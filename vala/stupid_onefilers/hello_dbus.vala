//hello_dbus.vala
//Nine GPL3+ 2016.02.04
//valac --pkg gio-2.0 hello_dbus.vala
//does this in way too many lines:
//dbus-send --session \
//          --dest=org.pantheon.gala \
//          --print-reply /org/pantheon/gala \
//          org.pantheon.gala.PerformAction \
//          int32:1

//PerformAction
// 1 = desktop manager
// 2 = fullscreen
// 3 = minimize
// 4 = slingshot
// 5 = ???
// 6 = window overview
// 7 = window overview (all)

[DBus (name = "org.pantheon.gala")]
interface Gala : Object {
    public abstract int perform_action ( int32 i ) throws IOError;
}

int main ( string[] args ) {
    Gala gala = null;
    try {
        gala = Bus.get_proxy_sync ( BusType.SESSION,
                                    "org.pantheon.gala",
                                    "/org/pantheon/gala" );       
        int perform_action = gala.perform_action( 1 );
        stdout.printf ( "%i\n", perform_action );
    } catch ( IOError e ) {
        stderr.printf ( "%s\n", e.message );
    }
    return 0;
}
