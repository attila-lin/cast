/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */


#ifndef READER_H_
#define READER_H_


typedef struct Reader Reader;
struct Reader
{
  const void * class;
  byte * bytes;
  long offset;

  int (*read8)();
  int (*read16)();
  int (*read32)();
  int (*readString)(int length);
  int (*readBytes)(int length);

};

Reader * newReader();

#endif /*READER_H_*/