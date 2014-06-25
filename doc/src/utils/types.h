/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef TYPES_H_
#define TYPES_H_

#include "../object.h"
#include "integertype.h"

typedef unsigned char byte;

// struct types
#define OBJECT  8eee8e217391199668cbac89472ace53dd

// typedef enum
// {
//   OBJECTT = 0
// }OBJECTTYPE;




// ads type
#define LIST    0x298cb25408234de02baf2085803a464a
#define ARRAY   0xcb4fb1757fb37c43cded35d3eb857c43
#define MAP     0x5af1a3a285c2bdee4192223e31e1f833

// typedef enum
// {
//   LIST = 0,
//   ARRAY,
//   MAP
// }ADSTYPE;

// data types
#define BOOLEAN c48d5da12d702e73d6966069f2687376
#define CHAR    027acd3aa6b1dd7f26119d3cf0f9a063
#define STRING  63b588d5559f64f89a416e656880b949
#define FLOAT   e738c26bf4ce1037fa81b039a915cbf6
#define DOUBLE  fd3e4ece78a7d422280d5ed379482229
#define BYTE    e409eb2ba6eb6801f52763ae370c350e
#define SHORT   a35c2b02966b1563e5bf7b81b8b0cf77
#define INT     53f93baa3057821107c750323892fa92
#define LONG    c1fabfea54ec6011e694f211f3ffebf3

// typedef enum
// {
//   BOOLEAN = 0,
//   CHAR,
//   STRING,
//   FLOAT,
//   DOUBLE,
//   BYTE,
//   SHORT,
//   INT,
//   LONG
// }DATATYPE;

#define CMPTYPE(a, b) (strcmp((a),(b)) == 0)



#define CHECK_STRUCT_TYPE(a)    return (\
  CMPTYPE(a, OBJECT)  ? Object  : (\
  CMPTYPE(a, INT)     ? Int     : (\
  CMPTYPE(a, DOUBLE)  ? Double  : (\
    ))))

#define CHECK_DATA_TYPE(a)    return (\
  CMPTYPE(a, BOOLEAN) ? Boolen  : (\
  CMPTYPE(a, CHAR)    ? char    : (\
    )))



#endif /*TYPES_H_*/

