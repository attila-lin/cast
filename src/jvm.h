/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef JVM_H_
#define JVM_H_

#include "object.h"

#include "classes.h"
#include "threads.h"
#include "scheduler.h"
#include "logger.h"

#include "opcodes.h"
#include "thread.h"

typedef struct JVM JVM;

struct EntryPoint
{
  char className[MAXSIZE];
  char methodName[MAXSIZE];
};

struct JVM
{
  const void * class;

  Logger * LOG;
  Classes * CLASSES;
  Threads * THREADS;
  Scheduler * SCHEDULER;
  Opcodes * OPCODES;

  struct EntryPoint *entryPoint;

  void (*setEntryPointClassName)(void *, const char *);
  void (*setEntryPointMethodName)(void *, const char *);
  void (*setLogLevel)(void *, int );
  void (*loadClassFile)(void *, const char *);
  void (*loadClassFiles)(void *, const char *);
  void (*loadJSFile)(void *, const char *);
  void (*loadJarFile)(void *, const char *);

  void (*run)(void *);

};


JVM * newJVM();



#endif /* JVM_H_ */
