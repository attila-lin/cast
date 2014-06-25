#include "scheduler.h"

static void tick(void *_self, pid_t pid, void (*fn)())
{
  Scheduler * self = (Scheduler *)_self;
  switch(self->_mode) {
    case SYNC:
      (*fn)();
      break;
    case YIELD:
      self->_mode = NORMAL;
      self->_ticks = 0;
      // (setImmediate || process.nextTick)(fn);
      break;
    case NORMAL:
      // if (++self->_ticks > THREADS.getThread(pid).getPriority())
      // {
      //   self->_ticks = 0;
      //   // (setImmediate || process.nextTick)(fn);
      // }
      // else
      {
        (*fn)();
      }
      break;
  }
}

static void yield(void *_self)
{
  Scheduler * self = (Scheduler *)_self;
  self->_mode = YIELD;
}

static void sync(void *_self, void (*fn)())
{
  Scheduler * self = (Scheduler *)_self;
  self->_mode = SYNC;
  (*fn)();
  self->_mode = NORMAL;
}



Scheduler * newScheduler(int mticks)
{
  Scheduler * scheduler = (Scheduler *)malloc(sizeof(Scheduler));
  scheduler->_ticks = mticks;
  scheduler->_mode = NORMAL;

  scheduler->tick = tick;
  scheduler->yield = yield;
  scheduler->sync = sync;

  return scheduler;
}