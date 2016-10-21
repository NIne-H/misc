//valac --pkg gtk+-3.0 --pkg posix shittalker.vala

using Posix;

void say ( string entry, string voice ) {
    string str = "spd-say " + voice + " \"" + entry + "\"";
    Posix.system ( str );
}

int main (string[] args) {
    Gtk.init (ref args);
    
    var window = new Gtk.Window();
    window.title = "ShitTalker";
    window.set_border_width (12);
    window.set_position (Gtk.WindowPosition.CENTER);
    window.set_default_size (350, 70);
    window.destroy.connect (Gtk.main_quit);
    window.get_style_context ().add_class ("Gtk.STYLE_CLASS_CSD");
    window.get_style_context ().add_class ("rounded");
    
    // list of voices
    string voice = "";
    
    var voices = new Gtk.ListStore ( 2, typeof (string), typeof (string) );
    Gtk.TreeIter iter;
    
    voices.append ( out iter );
    voices.set ( iter, 0, "male1", 1, "-t male1" );
    voices.append ( out iter );
    voices.set ( iter, 0, "male2", 1, "-t male2" );
    voices.append ( out iter );
    voices.set ( iter, 0, "male3", 1, "-t male3" );
    voices.append ( out iter );
    voices.set ( iter, 0, "female1", 1, "-t female1" );
    voices.append ( out iter );
    voices.set ( iter, 0, "female2", 1, "-t female2" );
    voices.append ( out iter );
    voices.set ( iter, 0, "female3", 1, "-t female3" );
    voices.append ( out iter );
    voices.set ( iter, 0, "child_male", 1, "-t child_male" );
    voices.append ( out iter );
    voices.set ( iter, 0, "child_female", 1, "-t child_female" );
    
    // combobox
    var voice_selector = new Gtk.ComboBox.with_model (voices);
    var renderer = new Gtk.CellRendererText ();
    voice_selector.pack_start (renderer, true);
    voice_selector.add_attribute (renderer, "text", 0);
    voice_selector.active = 0;
    
    voice_selector.changed.connect ( () => {
        Value val2;
        voice_selector.get_active_iter (out iter);
        voices.get_value (iter, 1, out val2);
        voice = (string) val2;
    });
   
    // end of box
    
    var image = new Gtk.Image.from_file ("/home/nine/Projects/misc/vala/shittalker/mrcomputer.svg");
    
    
    var entry_say = new Gtk.Entry ();
    entry_say.set_text("Enter some words to say");
    entry_say.activate.connect (() => {
        say ( entry_say.get_text (), voice );
    });
    
    var button_say = new Gtk.Button.with_label ("Say");
    button_say.get_style_context ().add_class (Gtk.STYLE_CLASS_SUGGESTED_ACTION);
    button_say.clicked.connect (() => {
        say ( entry_say.get_text (), voice );
    });
    
    var button_save = new Gtk.Button.with_label ("⚫ " + "Save");
    button_save.get_style_context ().add_class (Gtk.STYLE_CLASS_DESTRUCTIVE_ACTION);
    
    // add widgets and draw
    var buttons = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 6);
    buttons.get_style_context ().add_class ("secondary-toolbar");
    buttons.homogeneous = true;
    buttons.add (button_save);
    buttons.add (button_say);
    
    var layout = new Gtk.Box (Gtk.Orientation.VERTICAL, 6);
    layout.add (voice_selector);
    layout.add (image);
    layout.add (entry_say);
    layout.add (buttons);
    
    window.add (layout);
    window.show_all ();
    Gtk.main ();
    return 0;
}
