/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdlib.h>

typedef enum
{
  NORMAL = 0,
  SYNC,
  YIELD
}MODE;

typedef struct Scheduler Scheduler;

struct Scheduler
{
  const void * class;

  int _ticks;
  MODE _mode;


  void (*tick)(void *_self, pid_t pid, void (*fn)() );
  void (*yield)(void *_self);
  void (*sync)(void *_self, void (*fn)() );
};


Scheduler * newScheduler(int mticks);

#endif /*SCHEDULER_H_*/
