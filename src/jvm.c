/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "jvm.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

static void setEntryPointClassName(void *_self, const char *className)
{
  JVM * self = (JVM *)_self;
  strcpy(self->entryPoint->className, className);
}

static void setEntryPointMethodName(void *_self, const char *methodName)
{
  JVM * self = (JVM *)_self;
  strcpy(self->entryPoint->methodName, methodName);
}

static void setLogLevel(void *_self, int level)
{
  JVM * self = (JVM *)_self;
  self->LOG->setLogLevel(self->LOG, level);
}

static void loadClassFile(void *_self, const char *fileName)
{
  JVM * self = (JVM *)_self;
  self->CLASSES->loadClassFile(self->CLASSES, fileName);
}

static void loadClassFiles(void *_self, const char *dirName)
{
  JVM * self = (JVM *)_self;
  self->CLASSES->addPath(self->CLASSES, dirName);
  DIR *dir;
  char *file;
  struct dirent * ptr;
  if ((dir=opendir(dirName)) == NULL)
  {
    perror("Open dir error...");
    exit(1);
  }
  file = (char *)malloc(sizeof(char) * MAXSIZE);
  while ((ptr=readdir(dir)) != NULL)
  {
    strcpy(file, dirName);
    strcat(file, "/");
    strcat(file, ptr->d_name);
    self->LOG->debug(self->LOG, file);
  }

  closedir(dir);
    // var files = fs.readdirSync(dirName);
    // files.forEach(function(file) {
    //     var p = util.format("%s/%s", dirName, file);
    //     var stat = fs.statSync(p);
    //     if (stat.isFile()) {
    //         if (path.extname(file) === ".class") {
    //             self.loadClassFile(p);
    //         }
    //     } else if (stat.isDirectory()) {
    //         self.loadClassFiles(p);
    //     }
    // });
}
static void loadJSFile(void *_self, const char *fileName)
{
  JVM *self = (JVM *)_self;
  self->CLASSES->loadJSFile(self->CLASSES, fileName);
}
static void loadJarFile(void *_self, const char *fileName)
{
  JVM *self = (JVM *)_self;
  self->CLASSES->loadJarFile(self->CLASSES, fileName);
}

static void run(void *_self)
{
  JVM *self = (JVM *)_self;

  self->CLASSES->clinit(self->CLASSES);

  struct EntryPoint * entryPoint;
  entryPoint = self->CLASSES->getEntryPoint(
                                      self->CLASSES,
                                      self->entryPoint->className,
                                      self->entryPoint->methodName);

  // if (!entryPoint) {
  //   throw new Error("Entry point method is not found.");
  // }
  // assert(!entryPoint);


    // entryPoint.run(arguments, function(code) {
    //     var exit = function() {
    //         SCHEDULER.tick(0, function() {
    //             if (THREADS.count() === 1) {
    //                 THREADS.remove(0);
    //                 self.emit("exit", code);
    //             } else {
    //                 exit();
    //             }
    //         });
    //     };
    //     exit();
    // });
}

extern Logger * newLogger();
extern Classes * newClasses();

JVM * newJVM(){
  JVM * jvm = (JVM *)malloc(sizeof(JVM));

  jvm->LOG        = newLogger();
  jvm->CLASSES    = newClasses();
  jvm->THREADS    = newThreads();
  jvm->SCHEDULER  = newScheduler(0);
  jvm->OPCODES    = newOpcodes();

  jvm->setEntryPointClassName   = setEntryPointClassName;
  jvm->setEntryPointMethodName  = setEntryPointMethodName;
  jvm->setLogLevel              = setLogLevel;
  jvm->loadClassFile            = loadClassFile;
  jvm->loadClassFiles           = loadClassFiles;
  jvm->loadJSFile               = loadJSFile;
  jvm->loadJarFile              = loadJarFile;

  jvm->run = run;


  jvm->THREADS->add(jvm->THREADS, newThread("main"));

  strcpy(jvm->entryPoint->className, "");
  strcpy(jvm->entryPoint->methodName, "main");

  return jvm;
}