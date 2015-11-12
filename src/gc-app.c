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

#include "gc-app.h"

typedef struct
{

} GCardsAppPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (GCardsApp, gcards_app, GTK_TYPE_APPLICATION)

enum {
  PROP_0,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

static void
gcards_app_activate (GApplication *app)
{
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
