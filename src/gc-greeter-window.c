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
#include "gc-window.h"

typedef struct
{
} GCardsWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GCardsWindow, gcards_window, GTK_TYPE_APPLICATION_WINDOW)

enum {
  PROP_0,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

static void
gcards_window_finalize (GObject *object)
{
  GCardsWindow *self = (GCardsWindow *)object;
  GCardsWindowPrivate *priv = gcards_window_get_instance_private (self);

  G_OBJECT_CLASS (gcards_window_parent_class)->finalize (object);
}

static void
gcards_window_get_property (GObject    *object,
                            guint       prop_id,
                            GValue     *value,
                            GParamSpec *pspec)
{
  GCardsWindow *self = GCARDS_WINDOW (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_window_set_property (GObject      *object,
                            guint         prop_id,
                            const GValue *value,
                            GParamSpec   *pspec)
{
  GCardsWindow *self = GCARDS_WINDOW (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_window_class_init (GCardsWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = gcards_window_finalize;
  object_class->get_property = gcards_window_get_property;
  object_class->set_property = gcards_window_set_property;
}

static void
gcards_window_init (GCardsWindow *self)
{
}

GtkWidget *
gcards_window_new (GApplication *app)
{
  GCardsWindow *win = NULL;

  win = g_object_new (GCARDS_TYPE_WINDOW,
                      "application", app, NULL);

  return GTK_WIDGET (win);
} 
