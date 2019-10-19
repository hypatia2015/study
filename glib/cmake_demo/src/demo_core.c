
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>

#ifdef EVENT_LOOP
int
export_demo_main_event_loop()
{
  int ret = 0;
  gboolean is_run = FALSE;
  GMainLoop *p_loop = NULL;
  GMainContext * p_cxt = NULL;
  GSource *p_source = NULL;

  p_loop = g_main_loop_new(NULL, FALSE);

  p_cxt = g_main_loop_get_context(p_loop);

  g_main_loop_run(p_loop);

  is_run = g_main_loop_is_running(p_loop);
  is_run = g_main_context_pending(p_cxt);
  g_main_context_wakeup(p_cxt);
  g_main_context_dispatch(p_cxt);
  g_main_context_set_poll_func(p_txt, GPollFunc());
  g_main_current_source();
  g_main_context_invoke(p_txt, GSourceFunc(), NULL);
  g_main_context_push_thread_default(p_txt);
  g_main_context_pop_thread_default(p_txt);
  g_timeout_source_new_seconds(10);
  p_source = g_source_new(GSourceFuncs(), szieof(GSource));
  g_source_set_funcs(p_source, GSourceFuncs());
  g_source_attach(p_source, p_txt);
  g_source_set_priority(p_source, 4);
  g_source_set_can_recurse(p_source, TRUE);
  g_source_get_id(p_source);
  g_source_get_name(p_source);
  g_source_set_name_by_id(1, "123");
  g_source_set_callback();


  g_source_destroy(p_source);
  g_main_context_release();
  g_main_loop_quit(p_loop)
  return ret;
}
#endif
/*******************************************************/
static gpointer
threadf (gpointer data)
{
  GThread *thread = NULL;
  GMainLoop *loop = NULL;

  loop = g_main_loop_new (NULL, FALSE);
  
#if 0
  GMainContext *context = data;
  GMainLoop *loop;
  GSource *source;

  loop = g_main_loop_new (context, FALSE);
  source = g_timeout_source_new (250);
  g_source_set_callback (source, timeout_cb, loop, NULL);
  g_source_attach (source, context);
  g_source_unref (source);
 
  g_main_loop_run (loop);

  g_main_loop_unref (loop);
#endif

  thread = g_thread_self();
  printf("thread addr %p\n", thread);
  g_main_loop_run (loop);

  return NULL;
}
void
export_demo_thread()
{
  GMainContext *context;
  GThread *t1, *t2, *t3;
  char * p_data1 = "t3";
  char * p_data0 = "tnew";
  guint nthread = 0;

  context = g_main_context_new ();

  t1 = g_thread_new ("t1", threadf, p_data0);
  t2 = g_thread_new ("t2", threadf, NULL);

  t3 = g_thread_create (threadf, p_data1, TRUE, NULL);

  nthread = g_get_num_processors();
  //g_thread_join (t1);
  //g_thread_join (t2);
  //g_thread_join (t3);

  g_main_context_unref (context);


  return;
}

void export_demo_thread_pool()
{
  int i = 0;
  int ret = 0;
  GThreadPool *pool = NULL;
  char * p_poolname = "p1";

  pool = g_thread_pool_new((GFunc)threadf, p_poolname, 5, FALSE, NULL);

  g_thread_pool_set_max_unused_threads(1);
  for (i = 0; i < 3; i++)
  {
    g_thread_pool_push (pool, GUINT_TO_POINTER (i + 1), NULL);
  }
  ret = g_thread_pool_get_max_threads(pool);
  ret = g_thread_pool_get_num_threads(pool);
  ret = g_thread_pool_unprocessed(pool);

  return;
}

void export_demo_thread_async_queue()
{
  gint ret = 0;
  GAsyncQueue *aq;
  char * p_data0 = "asyncqueue";

  aq = g_async_queue_new ();
#if 0
  GPOINTER_TO_INT()
  INT_TO_GPOINTER()
#endif
  g_async_queue_push (aq, p_data0);
  ret = g_async_queue_length (aq);
  gpointer *p = g_async_queue_pop (aq);//则该功能将阻塞，直到有可用数据为止
  ret = g_async_queue_length (aq);
  g_async_queue_lock (aq);
  g_async_queue_unlock(aq);

  return;
}

void export_demo_mem()
{
   gpointer *p = NULL;
   gpointer *q = NULL;
   gchar *str = NULL, *newstr = NULL;
   int size = 5;


   str = g_new (gchar, size);
   newstr = g_renew (gchar, str, 7);
   g_free (newstr);
#if 0
  g_autoptr (gchar)p = g_new(gchar, 5); 
  memset(p,'a', 1);
  q = g_steal_pointer(&p);
#endif

  //在Linux上的线程环境中，每个线程的堆栈大小限制为2 MB

  return;
}

void
export_demo_slice()
{
  void *b = g_slice_alloc (5);
  const gchar *block = "0123456789ABCDEF";
  gpointer p = NULL;
  p = g_slice_copy (12, block);

  g_slice_free1 (12, p);

  return;
}

void export_demo_io_channel()
{
#if 0
  GIOChannel * p = NULL;
  p = g_io_channel_init();
  p = g_io_channel_unix_new();
#endif

  return;
}

void export_demo_core()
{

#ifdef LOOP_EVENT
  export_demo_main_event_loop();
#endif

  export_demo_thread();
  export_demo_thread_pool();
  export_demo_thread_async_queue();
  export_demo_mem();
  export_demo_slice();

  return;
}
