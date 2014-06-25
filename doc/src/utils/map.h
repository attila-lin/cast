/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef MAP_H_
#define MAP_H_

typedef struct Map Map;
typedef struct MapNode MapNode;

struct MapNode
{
  void * key;
  void * value;
  MapNode * prev;
  MapNode * next;
};

struct Map
{
  const void * object;

  char keytype[33];
  char valuetype[33];

  MapNode *head;
  MapNode *tail;

  long size;

  void *(*get)(void *_self, void * key);
  void (*set)(void *_self, void * key, void * value);
};


Map *newMap(char * keytype, char * valuetype);

#endif /*MAP_H_*/

