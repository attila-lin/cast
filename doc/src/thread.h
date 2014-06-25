/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */


#ifndef THREAD_H_
#define THREAD_H_

#define MIN_PRIORITY 0
#define MAX_PRIORITY 100

typedef struct Thread Thread;
struct Thread
{
  const void * class;

  char *name;
  int priority;

  void (*setName)(void *, char *name);
  void (*getName)(void *);
  void (*setPriority)(void *, int priority);
  void (*getPriority)(void *);


};

Thread * newThread(char *name);

#endif /*THREAD_H_*/
