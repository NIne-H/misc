// markdown preview and print
// Nine GPL3+
// requires libmarkdown2-dev and libwebkit2gtk-3.0-dev
// valac --pkg gtk+-3.0 --pkg webkit2gtk-4.0 --pkg libmarkdown markdown_preview_and_print.vala 
// will not compile in freya without manually installing libmarkdown.vapi

using Gtk;

int main ( string [] args ) {
    Gtk.init ( ref args );
    var window = new Gtk.Window ();
    window.set_title ( "MarkDown" );
    window.destroy.connect ( Gtk.main_quit );
    
    // all the shit that's shit to shit.
    var file = FileStream.open ( "~/Documents/RESUME.md", "r" );
    assert ( file != null );
    var doc = new Markdown.Document.from_in ( file, Markdown.DocumentFlags.SAFELINK );
    var page = doc.generatehtml ( file );
    var view = new WebKit.WebView ();
    
    window.add ( view );
    // shit ends other shit begins.
    
    window.show_all ();
    Gtk.main ();
    return 0;
}
