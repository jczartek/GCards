/* gc-scrolled-window.c
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

#include "gc-scrolled-window.h"

struct _GCardsScrolledWindow
{
  GtkScrolledWindow  parent;

  gint max_content_height;
  gint max_content_width;
};

G_DEFINE_TYPE (GCardsScrolledWindow, gcards_scrolled_window, GTK_TYPE_SCROLLED_WINDOW)

enum {
  PROP_0,
  PROP_MAX_CONTENT_HEIGHT,
  PROP_MAX_CONTENT_WIDTH,
  LAST_PROP
};

static GParamSpec *gParamSpecs [LAST_PROP];

static void
gcards_scrolled_window_get_preferred_height (GtkWidget *widget,
                                             gint      *minium_height,
                                             gint      *natural_height)
{
  GCardsScrolledWindow *self = GCARDS_SCROLLED_WINDOW (widget);

  GTK_WIDGET_CLASS (gcards_scrolled_window_parent_class)->get_preferred_height (widget,
                                                                                minium_height,
                                                                                natural_height);
  if (natural_height)
    {
      if (self->max_content_height > -1)
        {
          GtkWidget *child;
          GtkStyleContext *style;
          GtkBorder border;
          gint child_min_height;
          gint child_nat_height;
          gint additional;

          if (!(child = gtk_bin_get_child (GTK_BIN (widget))))
            return;

          style = gtk_widget_get_style_context (widget);
          gtk_style_context_get_border (style, gtk_widget_get_state_flags (widget), &border);
          additional = border.top + border.bottom;

          gtk_widget_get_preferred_height (child, &child_min_height, &child_nat_height);
          if ((child_nat_height > *natural_height) && (self->max_content_height > *natural_height))
            *natural_height = MIN (self->max_content_height, child_nat_height) + additional;
        }
    }
}

static void
gcards_scrolled_window_get_preferred_width (GtkWidget *widget,
                                            gint      *minium_width,
                                            gint      *natural_width)
{
  GCardsScrolledWindow *self = GCARDS_SCROLLED_WINDOW (widget);

  GTK_WIDGET_CLASS (gcards_scrolled_window_parent_class)->get_preferred_width (widget,
                                                                               minium_width,
                                                                               natural_width);

  if (natural_width && (self->max_content_width > -1))
    {
      GtkWidget *child;
      GtkStyleContext *style;
      GtkBorder border;
      gint child_min_width;
      gint child_nat_width;
      gint addition;

      if (!(child = gtk_bin_get_child (GTK_BIN (widget))))
        return;

      style = gtk_widget_get_style_context (widget);
      gtk_style_context_get_border (style, gtk_widget_get_state_flags (widget), &border);
      addition = border.right + border.left + 1;

      gtk_widget_get_preferred_width (child, &child_min_width, &child_nat_width);

      if ((child_nat_width > *natural_width) && (self->max_content_width > *natural_width))
        *natural_width = MIN (self->max_content_width, child_nat_width) + addition;
    }
}

static void
gcards_scrolled_window_finalize (GObject *object)
{
  GCardsScrolledWindow *self = (GCardsScrolledWindow *)object;

  G_OBJECT_CLASS (gcards_scrolled_window_parent_class)->finalize (object);
}

static void
gcards_scrolled_window_get_property (GObject    *object,
                                     guint       prop_id,
                                     GValue     *value,
                                     GParamSpec *pspec)
{
  GCardsScrolledWindow *self = GCARDS_SCROLLED_WINDOW (object);

  switch (prop_id)
    {
    case PROP_MAX_CONTENT_HEIGHT:
      g_value_set_int (value, gcards_scrolled_window_get_max_content_height (self));
      break;
    case PROP_MAX_CONTENT_WIDTH:
      g_value_set_int (value, gcards_scrolled_window_get_max_content_width (self));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_scrolled_window_set_property (GObject      *object,
                                     guint         prop_id,
                                     const GValue *value,
                                     GParamSpec   *pspec)
{
  GCardsScrolledWindow *self = GCARDS_SCROLLED_WINDOW (object);

  switch (prop_id)
    {
    case PROP_MAX_CONTENT_HEIGHT:
      gcards_scrolled_window_set_max_content_height (self, g_value_get_int (value));
      break;
    case PROP_MAX_CONTENT_WIDTH:
      gcards_scrolled_window_set_max_content_width (self, g_value_get_int (value));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gcards_scrolled_window_class_init (GCardsScrolledWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  object_class->finalize = gcards_scrolled_window_finalize;
  object_class->get_property = gcards_scrolled_window_get_property;
  object_class->set_property = gcards_scrolled_window_set_property;

  widget_class->get_preferred_width = gcards_scrolled_window_get_preferred_width;
  widget_class->get_preferred_height = gcards_scrolled_window_get_preferred_height;

  gParamSpecs [PROP_MAX_CONTENT_HEIGHT] =
    g_param_spec_int ("max-content-height",
                      "Max Content Height",
                      "The maximum height request that can be made.",
                      -1,
                      G_MAXINT,
                      -1,
                      (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  gParamSpecs [PROP_MAX_CONTENT_WIDTH] =
    g_param_spec_int ("max-content-width",
                      "Max Content Height",
                      "The maximum height request that can be made.",
                      -1,
                      G_MAXINT,
                      -1,
                      (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));

  g_object_class_install_properties (object_class, LAST_PROP, gParamSpecs);
}

static void
gcards_scrolled_window_init (GCardsScrolledWindow *self)
{
  self->max_content_height = -1;
  self->max_content_width  = -1;
}

/* Public Methods */
gint
gcards_scrolled_window_get_max_content_height (GCardsScrolledWindow *self)
{
  g_return_val_if_fail (GCARDS_IS_SCROLLED_WINDOW (self), -1);

  return self->max_content_height;
}

gint
gcards_scrolled_window_get_max_content_width (GCardsScrolledWindow *self)
{
  g_return_val_if_fail (GCARDS_IS_SCROLLED_WINDOW (self), -1);

  return self->max_content_width;
}

void
gcards_scrolled_window_set_max_content_height (GCardsScrolledWindow *self,
                                               gint                  max_content_height)
{
  g_return_if_fail (GCARDS_IS_SCROLLED_WINDOW (self));

  if (max_content_height != self->max_content_height)
    {
      self->max_content_height = max_content_height;
      g_object_notify_by_pspec (G_OBJECT (self), gParamSpecs[PROP_MAX_CONTENT_HEIGHT]);
      gtk_widget_queue_resize (GTK_WIDGET (self));
    }
}

void
gcards_scrolled_window_set_max_content_width (GCardsScrolledWindow *self,
                                              gint                  max_content_width)
{
  g_return_if_fail (GCARDS_IS_SCROLLED_WINDOW (self));

  if (max_content_width != self->max_content_width)
    {
      self->max_content_width = max_content_width;
      g_object_notify_by_pspec (G_OBJECT (self), gParamSpecs [PROP_MAX_CONTENT_WIDTH]);
      gtk_widget_queue_resize (GTK_WIDGET (self));
    }
}
