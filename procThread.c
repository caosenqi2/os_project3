#include "types.h"
#include "user.h"
#include "procThread.h"

int procThread_create(void)
{
  void * stack = malloc(4096);
  int pid = clone(stack);
  return pid;
}


void procThread_exit(int ret_val)
{
  thread_exit(ret_val);
}


void procThread_join(int tid, int * ret_val_p)
{
  void * stack;
  join(tid, ret_val_p, &stack);
  free(stack);
}

