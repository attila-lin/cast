/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "classes.h"

#include "utils/fs.h"

static void addPath(void *_self, const char *path)
{
  Classes * self = (Classes *)_self;
  if (self->paths->indexOf(self->paths, path) == -1)
  {
    self->paths->push(self->paths, path);
  }
}

static void clinit(void *_self)
{

}

static ClassArea * loadClassBytes(void *_self, byte * bytes)
{
  Classes * self = (Classes *)_self;

  ClassArea * classarea = newClassArea(bytes);
  self->classes->set(self->classes, classarea->getClassName(classarea), classarea);

  return classarea;
}

static ClassArea * loadClassFile(void *_self, char * fileName)
{
  printf("loading %s ...\n", fileName);
  Classes * self = (Classes *)_self;

  FS * fs = newFS();
  Path * path = newPaht();

  byte * bytes = fs->readFileSync(fileName);
  ClassArea * ca = self->loadClassBytes(bytes);
  Array * classes = ca->getClasses(ca);
  for (int i = 0; i < classes->length; i++)
  {
    if (!self->classes->get(self->classes, i))
    {
      char * tmp = (char *)malloc(sizeof(char) * MAXSIZE);
      strcpy(tmp, path->dirname(fileName));
      strcat(tmp, path->sep);
      strcat(tmp, classes->get(classes, i));
      strcat(tmp, ".class");
      self->loadClassFile(self, tmp);
    }
  }
  return ca;
}

static ClassArea * loadJSFile(void *_self, char *fileName)
{
  printf("loading %s ...\n", fileName);
  Classes * self = (Classes *)_self;

  ClassArea classarea = require(fileName);
  self->classes[classarea->getClassName(classarea)] = classarea;
  return classarea;
}

static ClassArea * loadJarFile(void *_self, char *fileName)
{
  ClassArea * classarea;
  return classarea;
}

static Frame * getEntryPoint( className, methodName)
{
  Frame * frame;
  return frame;
}


static ClassArea * getClass(void *_self, char *className)
{
  Classes * self = (Classes *)_self;
  ClassArea * ca = self->classes->get(self->classes, className);

  if (ca)
    return ca;

  FS * fs = newFS();

  for(int i = 0; i < self->paths->length; i++)
  {
      char * fileName = (char *)malloc(sizeof(char) * MAXSIZE);
      strcpy(fileName, self->paths->get(self->paths, i));
      strcat(fileName, "/");
      strcat(fileName, className);
      if (fs->existsSync(fileName + ".js"))
        return self->loadJSFile(self, strcat(fileName, ".js"));

      if(fs->existsSync(fileName + ".class"))
        return self->loadClassFile(self, strcat(fileName, ".class"));
  }

  return NULL;
}

static char * getStaticField(void *_self, char * className, char * fieldName)
{
  Classes * self = (Classes *)_self;
  char * tmp = (char *)malloc(sizeof(char) * MAXSIZE);
  strcpy(tmp, className);
  strcat(tmp, ".");
  strcat(tmp, fileName);
  return self->staticFields->get(self->staticFields, tmp);
}

static void setStaticField(void *_self, char * className, char * fieldName, int value)
{
  Classes * self = (Classes *)_self;
  char * tmp = (char *)malloc(sizeof(char) * MAXSIZE);
  strcpy(tmp, className);
  strcat(tmp, ".");
  strcat(tmp, fileName);
  self->staticFields->set(self->staticFields, tmp, value);
}

static Frame * getStaticMethod(void *_self, char * className, char * methodName, char * signature)
{
  ClassArea * ca = self->getClass(self, className);
  if (ca)
  {
    var methods = ca->getMethods();
    var cp = ca->getConstantPool();
    for(var i=0; i<methods.length; i++)
      if (ACCESS_FLAGS.isStatic(methods[i].access_flags))
        if (cp[methods[i].name_index].bytes === methodName)
          if (signature.toString() === cp[methods[i].signature_index].bytes)
            return new Frame(ca, methods[i]);
  }
  else
  {
   if (methodName in ca)
    return ca[methodName];
  }
  return null;

}


Classes * newClasses()
{
  Classes * classes = (Classes *)malloc(sizeof(Classes));
  classes->path = newList();
  classes->classes = newMap();
  classes->staticFields = newMap();

}






