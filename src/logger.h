/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef LOGER_H_
#define LOGER_H_

#include "object.h"

typedef struct Logger Logger;

#define DEBUG (1<<0)
#define ERROR (1<<1)
#define INFO  (1<<2)
#define WARN  (1<<3)

struct Logger
{
  const void * class;

  int levels;

  void (*setLogLevel)(void *, int );
  void (*debug)(void *, char *);
  void (*error)(void *, char *);
  void (*info)(void *, char *);
  void (*warn)(void *, char *);

};

Logger * newLogger();


#endif /*LOGER_H_*/
