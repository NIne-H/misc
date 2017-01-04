// annotate.vala
// stupid little hack to display text onscreen
// broken
// 4.1.2017
// valac --pkg gtk+-3.0 annotate.vala

using Gtk;

int main ( string [] args ) {
    Gtk.init ( ref args );
    var window = new Gtk.Window ();
    window.set_decorated ( false );
    window.destroy.connect ( Gtk.main_quit );
    
    string text = args[1];
    //if (args.length () > 1) {
        //add all the rest of the args :D
    //}
    var label = new Gtk.Label ( text );
    label.get_style_context().add_class ("h1");
    label.margin = 12;
    
    window.add ( label );
    window.show_all ();
    
    Timeout.add ( 4500, () => {
        window.close ();
        return false;
    } );
    Gtk.main ();
    return 0;
}
