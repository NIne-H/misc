// hangman.vala
// valac --pkg gtk+-3.0 --pkg granite hangman_gtk.vala
// Nine GPL3+ 2016.02.07

using Gtk;

class Hangman : Object {
    private int guesses;
    private string word;
    private string guess_buffer;
    private string incorrect_guesses;
    private string board_state;
    private Entry input;
    private Label remaining;
    private Label board;
    private Label fails;
    public enum State {
        INGAME,
        WIN,
        LOSE
    }
    public State state;
    
    public Hangman ( Entry _input, Label _remaining, Label _board, Label _fails ) {
        this.input = _input;
        this.remaining = _remaining;
        this.board = _board;
        this.fails = _fails;
        reset ();
    }
    
    private string double_space ( string s ) {
        unichar c;
        string o = "";
        for ( int i = 0; s.get_next_char ( ref i, out c ); ) {
            o += " %s ".printf ( c.to_string () );
        }
        return o;
    }
    
    private string get_random_word () {
        string dictionary;
        string [] dict_split;
        try {
            FileUtils.get_contents ( "/usr/share/dict/words", out dictionary );
            dict_split = dictionary.split("\n");
            return dict_split[ Random.int_range ( 0, dict_split.length ) ].up ();
        } catch (FileError e) { 
            stderr.printf ("%s\n", e.message);
            return "";
        }

    }
    
    public void reset () {
        guesses = 10;
        incorrect_guesses = "";
        guess_buffer = "";
        board_state = "";
        word = get_random_word ();
        string hidden = "";
        unichar c; // annoying I need this, find better pattern.
        for ( int i = 0; word.get_next_char ( ref i, out c );) { // thanks Maciej Pietchotka
            hidden += "_";
        }
        board.set_text ( double_space ( hidden ) );
        remaining.set_text ("you have %i guesses remaining".printf ( guesses ) );
        fails.set_text ( "" );
    }
    
    public void make_guess () {
        unichar c;
        for ( int i = 0; input.get_text ().get_next_char ( ref i, out c); ) {
            if ( c.isalpha () ) {
                c = c.toupper ();
                guess_buffer += c.to_string ();
                if ( !incorrect_guesses.contains ( c.to_string () ) ) {
                    incorrect_guesses += c.to_string ();
                    fails.set_text ( double_space ( incorrect_guesses ) );
                }
                if ( word.contains ( c.to_string () ) ) {
                    string temp = "";
                    unichar d;
                    for ( int j = 0; word.get_next_char ( ref j, out d ); ) {
                        if ( guess_buffer.contains ( d.to_string () ) ) {
                            temp += "%s".printf ( d.to_string () );
                        } else {
                            temp += "_";
                        }
                    }
                    board.set_text ( double_space ( temp ) );
                } else {
                    guesses -=1;
                }
            }
        }
        input.set_text ("");
        remaining.set_text ("you have %i guesses remaining".printf ( guesses ) );
        if (  guesses <= 0 ) {        
            remaining.set_text ("oh oh! the word was:" );
            board.set_text ( double_space (word) );
        }
    }
}

int main ( string [] args ) {
    Gtk.init ( ref args );
    var window = new Gtk.Window ();
    window.set_title ( "Hangman" );
    window.destroy.connect ( Gtk.main_quit );
    
    //set up objects
    var remaining = new Gtk.Label ( "10 guesses remaining" );
    remaining.get_style_context().add_class ("h3");
    var board = new Gtk.Label ( "" );
    board.get_style_context().add_class ("h1");
    var input = new Gtk.Entry ();
    var fails = new Gtk.Label ( "" );
    var hangman = new Hangman ( input, remaining, board, fails );
    input.activate.connect ( hangman.make_guess );
    
    // layout code
    var layout = new Gtk.Box ( Gtk.Orientation.VERTICAL, 6 );
    layout.homogeneous = true;
    layout.add ( remaining );
    layout.add ( board );
    layout.add ( input );
    layout.add ( fails );
    window.add ( layout );
    window.show_all ();
    
    Gtk.main ();
    return 0;
}
