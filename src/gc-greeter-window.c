/* gc-window.c
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

#define G_LOG_DOMAIN "GCardsWindow"
#include "gc-greeter-window.h"

typedef struct
{
} GCardsGreeterWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GCardsGreeterWindow, gcards_greeter_window, GTK_TYPE_APPLICATION_WINDOW)

enum {
  PROP_0,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

static void
gcards_greeter_window_finalize (GObject *object)
{
  GCardsGreeterWindow *self = (GCardsGreeterWindow *)object;
  GCardsGreeterWindowPrivate *priv = gcards_greeter_window_get_instance_private (self);

  G_OBJECT_CLASS (gcards_greeter_window_parent_class)->finalize (object);
}

static void
gcards_greeter_window_get_property (GObject    *object,
                                    guint       prop_id,
                                    GValue     *value,
                                    GParamSpec *pspec)
{
  GCardsGreeterWindow *self = GCARDS_GREETER_WINDOW (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_greeter_window_set_property (GObject      *object,
                                    guint         prop_id,
                                    const GValue *value,
                                    GParamSpec   *pspec)
{
  GCardsGreeterWindow *self = GCARDS_GREETER_WINDOW (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_greeter_window_class_init (GCardsGreeterWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  object_class->finalize = gcards_greeter_window_finalize;
  object_class->get_property = gcards_greeter_window_get_property;
  object_class->set_property = gcards_greeter_window_set_property;

  gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/gcards/gcards-greeter-window.ui");
}

static void
gcards_greeter_window_init (GCardsGreeterWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET(self));
}

GtkWidget *
gcards_greeter_window_new (GApplication *app)
{
  GCardsGreeterWindow *win = NULL;

  win = g_object_new (GCARDS_TYPE_GREETER_WINDOW,
                      "application", app, NULL);

  return GTK_WIDGET (win);
} 
