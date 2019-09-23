
#include <stdio.h>
#include <glib.h>
#include<gio/gio.h>

void on_bus_acquired (GDBusConnection *connection,
        const gchar *name,
        gpointer user_data)
{
    printf("on_bus_acquired the name = %s\n",name);
}

void on_name_acquired (GDBusConnection *connection,
        const gchar *name,
        gpointer user_data)
{
    printf("on_name_acquired has been invoked\n");
}

void on_name_lost (GDBusConnection *connection,
        const gchar *name,
        gpointer user_data)
{
    printf("on_name_lost has been invoked\n");
}
 

int
main(int agrc, char **argv)
{
  int ret = 0;
  int bus_id = 0;
  GMainLoop *p_loop = NULL;

  p_loop = g_main_loop_new(NULL, FALSE);
  bus_id = g_bus_own_name(G_BUS_TYPE_SYSTEM, "org.test.louting",
    G_BUS_NAME_OWNER_FLAGS_NONE,
    on_bus_acquired,
    on_name_acquired, // name acquired
    on_name_lost, // name lost if a connection to the bus can't be made
    NULL, // user data
    NULL  // user date free func
  );

  printf("%d\n", bus_id);

  g_main_loop_run(p_loop);

  return ret;
}
