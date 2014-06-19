/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "thread.h"

static void setName(void *_self, char *name)
{
  Thread * self = (Thread *)_self;
  strcpy(self->name, name);
}

static char * getName(void *_self)
{
  Thread * self = (Thread *)_self;
  return self->name;
}

static void setPriority(void *_self, int priority)
{
  Thread * self = (Thread *)_self;
  self->priority = priority;
}

static int getPriority(void *_self)
{
  Thread * self = (Thread *)_self;
  return self->priority;
}

Thread *newThread(char *name)
{
  Thread * thread = (Thread *)malloc(sizeof(Thread));
  strcpy(thread->name, name == NULL ? name || "noname");
  thread->priority = (MAX_PRIORITY + MIN_PRIORITY) >> 1;

  thread->setName = setName;
  thread->getName = getName;
  thread->setPriority = setPriority;
  thread->getPriority = getPriority;

  return thread;
}