/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */


#ifndef THREADS_H_
#define THREADS_H_

#include "thread.h"

typedef struct Threads Threads;
struct Threads
{
  const void * class;

  List * threads;
  List * empty;

  pid_t (*add)(void *, Thread * thread);
  void (*remove)(void *, pid_t pid);
  void (*count)(void *);
  void (*getThread)(void *, pid_t pid);
};

Threads * newThreads();

#endif /*THREADS_H_*/
