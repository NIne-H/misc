// very simple app based on the bacon ipsum api
// https://baconipsum.com/json-api/

int main (string[] args) {
    string url = "https://baconipsum.com/api/?";
    string type = "type=all-meat"; // all-meat, meat-and-filler
    string paras = "&paras=";
    //string sentences = 10;
    string start_with_lorem = "&start-with-lorem=1";
    string format = "&format=text"; //probs backend, can pass json text and html

    Gtk.init (ref args);
    
    var lorem_switch = new Gtk.Switch();
    
    var paras_spinner = new Gtk.SpinButton.with_range (1, 2048, 1);
    
    //var meatiness = new Gtk.
    
    var header = new Gtk.HeaderBar();
    header.pack_start (new Gtk.Label ("Start with Lorem:"));
    header.pack_start (lorem_switch);
    header.pack_end (paras_spinner);
    header.pack_end (new Gtk.Label ("Number of paragraphs:"));
    header.show_close_button = true;
    header.title = "Baconator";
        
    var label = new Gtk.Label ("");
    label.ellipsize = Pango.EllipsizeMode.END;   
    label.lines = 20;
    label.vexpand = true;
    label.wrap = true;
    
    var button = new Gtk.Button.with_label("Get some baconators");
    button.clicked.connect (() => {
        string query = url + type;
        if (lorem_switch.active)
            query += start_with_lorem;
        query += paras + paras_spinner.value.to_string();
        query += format;
        print (query);
        var session = new Soup.Session ();
        var message = new Soup.Message ("GET", query);
        session.send_message (message);
        label.label = (string) message.response_body.data;
    });
    button.hexpand = true;
    //button.set_style_context ();
    
    var layout = new Gtk.Grid ();
    layout.attach (button, 0, 0);
    layout.attach (label, 0, 1);
    layout.margin = 12;
    
    var window = new Gtk.Window();
    window.set_titlebar (header);
    window.destroy.connect (Gtk.main_quit);
    window.add (layout);
    window.show_all();
    
    Gtk.main ();
    
    return 0;
}
