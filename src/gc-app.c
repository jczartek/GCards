/* gc-app.c
 *
 * Copyright (C) 2015 kuba <kuba@linux.pl>
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

#define G_LOG_DOMAIN "GCardsApp"

#include <clutter-gtk/clutter-gtk.h>
#include "gc-app.h"
#include "gc-greeter-window.h"

static void gcards_app_new_window_cb (GSimpleAction *action,
                                      GVariant      *parameter,
                                      gpointer       data);

typedef struct
{
  gpointer padding[2];
} GCardsAppPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GCardsApp, gcards_app, GTK_TYPE_APPLICATION)

enum {
  PROP_0,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

static const GActionEntry app_actions[] =
{
    {"new-window", gcards_app_new_window_cb, NULL, NULL, NULL}
};

static void
gcards_app_activate_action_new_window (GCardsApp *app)
{
  g_return_if_fail (GCARDS_IS_APP (app));
  g_action_group_activate_action (G_ACTION_GROUP (app),
                                  "new-window", NULL);
}

static void
gcards_app_new_window_cb (GSimpleAction *action,
                          GVariant      *parameter,
                          gpointer       data)
{
  GCardsApp *self = GCARDS_APP (data);
  GtkWidget *win  = NULL;

  win = gcards_greeter_window_new (G_APPLICATION (self));
  gtk_application_add_window (GTK_APPLICATION (self),
                              GTK_WINDOW      (win));
  gtk_window_present (GTK_WINDOW (win));
}

static void
gcards_app_startup (GApplication *app)
{
  G_APPLICATION_CLASS (gcards_app_parent_class)->startup (app);

  if (gtk_clutter_init (NULL, NULL) != CLUTTER_INIT_SUCCESS)
    {
      g_critical ("Unable to initalize Clutter!!!");
      g_application_quit (app);
    }

  g_action_map_add_action_entries (G_ACTION_MAP(app),
                                   app_actions,
                                   G_N_ELEMENTS (app_actions),
                                   app);
}

static void
gcards_app_activate (GApplication *app)
{
  gcards_app_activate_action_new_window (GCARDS_APP (app));
}

static void
gcards_app_finalize (GObject *object)
{
  GCardsApp *self = (GCardsApp *)object;
  GCardsAppPrivate *priv = gcards_app_get_instance_private (self);

  G_OBJECT_CLASS (gcards_app_parent_class)->finalize (object);
}

static void
gcards_app_get_property (GObject    *object,
                         guint       prop_id,
                         GValue     *value,
                         GParamSpec *pspec)
{
  GCardsApp *self = GCARDS_APP (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_app_set_property (GObject      *object,
                         guint         prop_id,
                         const GValue *value,
                         GParamSpec   *pspec)
{
  GCardsApp *self = GCARDS_APP (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_app_class_init (GCardsAppClass *klass)
{
  GApplicationClass *application_class = G_APPLICATION_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  application_class->activate = gcards_app_activate;
  application_class->startup = gcards_app_startup;

  object_class->finalize = gcards_app_finalize;
  object_class->get_property = gcards_app_get_property;
  object_class->set_property = gcards_app_set_property;
}

static void
gcards_app_init (GCardsApp *self)
{
}

GCardsApp *
gcards_app_new (void)
{
  return g_object_new (GCARDS_TYPE_APP,
                       "application-id", "org.gnome.gcards",
                       "flags",           G_APPLICATION_FLAGS_NONE,
                       NULL);
}
