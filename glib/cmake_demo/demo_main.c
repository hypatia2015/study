
#include <stdio.h>
#include <glib.h>
#include<gio/gio.h>
#include<demo_export.h>

void get_version()
{
  printf("GIT_VER:%s\nGIT_DATE%s\nBUILD_DATE%s\n",
    G_STRINGIFY(GIT_VERSION), G_STRINGIFY(GIT_DATETIME),
     G_STRINGIFY(BUILD_DATETIME));
} 

int
main(int agrc, char **argv)
{
  int ret = 0;

  get_version();

  //export_demo_gbus();

  return ret;
}
