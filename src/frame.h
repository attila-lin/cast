/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef FRAME_H_
#define FRAME_H_
typedef struct Frame Frame;

#include <sys/types.h>

struct Frame
{
  const void * class;

  pid_t _pid;
  Map * _cp;

  void (*setPid)(pid_t pid);

  void (*_read8)();
  void (*_read16)();
  void (*_read32)();


};

#endif /*FRAME_H_*/
