/* gc-session-window.c
 *
 * Copyright (C) 2015 Jakub Czartek <kuba@linux.pl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <clutter-gtk/clutter-gtk.h>
#include "gc-session-window.h"

struct _GCardsSessionWindow
{
  GtkApplicationWindow parent;

  GtkClutterEmbed *clutter_embed;
  ClutterActor    *stage;
  GtkActionBar    *action_bar;
};

G_DEFINE_TYPE (GCardsSessionWindow, gcards_session_window, GTK_TYPE_APPLICATION_WINDOW)

enum {
  PROP_0,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

static void
gcards_session_window_finalize (GObject *object)
{
  GCardsSessionWindow *self = (GCardsSessionWindow *)object;

  G_OBJECT_CLASS (gcards_session_window_parent_class)->finalize (object);
}

static void
gcards_session_window_get_property (GObject    *object,
                                    guint       prop_id,
                                    GValue     *value,
                                    GParamSpec *pspec)
{
  GCardsSessionWindow *self = GCARDS_SESSION_WINDOW (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_session_window_set_property (GObject      *object,
                                    guint         prop_id,
                                    const GValue *value,
                                    GParamSpec   *pspec)
{
  GCardsSessionWindow *self = GCARDS_SESSION_WINDOW (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_session_window_constructed (GObject *object)
{
  GCardsSessionWindow *self = GCARDS_SESSION_WINDOW (object);
  ClutterColor color = CLUTTER_COLOR_INIT (0,0,0,255);

  G_OBJECT_CLASS (gcards_session_window_parent_class)->constructed (object);

  self->stage = gtk_clutter_embed_get_stage (self->clutter_embed);
  clutter_actor_set_background_color (self->stage, &color);


}

static void
gcards_session_window_class_init (GCardsSessionWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  object_class->constructed = gcards_session_window_constructed;
  object_class->finalize = gcards_session_window_finalize;
  object_class->get_property = gcards_session_window_get_property;
  object_class->set_property = gcards_session_window_set_property;

  gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/gcards/gcards-session-window.ui");
  gtk_widget_class_bind_template_child (widget_class, GCardsSessionWindow, clutter_embed);
  gtk_widget_class_bind_template_child (widget_class, GCardsSessionWindow, action_bar);
}

static void
gcards_session_window_init (GCardsSessionWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
