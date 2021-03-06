/*-
 * Copyright (c) 2015 StopClock Developers (nine.gentooman@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

using Gtk;
using GLib;

namespace StopClock {
    class Window : Gtk.Window {
        
        public Window () {
            // window specifics
            this.title = "StopClock";
            this.set_position (Gtk.WindowPosition.CENTER);
            this.set_default_size (350, 500);
            this.destroy.connect (Gtk.main_quit);
            this.get_style_context ().add_class ("rounded");
            
            var headerbar = new Gtk.HeaderBar();
            this.set_titlebar (headerbar);
            headerbar.set_title ("StopClock");
            headerbar.set_show_close_button (true);
            headerbar.get_style_context ().remove_class ("header-bar");
            var settings = new Gtk.Button.from_icon_name ("application-menu-symbolic");
            headerbar.pack_end(settings);
            
            var layout = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);
            
            var view = new Gtk.Stack ();
            view.add_titled (
                new StopWatch.StopWatch(Gtk.Orientation.VERTICAL, 0),
                "stopwatch",
                "stopwatch"
            );
            view.add_titled (
                new EggTimer.EggTimer(Gtk.Orientation.VERTICAL, 0),
                "eggtimer",
                "eggtimer"
            );
            view.add_titled (
                new Alarm.Alarm(Gtk.Orientation.VERTICAL, 0),
                "alarm",
                "alarm"
            );
            view.add_titled (
                new WorldClock.WorldClock(Gtk.Orientation.VERTICAL, 0),
                "worldclock",
                "worldclock"
            );
            var selector = new Gtk.StackSwitcher ();
            selector.stack = view;
            selector.halign = Gtk.Align.CENTER;
            selector.set_border_width (12);
            
            layout.pack_start (selector, false, false, 0);
            layout.pack_end (view, true, true, 0);
            add (layout);
            
            show_all();
            Gtk.main ();
        }
        /*
        public static int main (string[] args) {
            
            
            var css_provider = new Gtk.CssProvider();
            string css_path = "/usr/local/share/stopclock/stopclock.css";
            try {
                css_provider.load_from_path (css_path);
            } catch (GLib.Error e) {
                warning("%s", e.message);
            }
            StyleContext.add_provider_for_screen(
                Gdk.Screen.get_default(),
                css_provider,
                Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION
            );
            
        }
        */
    }
}
