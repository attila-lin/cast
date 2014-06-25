/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */
#ifndef OBJECT_H_
#define OBJECT_H_

#include <string.h>

#define MAXSIZE 124
typedef struct Object Object;


struct Object
{
  size_t size;
  char type[33];

  // void * (* ctor) (void * self, va_list * app);
  void * (* dtor) (void * self);
  void * (* clone) (const void * self);
  int (* diff) (const void * self, const void * b);
};

#endif /*OBJECT_H_*/
