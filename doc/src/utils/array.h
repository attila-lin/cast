/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef ARRAR_H_
#define ARRAR_H_

typedef struct Array Array;
#define ARRAYSIZE 1024


struct Array
{
  const void * object;

  char valueType[33];

  void * head;
  unsigned int size;

  unsigned int (*indexOf)(void *, void *);
  void (*add)(void *, void *);
  void (*get)(void *, int );

};

Array * newArray();


#endif /*ARRAR_H_*/

