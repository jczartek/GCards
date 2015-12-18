/* gc-session-window.h
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

#ifndef GCARDS_SESSION_WINDOW_H
#define GCARDS_SESSION_WINDOW_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GCARDS_TYPE_SESSION_WINDOW (gcards_session_window_get_type())

G_DECLARE_FINAL_TYPE (GCardsSessionWindow, gcards_session_window, GCARDS, SESSION_WINDOW, GtkApplicationWindow)

G_END_DECLS

#endif /* GCARDS_SESSION_WINDOW_H */
