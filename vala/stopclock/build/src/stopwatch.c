/* stopwatch.c generated by valac 0.34.4, the Vala compiler
 * generated from stopwatch.vala, do not modify */

/*
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

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH (stop_clock_stop_watch_stop_watch_get_type ())
#define STOP_CLOCK_STOP_WATCH_STOP_WATCH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH, StopClockStopWatchStopWatch))
#define STOP_CLOCK_STOP_WATCH_STOP_WATCH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH, StopClockStopWatchStopWatchClass))
#define STOP_CLOCK_STOP_WATCH_IS_STOP_WATCH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH))
#define STOP_CLOCK_STOP_WATCH_IS_STOP_WATCH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH))
#define STOP_CLOCK_STOP_WATCH_STOP_WATCH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH, StopClockStopWatchStopWatchClass))

typedef struct _StopClockStopWatchStopWatch StopClockStopWatchStopWatch;
typedef struct _StopClockStopWatchStopWatchClass StopClockStopWatchStopWatchClass;
typedef struct _StopClockStopWatchStopWatchPrivate StopClockStopWatchStopWatchPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_timer_destroy0(var) ((var == NULL) ? NULL : (var = (g_timer_destroy (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _StopClockStopWatchStopWatch {
	GtkBox parent_instance;
	StopClockStopWatchStopWatchPrivate * priv;
};

struct _StopClockStopWatchStopWatchClass {
	GtkBoxClass parent_class;
};

struct _StopClockStopWatchStopWatchPrivate {
	GtkLabel* readout;
	GtkLabel* miliseconds;
	GtkTreeView* laps;
	GtkButton* button_startstop;
	GTimer* timer;
	gboolean cleared;
	GtkListStore* laplist;
	GtkTreeIter iter;
};


static gpointer stop_clock_stop_watch_stop_watch_parent_class = NULL;

GType stop_clock_stop_watch_stop_watch_get_type (void) G_GNUC_CONST;
#define STOP_CLOCK_STOP_WATCH_STOP_WATCH_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH, StopClockStopWatchStopWatchPrivate))
enum  {
	STOP_CLOCK_STOP_WATCH_STOP_WATCH_DUMMY_PROPERTY
};
StopClockStopWatchStopWatch* stop_clock_stop_watch_stop_watch_new (GtkOrientation orientation, gint spacing);
StopClockStopWatchStopWatch* stop_clock_stop_watch_stop_watch_construct (GType object_type, GtkOrientation orientation, gint spacing);
static void stop_clock_stop_watch_stop_watch_start_stop (StopClockStopWatchStopWatch* self, GtkButton* btn);
static void _stop_clock_stop_watch_stop_watch_start_stop_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void stop_clock_stop_watch_stop_watch_lap (StopClockStopWatchStopWatch* self);
static void _stop_clock_stop_watch_stop_watch_lap_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void stop_clock_stop_watch_stop_watch_clear (StopClockStopWatchStopWatch* self);
static void _stop_clock_stop_watch_stop_watch_clear_gtk_button_clicked (GtkButton* _sender, gpointer self);
static gboolean stop_clock_stop_watch_stop_watch_update (StopClockStopWatchStopWatch* self);
static gboolean _stop_clock_stop_watch_stop_watch_update_gsource_func (gpointer self);
void stop_clock_utils_time_to_hms (gdouble t, gint* h, gint* m, gint* s, gint* ms);
static void stop_clock_stop_watch_stop_watch_finalize (GObject* obj);


static void _stop_clock_stop_watch_stop_watch_start_stop_gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 60 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_stop_watch_stop_watch_start_stop ((StopClockStopWatchStopWatch*) self, _sender);
#line 90 "stopwatch.c"
}


static void _stop_clock_stop_watch_stop_watch_lap_gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 63 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_stop_watch_stop_watch_lap ((StopClockStopWatchStopWatch*) self);
#line 97 "stopwatch.c"
}


static void _stop_clock_stop_watch_stop_watch_clear_gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 67 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_stop_watch_stop_watch_clear ((StopClockStopWatchStopWatch*) self);
#line 104 "stopwatch.c"
}


static gboolean _stop_clock_stop_watch_stop_watch_update_gsource_func (gpointer self) {
	gboolean result;
	result = stop_clock_stop_watch_stop_watch_update ((StopClockStopWatchStopWatch*) self);
#line 81 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	return result;
#line 113 "stopwatch.c"
}


StopClockStopWatchStopWatch* stop_clock_stop_watch_stop_watch_construct (GType object_type, GtkOrientation orientation, gint spacing) {
	StopClockStopWatchStopWatch * self = NULL;
	GtkOrientation _tmp0_ = 0;
	gint _tmp1_ = 0;
	GtkBox* controls = NULL;
	GtkBox* _tmp2_ = NULL;
	GtkBox* readout_box = NULL;
	GtkBox* _tmp3_ = NULL;
	GtkLabel* _tmp4_ = NULL;
	GtkLabel* _tmp5_ = NULL;
	GtkStyleContext* _tmp6_ = NULL;
	GtkLabel* _tmp7_ = NULL;
	GtkLabel* _tmp8_ = NULL;
	GtkStyleContext* _tmp9_ = NULL;
	GTimer* _tmp10_ = NULL;
	GtkListStore* _tmp11_ = NULL;
	GtkListStore* _tmp12_ = NULL;
	GtkTreeView* _tmp13_ = NULL;
	GtkCellRendererText* cell = NULL;
	GtkCellRendererText* _tmp14_ = NULL;
	GtkTreeView* _tmp15_ = NULL;
	GtkTreeView* _tmp16_ = NULL;
	GtkButton* _tmp17_ = NULL;
	GtkButton* _tmp18_ = NULL;
	GtkStyleContext* _tmp19_ = NULL;
	GtkButton* _tmp20_ = NULL;
	GtkButton* button_lap = NULL;
	GtkButton* _tmp21_ = NULL;
	GtkButton* button_reset = NULL;
	GtkButton* _tmp22_ = NULL;
	GtkStyleContext* _tmp23_ = NULL;
	GtkLabel* _tmp24_ = NULL;
	GtkLabel* _tmp25_ = NULL;
	GtkButton* _tmp26_ = NULL;
	GtkTreeView* _tmp27_ = NULL;
#line 35 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp0_ = orientation;
#line 35 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp1_ = spacing;
#line 35 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self = (StopClockStopWatchStopWatch*) g_object_new (object_type, "orientation", _tmp0_, "spacing", _tmp1_, NULL);
#line 37 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp2_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 12);
#line 37 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp2_);
#line 37 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	controls = _tmp2_;
#line 38 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_container_set_border_width ((GtkContainer*) controls, (guint) 12);
#line 40 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp3_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 2);
#line 40 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp3_);
#line 40 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	readout_box = _tmp3_;
#line 41 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_widget_set_halign ((GtkWidget*) readout_box, GTK_ALIGN_CENTER);
#line 43 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp4_ = (GtkLabel*) gtk_label_new ("");
#line 43 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp4_);
#line 43 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->readout);
#line 43 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->readout = _tmp4_;
#line 44 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp5_ = self->priv->readout;
#line 44 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp6_ = gtk_widget_get_style_context ((GtkWidget*) _tmp5_);
#line 44 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_style_context_add_class (_tmp6_, "h1");
#line 45 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp7_ = (GtkLabel*) gtk_label_new ("");
#line 45 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp7_);
#line 45 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->miliseconds);
#line 45 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->miliseconds = _tmp7_;
#line 46 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp8_ = self->priv->miliseconds;
#line 46 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp9_ = gtk_widget_get_style_context ((GtkWidget*) _tmp8_);
#line 46 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_style_context_add_class (_tmp9_, "h2");
#line 48 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp10_ = g_timer_new ();
#line 48 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_timer_destroy0 (self->priv->timer);
#line 48 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->timer = _tmp10_;
#line 50 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp11_ = gtk_list_store_new (2, G_TYPE_STRING, G_TYPE_STRING, -1);
#line 50 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->laplist);
#line 50 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->laplist = _tmp11_;
#line 52 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp12_ = self->priv->laplist;
#line 52 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp13_ = (GtkTreeView*) gtk_tree_view_new_with_model ((GtkTreeModel*) _tmp12_);
#line 52 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp13_);
#line 52 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->laps);
#line 52 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->laps = _tmp13_;
#line 53 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp14_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
#line 53 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp14_);
#line 53 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	cell = _tmp14_;
#line 54 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp15_ = self->priv->laps;
#line 54 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_tree_view_insert_column_with_attributes (_tmp15_, -1, "Lap", (GtkCellRenderer*) cell, "text", 0, NULL);
#line 55 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp16_ = self->priv->laps;
#line 55 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_tree_view_insert_column_with_attributes (_tmp16_, -1, "Time", (GtkCellRenderer*) cell, "text", 0, NULL);
#line 58 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp17_ = (GtkButton*) gtk_button_new_with_label ("Start");
#line 58 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp17_);
#line 58 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->button_startstop);
#line 58 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->button_startstop = _tmp17_;
#line 59 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp18_ = self->priv->button_startstop;
#line 59 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp19_ = gtk_widget_get_style_context ((GtkWidget*) _tmp18_);
#line 59 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_style_context_add_class (_tmp19_, GTK_STYLE_CLASS_SUGGESTED_ACTION);
#line 60 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp20_ = self->priv->button_startstop;
#line 60 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_signal_connect_object (_tmp20_, "clicked", (GCallback) _stop_clock_stop_watch_stop_watch_start_stop_gtk_button_clicked, self, 0);
#line 62 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp21_ = (GtkButton*) gtk_button_new_with_label ("Lap");
#line 62 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp21_);
#line 62 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	button_lap = _tmp21_;
#line 63 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_signal_connect_object (button_lap, "clicked", (GCallback) _stop_clock_stop_watch_stop_watch_lap_gtk_button_clicked, self, 0);
#line 65 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp22_ = (GtkButton*) gtk_button_new_with_label ("Reset");
#line 65 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_object_ref_sink (_tmp22_);
#line 65 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	button_reset = _tmp22_;
#line 66 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp23_ = gtk_widget_get_style_context ((GtkWidget*) button_reset);
#line 66 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_style_context_add_class (_tmp23_, GTK_STYLE_CLASS_DESTRUCTIVE_ACTION);
#line 67 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_signal_connect_object (button_reset, "clicked", (GCallback) _stop_clock_stop_watch_stop_watch_clear_gtk_button_clicked, self, 0);
#line 69 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp24_ = self->priv->readout;
#line 69 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_container_add ((GtkContainer*) readout_box, (GtkWidget*) _tmp24_);
#line 70 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp25_ = self->priv->miliseconds;
#line 70 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_container_add ((GtkContainer*) readout_box, (GtkWidget*) _tmp25_);
#line 71 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_pack_start (controls, (GtkWidget*) button_lap, TRUE, TRUE, (guint) 0);
#line 72 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_pack_start (controls, (GtkWidget*) button_reset, TRUE, TRUE, (guint) 0);
#line 73 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp26_ = self->priv->button_startstop;
#line 73 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_pack_end (controls, (GtkWidget*) _tmp26_, TRUE, TRUE, (guint) 0);
#line 74 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_set_homogeneous (controls, TRUE);
#line 75 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) readout_box, FALSE, FALSE, (guint) 0);
#line 76 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp27_ = self->priv->laps;
#line 76 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) _tmp27_, TRUE, TRUE, (guint) 0);
#line 77 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_box_pack_end ((GtkBox*) self, (GtkWidget*) controls, FALSE, FALSE, (guint) 0);
#line 79 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_stop_watch_stop_watch_update (self);
#line 80 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_stop_watch_stop_watch_clear (self);
#line 81 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 10, _stop_clock_stop_watch_stop_watch_update_gsource_func, g_object_ref (self), g_object_unref);
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (button_reset);
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (button_lap);
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (cell);
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (readout_box);
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (controls);
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	return self;
#line 320 "stopwatch.c"
}


StopClockStopWatchStopWatch* stop_clock_stop_watch_stop_watch_new (GtkOrientation orientation, gint spacing) {
#line 34 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	return stop_clock_stop_watch_stop_watch_construct (STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH, orientation, spacing);
#line 327 "stopwatch.c"
}


static void stop_clock_stop_watch_stop_watch_start_stop (StopClockStopWatchStopWatch* self, GtkButton* btn) {
	GtkButton* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
#line 85 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_return_if_fail (self != NULL);
#line 85 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_return_if_fail (btn != NULL);
#line 86 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp0_ = btn;
#line 86 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp1_ = gtk_button_get_label (_tmp0_);
#line 86 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	if (g_strcmp0 (_tmp1_, "Start") == 0) {
#line 344 "stopwatch.c"
		gboolean _tmp2_ = FALSE;
		GtkButton* _tmp5_ = NULL;
#line 87 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp2_ = self->priv->cleared;
#line 87 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		if (_tmp2_ == TRUE) {
#line 351 "stopwatch.c"
			GTimer* _tmp3_ = NULL;
#line 88 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
			_tmp3_ = self->priv->timer;
#line 88 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
			g_timer_start (_tmp3_);
#line 89 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
			self->priv->cleared = FALSE;
#line 359 "stopwatch.c"
		} else {
			GTimer* _tmp4_ = NULL;
#line 91 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
			_tmp4_ = self->priv->timer;
#line 91 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
			g_timer_continue (_tmp4_);
#line 366 "stopwatch.c"
		}
#line 93 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp5_ = btn;
#line 93 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		gtk_button_set_label (_tmp5_, "Pause");
#line 372 "stopwatch.c"
	} else {
		GTimer* _tmp6_ = NULL;
		GtkButton* _tmp7_ = NULL;
#line 95 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp6_ = self->priv->timer;
#line 95 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		g_timer_stop (_tmp6_);
#line 96 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp7_ = btn;
#line 96 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		gtk_button_set_label (_tmp7_, "Start");
#line 384 "stopwatch.c"
	}
}


static void stop_clock_stop_watch_stop_watch_clear (StopClockStopWatchStopWatch* self) {
	GtkButton* _tmp0_ = NULL;
	GTimer* _tmp1_ = NULL;
	GTimer* _tmp2_ = NULL;
	GtkListStore* _tmp3_ = NULL;
	GtkLabel* _tmp4_ = NULL;
#line 100 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_return_if_fail (self != NULL);
#line 101 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp0_ = self->priv->button_startstop;
#line 101 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_button_set_label (_tmp0_, "Start");
#line 102 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp1_ = self->priv->timer;
#line 102 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_timer_reset (_tmp1_);
#line 103 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp2_ = self->priv->timer;
#line 103 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_timer_stop (_tmp2_);
#line 104 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp3_ = self->priv->laplist;
#line 104 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_list_store_clear (_tmp3_);
#line 105 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->cleared = TRUE;
#line 106 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp4_ = self->priv->readout;
#line 106 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_label_set_label (_tmp4_, "0.00");
#line 419 "stopwatch.c"
}


static void stop_clock_stop_watch_stop_watch_lap (StopClockStopWatchStopWatch* self) {
	gint h = 0;
	gint m = 0;
	gint s = 0;
	gint ms = 0;
	GTimer* _tmp0_ = NULL;
	gdouble _tmp1_ = 0.0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	gchar* elapsed = NULL;
	gchar* _tmp6_ = NULL;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	gint _tmp12_ = 0;
	gchar* _tmp13_ = NULL;
	gchar* _tmp14_ = NULL;
	gchar* _tmp15_ = NULL;
	gchar* _tmp16_ = NULL;
	GtkListStore* _tmp17_ = NULL;
	GtkTreeIter _tmp18_ = {0};
	GtkListStore* _tmp19_ = NULL;
	GtkTreeIter _tmp20_ = {0};
#line 109 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_return_if_fail (self != NULL);
#line 110 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	ms = 0;
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp0_ = self->priv->timer;
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp1_ = g_timer_elapsed (_tmp0_, NULL);
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_utils_time_to_hms (_tmp1_, &_tmp2_, &_tmp3_, &_tmp4_, &_tmp5_);
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	h = _tmp2_;
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	m = _tmp3_;
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	s = _tmp4_;
#line 111 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	ms = _tmp5_;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp6_ = g_strdup_printf ("%i", h);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp7_ = _tmp6_;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp8_ = g_strdup_printf ("%i", m);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp9_ = _tmp8_;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp10_ = g_strdup_printf ("%i", s);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp11_ = _tmp10_;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp12_ = ms;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp13_ = g_strdup_printf ("%i", _tmp12_);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp14_ = _tmp13_;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp15_ = g_strconcat (_tmp7_, ":", _tmp9_, ":", _tmp11_, ".", _tmp14_, NULL);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp16_ = _tmp15_;
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_free0 (_tmp14_);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_free0 (_tmp11_);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_free0 (_tmp9_);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_free0 (_tmp7_);
#line 112 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	elapsed = _tmp16_;
#line 113 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp17_ = self->priv->laplist;
#line 113 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_list_store_append (_tmp17_, &_tmp18_);
#line 113 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv->iter = _tmp18_;
#line 114 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp19_ = self->priv->laplist;
#line 114 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp20_ = self->priv->iter;
#line 114 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_list_store_set (_tmp19_, &_tmp20_, 0, elapsed, 1, elapsed, -1);
#line 109 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_free0 (elapsed);
#line 514 "stopwatch.c"
}


static gboolean stop_clock_stop_watch_stop_watch_update (StopClockStopWatchStopWatch* self) {
	gboolean result = FALSE;
	gint h = 0;
	gint m = 0;
	gint s = 0;
	gint ms = 0;
	GTimer* _tmp0_ = NULL;
	gdouble _tmp1_ = 0.0;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	gint _tmp5_ = 0;
	gint _tmp6_ = 0;
	GtkLabel* _tmp27_ = NULL;
	gint _tmp28_ = 0;
	gchar* _tmp29_ = NULL;
	gchar* _tmp30_ = NULL;
#line 117 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 118 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	ms = 0;
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp0_ = self->priv->timer;
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp1_ = g_timer_elapsed (_tmp0_, NULL);
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_utils_time_to_hms (_tmp1_, &_tmp2_, &_tmp3_, &_tmp4_, &_tmp5_);
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	h = _tmp2_;
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	m = _tmp3_;
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	s = _tmp4_;
#line 119 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	ms = _tmp5_;
#line 120 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp6_ = h;
#line 120 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	if (_tmp6_ != 0) {
#line 557 "stopwatch.c"
		GtkLabel* _tmp7_ = NULL;
		gint _tmp8_ = 0;
		gchar* _tmp9_ = NULL;
		gchar* _tmp10_ = NULL;
		gint _tmp11_ = 0;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gint _tmp14_ = 0;
		gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		gint _tmp17_ = 0;
		gchar* _tmp18_ = NULL;
		gchar* _tmp19_ = NULL;
		gchar* _tmp20_ = NULL;
		gchar* _tmp21_ = NULL;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp7_ = self->priv->readout;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp8_ = h;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp9_ = g_strdup_printf ("%i", _tmp8_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp10_ = _tmp9_;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp11_ = m;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp12_ = g_strdup_printf ("%i", _tmp11_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp13_ = _tmp12_;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp14_ = s;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp15_ = g_strdup_printf ("%i", _tmp14_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp16_ = _tmp15_;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp17_ = ms;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp18_ = g_strdup_printf ("%i", _tmp17_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp19_ = _tmp18_;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp20_ = g_strconcat (_tmp10_, ":", _tmp13_, ":", _tmp16_, ".", _tmp19_, NULL);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp21_ = _tmp20_;
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		gtk_label_set_label (_tmp7_, _tmp21_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_g_free0 (_tmp21_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_g_free0 (_tmp19_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_g_free0 (_tmp16_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_g_free0 (_tmp13_);
#line 121 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_g_free0 (_tmp10_);
#line 615 "stopwatch.c"
	} else {
		GtkLabel* _tmp22_ = NULL;
		gint _tmp23_ = 0;
		gint _tmp24_ = 0;
		gchar* _tmp25_ = NULL;
		gchar* _tmp26_ = NULL;
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp22_ = self->priv->readout;
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp23_ = m;
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp24_ = s;
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp25_ = g_strdup_printf ("%i∶%02i", _tmp23_, _tmp24_);
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_tmp26_ = _tmp25_;
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		gtk_label_set_label (_tmp22_, _tmp26_);
#line 123 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
		_g_free0 (_tmp26_);
#line 636 "stopwatch.c"
	}
#line 124 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp27_ = self->priv->miliseconds;
#line 124 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp28_ = ms;
#line 124 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp29_ = g_strdup_printf (".%02i", _tmp28_);
#line 124 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_tmp30_ = _tmp29_;
#line 124 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	gtk_label_set_label (_tmp27_, _tmp30_);
#line 124 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_free0 (_tmp30_);
#line 125 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	result = TRUE;
#line 125 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	return result;
#line 654 "stopwatch.c"
}


static void stop_clock_stop_watch_stop_watch_class_init (StopClockStopWatchStopWatchClass * klass) {
#line 23 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	stop_clock_stop_watch_stop_watch_parent_class = g_type_class_peek_parent (klass);
#line 23 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	g_type_class_add_private (klass, sizeof (StopClockStopWatchStopWatchPrivate));
#line 23 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	G_OBJECT_CLASS (klass)->finalize = stop_clock_stop_watch_stop_watch_finalize;
#line 665 "stopwatch.c"
}


static void stop_clock_stop_watch_stop_watch_instance_init (StopClockStopWatchStopWatch * self) {
#line 23 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self->priv = STOP_CLOCK_STOP_WATCH_STOP_WATCH_GET_PRIVATE (self);
#line 672 "stopwatch.c"
}


static void stop_clock_stop_watch_stop_watch_finalize (GObject* obj) {
	StopClockStopWatchStopWatch * self;
#line 23 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, STOP_CLOCK_STOP_WATCH_TYPE_STOP_WATCH, StopClockStopWatchStopWatch);
#line 25 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->readout);
#line 26 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->miliseconds);
#line 27 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->laps);
#line 28 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->button_startstop);
#line 29 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_timer_destroy0 (self->priv->timer);
#line 31 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	_g_object_unref0 (self->priv->laplist);
#line 23 "/home/nine/Projects/misc/vala/stopclock/src/stopwatch.vala"
	G_OBJECT_CLASS (stop_clock_stop_watch_stop_watch_parent_class)->finalize (obj);
#line 694 "stopwatch.c"
}


GType stop_clock_stop_watch_stop_watch_get_type (void) {
	static volatile gsize stop_clock_stop_watch_stop_watch_type_id__volatile = 0;
	if (g_once_init_enter (&stop_clock_stop_watch_stop_watch_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (StopClockStopWatchStopWatchClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) stop_clock_stop_watch_stop_watch_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (StopClockStopWatchStopWatch), 0, (GInstanceInitFunc) stop_clock_stop_watch_stop_watch_instance_init, NULL };
		GType stop_clock_stop_watch_stop_watch_type_id;
		stop_clock_stop_watch_stop_watch_type_id = g_type_register_static (gtk_box_get_type (), "StopClockStopWatchStopWatch", &g_define_type_info, 0);
		g_once_init_leave (&stop_clock_stop_watch_stop_watch_type_id__volatile, stop_clock_stop_watch_stop_watch_type_id);
	}
	return stop_clock_stop_watch_stop_watch_type_id__volatile;
}



