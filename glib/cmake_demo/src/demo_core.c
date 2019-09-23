
#include <stdio.h>
#include <glib.h>

int
export_demo_main_event_loop()
{
  int ret = 0;
#ifdef XXX
  int bus_id = 0;
#endif
  GMainLoop *p_loop = NULL;

  p_loop = g_main_loop_new(NULL, FALSE);

#ifdef XXX
  bus_id = g_bus_own_name(G_BUS_TYPE_SYSTEM, "org.kernel.TCMUService1",
    G_BUS_NAME_OWNER_FLAGS_NONE,
    on_bus_acquired,
    on_name_acquired, // name acquired
    on_name_lost, // name lost if a connection to the bus can't be made
    NULL, // user data
    NULL  // user date free func
  );

  printf("%d\n", bus_id);

  g_main_loop_run(p_loop);
#endif

  return ret;
}

void export_core()
{
  return;
}
