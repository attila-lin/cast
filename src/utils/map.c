/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */
#include "map.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>

static void * get(void *_self, void * key)
{
  Map * self = (Map *)_self;
  MapNode * tmp = self->head;

  if (tmp == NULL)
    return NULL;

  while(tmp->next != self->head->next)
  {
    if ((CHECK_STRUCT_TYPE(self->keytype) *)tmp->key->diff(tmp->key, key) == 0)
    {
      return tmp->value;
    }
  }
  return NULL;
}

static void _add(void *_self, void * key, void * value)
{
  Map * self = (Map *)_self;
  MapNode * tmp = self->head;

  self->head = (MapNode *)malloc(sizeof(MapNode));
  self->head->key = key;
  self->head->value = value;
  self->head->prev = self->tail;
  self->head->next = tmp;

  tmp->prev = self->head;
  self->tail = self->head;
}

static void set(void *_self, void * key, void * value)
{
  printf("eh\n");
  Map * self = (Map *)_self;
  MapNode * tmp = self->head;

  if (tmp == NULL)
  {
    _add(_self, key, value);
    return;
  }



  while(tmp->next != self->head->next)
  {
    if (tmp->key->diff(tmp->key, key) == 0)
    {
      tmp->value = value;
    }
  }
  _add(_self, key, value);
}

Map *newMap(char * keytype, char * valuetype)
{
  Map * map = (Map *)malloc(sizeof(Map));

  strcpy(map->keytype, keytype);
  strcpy(map->valuetype, valuetype);
  map->head = NULL;
  map->tail = NULL;

  map->size = 0;

  map->get = get;
  map->set = set;

  return map;
}
