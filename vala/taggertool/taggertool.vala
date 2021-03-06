//valac --pkg gtk+-3.0 --pkg granite taggertool.vala

enum OutPutMode {
    HASHTAG,
    COMMAS
}

//FIXME: passing a fucking window to a fucking copy method would make bob martin cry and shit himself
void copy ( string entry, OutPutMode mode, Gtk.Window window ) {
    var display = window.get_display ();
    var clipboard = Gtk.Clipboard.get_for_display (display, Gdk.SELECTION_CLIPBOARD);
    string output = "";
    switch (mode) {
        case OutPutMode.HASHTAG:
            var entry_split = entry.split ("\n");
            foreach ( var s in entry_split ) output += "#%s ".printf (s);
            break;
        
        case OutPutMode.COMMAS:
            var entry_split = entry.split ("\n");
            foreach ( var s in entry_split ) output += "%s, ".printf (s);
            break;
    }
    clipboard.set_text ( output, -1 );
    //stdout.printf ( "%s\n", output );
}

int main (string[] args) {
    Gtk.init (ref args);
    
    var window = new Gtk.Window();
    window.title = "TaggerTool";
    window.set_position (Gtk.WindowPosition.CENTER);
    window.set_default_size (350, 70);
    window.destroy.connect (Gtk.main_quit);
    window.get_style_context ().add_class ("Gtk.STYLE_CLASS_CSD");
    window.get_style_context ().add_class ("rounded");
    
    var layout = new Gtk.Box (Gtk.Orientation.VERTICAL, 6);
    
    Gtk.ScrolledWindow scrolled = new Gtk.ScrolledWindow (null, null);
    layout.pack_start (scrolled, true, true, 0);
    
    var text_view = new Gtk.TextView ();
    text_view.set_wrap_mode (Gtk.WrapMode.WORD);
    text_view.vexpand = true;
    text_view.left_margin = 12;
    text_view.top_margin = 6;
    scrolled.add (text_view);
    
    var mode = new Granite.Widgets.ModeButton ();
    mode.append_text ( "#hashtag" );
    mode.append_text ( "comma, separated" );
    mode.margin = 12;
    mode.margin_top = 6;
    mode.margin_bottom = 0;
    mode.set_active ( 0 );
    var output_mode = OutPutMode.HASHTAG;
    mode.mode_changed.connect ( ()=> {
        switch ( mode.selected ) {
            case 0:
                output_mode = OutPutMode.HASHTAG;
                break;
            case 1:
                output_mode = OutPutMode.COMMAS;
                break;
        }
    });
    layout.add (mode);
    
    var do_it = new Gtk.Button.with_label ("Copy to Clipboard");
    do_it.get_style_context ().add_class (Gtk.STYLE_CLASS_SUGGESTED_ACTION);
    do_it.margin = 12;
    do_it.margin_top = 6;
    do_it.clicked.connect ( ()=> { copy (text_view.buffer.text, output_mode, window); } );
    layout.add (do_it);
    
    window.add (layout);
    window.show_all ();
    Gtk.main ();
    return 0;
}
