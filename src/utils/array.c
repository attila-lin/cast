/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#include "array.h"

static unsigned int indexOf(void *_self, void *value)
{
  Array *self = (Array *)_self;
  ListNode * tmp = self->head;
  if (tmp == NULL)
  {
    return -1;
  }

  int index = 0;
  while(tmp->next != self->head->next)
  {
    if (differ(tmp->value, value) == 0)
      return index;

    index ++;
  }

  return -1;
}


static void push(void *_self, void * _value)
{
  List *self = (List *)_self;
  void *value = (CHECKTYPE(self->valueType) *)_value;

  ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));

  newnode->value = (CHECKTYPE(self->valueType) *)malloc(sizeof(value));

  newnode->value = value->object->clone(value);

  newnode->next = self->head;
  newnode->prev = self->tail;
  self->tail->next = newnode;
  self->size ++;
}

static void remove(void *_self, void *_value)
{
  List *self = (List *)_self;
  void *value = (CHECKTYPE(self->valueType) *)_value;

  ListNode * tmp = self->head;
  if (tmp == NULL)
    return;

  while(tmp->next != self->head->next)
  {
    if (differ(tmp->value, value) == 0)
    {
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;

      // free
      tmp->dtor(tmp);
      self->size --;
      return;
    }
  }

}



List * newList()
{
  List * newlist = (List *)malloc(sizeof(List));
  newlist->object = (Object *)malloc(sizeof(Object));
  newlist->head = NULL;
  newlist->tail = NULL;
  newlist->size = 0;

  self->indexOf = indexOf;
  self->push = push;
  self->remove = remove;
}

