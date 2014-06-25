/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef CLASSES_H_
#define CLASSES_H_

#include "utils/map.h"
#include "utils/list.h"
#include "frame.h"
#include "classfile/classarea.h"

typedef struct Classes Classes;

struct Classes
{
  const void * class;

  List* paths;
  Map * classes;
  Map * staticFields;

  void (*addPath)(void *, const char *path);
  void (*clinit)(void *);
  ClassArea * (*loadClassBytes)(void *, byte* bytes);
  void (*loadClassFile)(void *, const char * fileName);
  void (*loadJSFile)(void *, const char * fileName);
  void (*loadJarFile)(void *, const char * fileName);
  void * (*getEntryPoint)(void *, const char * className, const char * methodName);
  void (*getClass)(void *, const char *className);
  void (*getStaticField)(void *, const char * className, const char * fieldName);
  void (*setStaticField)(void *, const char * className, const char * fieldName, void* value);
  void (*getStaticMethod)(void *, const char * className, const char * methodName, int signature);
  void (*getMethod)(void *, const char * className, const char * methodName, int signature);
  void (*newObject)(void *, const char * className);
  void (*newException)(void *, const char * className, const char * message, int cause);

};

Classes * newClasses();

#endif /*CLASSES_H_*/
