/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "logger.h"
#include <stdio.h>
#include <stdlib.h>

inline int CHECK(int levels, int level)
{
  return (levels & level) == level ? 1 : 0;
}

static void setLogLevel(void *_self, int levels)
{
  Logger * self = (Logger *)_self;
  self->levels = levels;
}

static void debug(void *_self, char *msg)
{
  Logger * self = (Logger *)_self;
  if (CHECK(self->levels, DEBUG))
    printf("%s\n", msg);
}

static void error(void *_self, char *msg)
{
  Logger * self = (Logger *)_self;
  if (CHECK(self->levels, ERROR))
    printf("%s\n", msg);
}

static void info(void *_self, char *msg)
{
  Logger * self = (Logger *)_self;
  if (CHECK(self->levels, INFO))
    printf("%s\n", msg);
}

static void warn(void *_self, char *msg)
{
  Logger * self = (Logger *)_self;
  if (CHECK(self->levels, WARN))
    printf("%s\n", msg);
}

Logger * newLogger(int levels)
{
  Logger * logger = (Logger *)malloc(sizeof(Logger));
  logger->levels = (levels == 1 ? levels : ( DEBUG | ERROR | INFO | WARN ));

  logger->setLogLevel = setLogLevel;
  logger->debug = debug;
  logger->error = error;
  logger->info = info;
  logger->warn = warn;

  return logger;
}
