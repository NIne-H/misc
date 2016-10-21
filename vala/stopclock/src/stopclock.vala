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

using Granite;
using Gtk;
using GLib;

namespace StopClock {
    class StopClockApp : Granite.Application {
        construct {
            program_name = "StopClock";
            exec_name = "stopclock";
            app_years = "2015";
            app_icon = "stopclock";
            app_launcher = "stopclock.desktop";
            
            about_authors = { "Aneurin Hall <aneurin.hall@gmail.com>" };           
        }
        
        public StopClockApp () {
            Granite.Services.Logger.initialize ("StopClockApp");
            Granite.Services.Logger.DisplayLevel = Granite.Services.LogLevel.DEBUG;
            new Window ();
        }

        
        public static int main (string [] args) {
            Gtk.init (ref args);
            var app = new StopClockApp ();
            return app.run (args);
        }
    }
}
