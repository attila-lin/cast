/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct List List;
typedef struct ListNode ListNode;
#define LISTSIZE 1024

struct ListNode
{
  void * value;

  ListNode *prev;
  ListNode *next;
};

struct List
{
  const void * object;

  char valueType[33];

  ListNode * head;
  ListNode * tail;
  unsigned int size;

  int (*indexOf)(void *, void *);
  void (*push)(void *, void *);
  void (*remove)(void *, void *);

};

List * newList();


#endif/*LIST_H_*/
