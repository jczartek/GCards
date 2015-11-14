/* gc-greeter-window.h
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

#ifndef __GCARDS_GREETER_WINDOW_H__
#define __GCARDS_GREETER_WINDOW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GCARDS_TYPE_GREETER_WINDOW (gcards_greeter_window_get_type())

G_DECLARE_DERIVABLE_TYPE (GCardsGreeterWindow, gcards_greeter_window, GCARDS, GREETER_WINDOW, GtkApplicationWindow)

struct _GCardsGreeterWindowClass
{
  GtkApplicationWindowClass parent;
};

GtkWidget * gcards_greeter_window_new (GApplication *app);

G_END_DECLS

#endif /* __GCARDS_GREETER_WINDOW_H__ */
