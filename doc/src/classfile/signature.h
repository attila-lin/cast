/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */

#ifndef SIGNATURE_H_
#define SIGNATURE_H_

typedef enum
{
   boolean:    'Z',
    byte:       'B',
    char:       'C',
    double:     'D',
    float:      'F',
    int:        'I',
    long:       'J',
    object:     'L',
    short:      'S',
    void:       'V',
    array:      '[',
}TYPE;

Map * parse(char * s);


#endif /*SIGNATURE_H_*/