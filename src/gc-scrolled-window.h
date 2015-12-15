/* gc-scrolled-window.h
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
#ifndef __GCARDS_SCROLLED_WINDOW_H__
#define __GCARDS_SCROLLED_WINDOW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GCARDS_TYPE_SCROLLED_WINDOW (gcards_scrolled_window_get_type ())

G_DECLARE_FINAL_TYPE (GCardsScrolledWindow, gcards_scrolled_window, GCARDS, SCROLLED_WINDOW, GtkScrolledWindow);

gint gcards_scrolled_window_get_max_content_height (GCardsScrolledWindow *self);
gint gcards_scrolled_window_get_max_content_width  (GCardsScrolledWindow *self);
void gcards_scrolled_window_set_max_content_height (GCardsScrolledWindow *self,
                                                    gint                  max_content_height);
void gcards_scrolled_window_set_max_content_width  (GCardsScrolledWindow *self,
                                                    gint                  max_content_width);

G_END_DECLS

#endif /* __GCARDS_SCROLLED_WINDOW_H__ */
