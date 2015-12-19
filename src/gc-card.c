/* gc-card.c
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
#include "gc-card.h"

struct _GCardsCard
{
  ClutterActor parent;
};

G_DEFINE_TYPE (GCardsCard, gcards_card, CLUTTER_TYPE_ACTOR)

enum {
  PROP_0,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

ClutterActor *
gcards_card_new (void)
{
  return CLUTTER_ACTOR (g_object_new (GCARDS_TYPE_CARD, NULL));
}

static void
gcards_card_finalize (GObject *object)
{
  GCardsCard *self = GCARDS_CARD (object);

  G_OBJECT_CLASS (gcards_card_parent_class)->finalize (object);
}

static void
gcards_card_get_property (GObject    *object,
                          guint       prop_id,
                          GValue     *value,
                          GParamSpec *pspec)
{
  GCardsCard *self = GCARDS_CARD (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_card_set_property (GObject      *object,
                          guint         prop_id,
                          const GValue *value,
                          GParamSpec   *pspec)
{
  GCardsCard *self = GCARDS_CARD (object);

  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_card_constructed (GObject *object)
{
  GCardsCard *self = GCARDS_CARD (object);

  G_OBJECT_CLASS (gcards_card_parent_class)->constructed (object);

  clutter_actor_set_background_color (CLUTTER_ACTOR (self),
                                      CLUTTER_COLOR_White );
}

static void
gcards_card_class_init (GCardsCardClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = gcards_card_finalize;
  object_class->get_property = gcards_card_get_property;
  object_class->set_property = gcards_card_set_property;
}

static void
gcards_card_init (GCardsCard *self)
{
}
