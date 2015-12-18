#include <gtk/gtk.h>
#include "gc-app.h"

gint
main (gint argc, char* argv[])
{
  GCardsApp *app = NULL;
  gint       status;

  app = gcards_app_new ();
  status = g_application_run (G_APPLICATION (app),
                              argc, argv);
  g_object_unref (app);
  return status;
}
