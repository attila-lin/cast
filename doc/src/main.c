/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "jvm.h"
#include "version.h"

#include <stdio.h>

void usage(void)
{
  printf("usage:\n");
  printf("  ./jvm /the/dir/contains/the/classes");
}

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    usage();
    return -1;
  }

  JVM *jvm = newJVM();
  jvm->loadClassFiles(jvm, argv[1]);
  jvm->run(jvm);
  return 0;
}