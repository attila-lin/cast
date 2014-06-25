/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef CLASSAREA_H_
#define CLASSAREA_H_

#include "../utils/types.h"

typedef struct ClassArea ClassArea;

struct ClassArea
{
  const void * class;

  Map * classImage;

  char * (*getClassName)();
  char * (*getSuperClassName)();
  char * (*getAccessFlags)();
  char * (*getConstantPool)();
  char * (*getFields)();
  char * (*getMethods)();
  char * (*getClasses)();



};

Map * getClassImage(byte* classBytes);

#endif /*CLASSAREA_H_*/
