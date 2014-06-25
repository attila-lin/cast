#ifndef INTEGERTYPE_H_
#define INTEGERTYPE_H_

#include <stdlib.h>

typedef struct Integer Int;
struct Integer
{
  const void * object;

  long value;

};

Int * newInt(int value)
{
  Int * integer = (Int *)malloc(sizeof(Int));
  integer->value = value;

  return integer;
}


#endif /*INTEGERTYPE_H_*/
