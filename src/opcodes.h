/*
 * Copyright (c) 2014, Yiyu Lin <linyiyu1992 at gmail dot com>
 * All rights reserved.
 */


#ifndef OPCODES_H_
#define OPCODES_H_

#include "utils/types.h"
#include "utils/integertype.h"
#include "utils/map.h"

typedef struct Opcodes Opcodes;

struct Opcodes
{
  Map * _cache;
};

Opcodes * newOpcodes()
{
  Opcodes * opcodes = (Opcodes *)malloc(sizeof(Opcodes));

  opcodes->_cache = newMap("String", "Int");

  printf("t\n");

  opcodes->_cache->set(opcodes->_cache, "nop", newInt(0x0));
  opcodes->_cache->set(opcodes->_cache, "aconst_null", newInt(0x1));
  opcodes->_cache->set(opcodes->_cache, "iconst_m1", newInt(0x2));
  opcodes->_cache->set(opcodes->_cache, "iconst_0", newInt(0x3));
  opcodes->_cache->set(opcodes->_cache, "iconst_1", newInt(0x4));
  opcodes->_cache->set(opcodes->_cache, "iconst_2", newInt(0x5));
  opcodes->_cache->set(opcodes->_cache, "iconst_3", newInt(0x6));
  opcodes->_cache->set(opcodes->_cache, "iconst_4", newInt(0x7));
  opcodes->_cache->set(opcodes->_cache, "iconst_5", newInt(0x8));
  opcodes->_cache->set(opcodes->_cache, "lconst_0", newInt(0x9));
  opcodes->_cache->set(opcodes->_cache, "lconst_1", newInt(0xa));
  opcodes->_cache->set(opcodes->_cache, "fconst_0", newInt(0xb));
  opcodes->_cache->set(opcodes->_cache, "fconst_1", newInt(0xc));
  opcodes->_cache->set(opcodes->_cache, "fconst_2", newInt(0xd));
  opcodes->_cache->set(opcodes->_cache, "dconst_0", newInt(0xe));
  opcodes->_cache->set(opcodes->_cache, "dconst_1", newInt(0xf));
  opcodes->_cache->set(opcodes->_cache, "bipush", newInt(0x10));
  opcodes->_cache->set(opcodes->_cache, "sipush", newInt(0x11));
  opcodes->_cache->set(opcodes->_cache, "ldc", newInt(0x12));
  opcodes->_cache->set(opcodes->_cache, "ldc_w", newInt(0x13));
  opcodes->_cache->set(opcodes->_cache, "ldc2_w", newInt(0x14));
  opcodes->_cache->set(opcodes->_cache, "iload", newInt(0x15));
  opcodes->_cache->set(opcodes->_cache, "lload", newInt(0x16));
  opcodes->_cache->set(opcodes->_cache, "fload", newInt(0x17));
  opcodes->_cache->set(opcodes->_cache, "dload", newInt(0x18));
  opcodes->_cache->set(opcodes->_cache, "aload", newInt(0x19));
  opcodes->_cache->set(opcodes->_cache, "iload_0", newInt(0x1a));
  opcodes->_cache->set(opcodes->_cache, "iload_1", newInt(0x1b));
  opcodes->_cache->set(opcodes->_cache, "iload_2", newInt(0x1c));
  opcodes->_cache->set(opcodes->_cache, "iload_3", newInt(0x1d));
  opcodes->_cache->set(opcodes->_cache, "lload_0", newInt(0x1e));
  opcodes->_cache->set(opcodes->_cache, "lload_1", newInt(0x1f));
  opcodes->_cache->set(opcodes->_cache, "lload_2", newInt(0x20));
  opcodes->_cache->set(opcodes->_cache, "lload_3", newInt(0x21));
  opcodes->_cache->set(opcodes->_cache, "fload_0", newInt(0x22));
  opcodes->_cache->set(opcodes->_cache, "fload_1", newInt(0x23));
  opcodes->_cache->set(opcodes->_cache, "fload_2", newInt(0x24));
  opcodes->_cache->set(opcodes->_cache, "fload_3", newInt(0x25));
  opcodes->_cache->set(opcodes->_cache, "dload_0", newInt(0x26));
  opcodes->_cache->set(opcodes->_cache, "dload_1", newInt(0x27));
  opcodes->_cache->set(opcodes->_cache, "dload_2", newInt(0x28));
  opcodes->_cache->set(opcodes->_cache, "dload_3", newInt(0x29));
  opcodes->_cache->set(opcodes->_cache, "aload_0", newInt(0x2a));
  opcodes->_cache->set(opcodes->_cache, "aload_1", newInt(0x2b));
  opcodes->_cache->set(opcodes->_cache, "aload_2", newInt(0x2c));
  opcodes->_cache->set(opcodes->_cache, "aload_3", newInt(0x2d));
  opcodes->_cache->set(opcodes->_cache, "iaload", newInt(0x2e));
  opcodes->_cache->set(opcodes->_cache, "laload", newInt(0x2f));
  opcodes->_cache->set(opcodes->_cache, "faload", newInt(0x30));
  opcodes->_cache->set(opcodes->_cache, "daload", newInt(0x31));
  opcodes->_cache->set(opcodes->_cache, "aaload", newInt(0x32));
  opcodes->_cache->set(opcodes->_cache, "baload", newInt(0x33));
  opcodes->_cache->set(opcodes->_cache, "caload", newInt(0x34));
  opcodes->_cache->set(opcodes->_cache, "saload", newInt(0x35));
  opcodes->_cache->set(opcodes->_cache, "istore", newInt(0x36));
  opcodes->_cache->set(opcodes->_cache, "lstore", newInt(0x37));
  opcodes->_cache->set(opcodes->_cache, "fstore", newInt(0x38));
  opcodes->_cache->set(opcodes->_cache, "dstore", newInt(0x39));
  opcodes->_cache->set(opcodes->_cache, "astore", newInt(0x3a));
  opcodes->_cache->set(opcodes->_cache, "istore_0", newInt(0x3b));
  opcodes->_cache->set(opcodes->_cache, "istore_1", newInt(0x3c));
  opcodes->_cache->set(opcodes->_cache, "istore_2", newInt(0x3d));
  opcodes->_cache->set(opcodes->_cache, "istore_3", newInt(0x3e));
  opcodes->_cache->set(opcodes->_cache, "lstore_0", newInt(0x3f));
  opcodes->_cache->set(opcodes->_cache, "lstore_1", newInt(0x40));
  opcodes->_cache->set(opcodes->_cache, "lstore_2", newInt(0x41));
  opcodes->_cache->set(opcodes->_cache, "lstore_3", newInt(0x42));
  opcodes->_cache->set(opcodes->_cache, "fstore_0", newInt(0x43));
  opcodes->_cache->set(opcodes->_cache, "fstore_1", newInt(0x44));
  opcodes->_cache->set(opcodes->_cache, "fstore_2", newInt(0x45));
  opcodes->_cache->set(opcodes->_cache, "fstore_3", newInt(0x46));
  opcodes->_cache->set(opcodes->_cache, "dstore_0", newInt(0x47));
  opcodes->_cache->set(opcodes->_cache, "dstore_1", newInt(0x48));
  opcodes->_cache->set(opcodes->_cache, "dstore_2", newInt(0x49));
  opcodes->_cache->set(opcodes->_cache, "dstore_3", newInt(0x4a));
  opcodes->_cache->set(opcodes->_cache, "astore_0", newInt(0x4b));
  opcodes->_cache->set(opcodes->_cache, "astore_1", newInt(0x4c));
  opcodes->_cache->set(opcodes->_cache, "astore_2", newInt(0x4d));
  opcodes->_cache->set(opcodes->_cache, "astore_3", newInt(0x4e));
  opcodes->_cache->set(opcodes->_cache, "iastore", newInt(0x4f));
  opcodes->_cache->set(opcodes->_cache, "lastore", newInt(0x50));
  opcodes->_cache->set(opcodes->_cache, "fastore", newInt(0x51));
  opcodes->_cache->set(opcodes->_cache, "dastore", newInt(0x52));
  opcodes->_cache->set(opcodes->_cache, "aastore", newInt(0x53));
  opcodes->_cache->set(opcodes->_cache, "bastore", newInt(0x54));
  opcodes->_cache->set(opcodes->_cache, "castore", newInt(0x55));
  opcodes->_cache->set(opcodes->_cache, "sastore", newInt(0x56));
  opcodes->_cache->set(opcodes->_cache, "pop", newInt(0x57));
  opcodes->_cache->set(opcodes->_cache, "pop2", newInt(0x58));
  opcodes->_cache->set(opcodes->_cache, "dup", newInt(0x59));
  opcodes->_cache->set(opcodes->_cache, "dup_x1", newInt(0x5a));
  opcodes->_cache->set(opcodes->_cache, "dup_x2", newInt(0x5b));
  opcodes->_cache->set(opcodes->_cache, "dup2", newInt(0x5c));
  opcodes->_cache->set(opcodes->_cache, "dup2_x1", newInt(0x5d));
  opcodes->_cache->set(opcodes->_cache, "dup2_x2", newInt(0x5e));
  opcodes->_cache->set(opcodes->_cache, "swap", newInt(0x5f));
  opcodes->_cache->set(opcodes->_cache, "iadd", newInt(0x60));
  opcodes->_cache->set(opcodes->_cache, "ladd", newInt(0x61));
  opcodes->_cache->set(opcodes->_cache, "fadd", newInt(0x62));
  opcodes->_cache->set(opcodes->_cache, "dadd", newInt(0x63));
  opcodes->_cache->set(opcodes->_cache, "isub", newInt(0x64));
  opcodes->_cache->set(opcodes->_cache, "lsub", newInt(0x65));
  opcodes->_cache->set(opcodes->_cache, "fsub", newInt(0x66));
  opcodes->_cache->set(opcodes->_cache, "dsub", newInt(0x67));
  opcodes->_cache->set(opcodes->_cache, "imul", newInt(0x68));
  opcodes->_cache->set(opcodes->_cache, "lmul", newInt(0x69));
  opcodes->_cache->set(opcodes->_cache, "fmul", newInt(0x6a));
  opcodes->_cache->set(opcodes->_cache, "dmul", newInt(0x6b));
  opcodes->_cache->set(opcodes->_cache, "idiv", newInt(0x6c));
  opcodes->_cache->set(opcodes->_cache, "ldiv", newInt(0x6d));
  opcodes->_cache->set(opcodes->_cache, "fdiv", newInt(0x6e));
  opcodes->_cache->set(opcodes->_cache, "ddiv", newInt(0x6f));
  opcodes->_cache->set(opcodes->_cache, "irem", newInt(0x70));
  opcodes->_cache->set(opcodes->_cache, "lrem", newInt(0x71));
  opcodes->_cache->set(opcodes->_cache, "frem", newInt(0x72));
  opcodes->_cache->set(opcodes->_cache, "drem", newInt(0x73));
  opcodes->_cache->set(opcodes->_cache, "ineg", newInt(0x74));
  opcodes->_cache->set(opcodes->_cache, "lneg", newInt(0x75));
  opcodes->_cache->set(opcodes->_cache, "fneg", newInt(0x76));
  opcodes->_cache->set(opcodes->_cache, "dneg", newInt(0x77));
  opcodes->_cache->set(opcodes->_cache, "ishl", newInt(0x78));
  opcodes->_cache->set(opcodes->_cache, "lshl", newInt(0x79));
  opcodes->_cache->set(opcodes->_cache, "ishr", newInt(0x7a));
  opcodes->_cache->set(opcodes->_cache, "lshr", newInt(0x7b));
  opcodes->_cache->set(opcodes->_cache, "iushr", newInt(0x7c));
  opcodes->_cache->set(opcodes->_cache, "lushr", newInt(0x7d));
  opcodes->_cache->set(opcodes->_cache, "iand", newInt(0x7e));
  opcodes->_cache->set(opcodes->_cache, "land", newInt(0x7f));
  opcodes->_cache->set(opcodes->_cache, "ior", newInt(0x80));
  opcodes->_cache->set(opcodes->_cache, "lor", newInt(0x81));
  opcodes->_cache->set(opcodes->_cache, "ixor", newInt(0x82));
  opcodes->_cache->set(opcodes->_cache, "lxor", newInt(0x83));
  opcodes->_cache->set(opcodes->_cache, "iinc", newInt(0x84));
  opcodes->_cache->set(opcodes->_cache, "i2l", newInt(0x85));
  opcodes->_cache->set(opcodes->_cache, "i2f", newInt(0x86));
  opcodes->_cache->set(opcodes->_cache, "i2d", newInt(0x87));
  opcodes->_cache->set(opcodes->_cache, "l2i", newInt(0x88));
  opcodes->_cache->set(opcodes->_cache, "l2f", newInt(0x89));
  opcodes->_cache->set(opcodes->_cache, "l2d", newInt(0x8a));
  opcodes->_cache->set(opcodes->_cache, "f2i", newInt(0x8b));
  opcodes->_cache->set(opcodes->_cache, "f2l", newInt(0x8c));
  opcodes->_cache->set(opcodes->_cache, "f2d", newInt(0x8d));
  opcodes->_cache->set(opcodes->_cache, "d2i", newInt(0x8e));
  opcodes->_cache->set(opcodes->_cache, "d2l", newInt(0x8f));
  opcodes->_cache->set(opcodes->_cache, "d2f", newInt(0x90));
  opcodes->_cache->set(opcodes->_cache, "i2b", newInt(0x91));
  opcodes->_cache->set(opcodes->_cache, "i2c", newInt(0x92));
  opcodes->_cache->set(opcodes->_cache, "i2s", newInt(0x93));
  opcodes->_cache->set(opcodes->_cache, "lcmp", newInt(0x94));
  opcodes->_cache->set(opcodes->_cache, "fcmpl", newInt(0x95));
  opcodes->_cache->set(opcodes->_cache, "fcmpg", newInt(0x96));
  opcodes->_cache->set(opcodes->_cache, "dcmpl", newInt(0x97));
  opcodes->_cache->set(opcodes->_cache, "dcmpg", newInt(0x98));
  opcodes->_cache->set(opcodes->_cache, "ifeq", newInt(0x99));
  opcodes->_cache->set(opcodes->_cache, "ifne", newInt(0x9a));
  opcodes->_cache->set(opcodes->_cache, "iflt", newInt(0x9b));
  opcodes->_cache->set(opcodes->_cache, "ifge", newInt(0x9c));
  opcodes->_cache->set(opcodes->_cache, "ifgt", newInt(0x9d));
  opcodes->_cache->set(opcodes->_cache, "ifle", newInt(0x9e));
  opcodes->_cache->set(opcodes->_cache, "if_icmpeq", newInt(0x9f));
  opcodes->_cache->set(opcodes->_cache, "if_icmpne", newInt(0xa0));
  opcodes->_cache->set(opcodes->_cache, "if_icmplt", newInt(0xa1));
  opcodes->_cache->set(opcodes->_cache, "if_icmpge", newInt(0xa2));
  opcodes->_cache->set(opcodes->_cache, "if_icmpgt", newInt(0xa3));
  opcodes->_cache->set(opcodes->_cache, "if_icmple", newInt(0xa4));
  opcodes->_cache->set(opcodes->_cache, "if_acmpeq", newInt(0xa5));
  opcodes->_cache->set(opcodes->_cache, "if_acmpne", newInt(0xa6));
  opcodes->_cache->set(opcodes->_cache, "goto", newInt(0xa7));
  opcodes->_cache->set(opcodes->_cache, "jsr", newInt(0xa8));
  opcodes->_cache->set(opcodes->_cache, "ret", newInt(0xa9));
  opcodes->_cache->set(opcodes->_cache, "tableswitch", newInt(0xaa));
  opcodes->_cache->set(opcodes->_cache, "lookupswitch", newInt(0xab));
  opcodes->_cache->set(opcodes->_cache, "ireturn", newInt(0xac));
  opcodes->_cache->set(opcodes->_cache, "lreturn", newInt(0xad));
  opcodes->_cache->set(opcodes->_cache, "freturn", newInt(0xae));
  opcodes->_cache->set(opcodes->_cache, "dreturn", newInt(0xaf));
  opcodes->_cache->set(opcodes->_cache, "areturn", newInt(0xb0));
  opcodes->_cache->set(opcodes->_cache, "return", newInt(0xb1));
  opcodes->_cache->set(opcodes->_cache, "getstatic", newInt(0xb2));
  opcodes->_cache->set(opcodes->_cache, "putstatic", newInt(0xb3));
  opcodes->_cache->set(opcodes->_cache, "getfield", newInt(0xb4));
  opcodes->_cache->set(opcodes->_cache, "putfield", newInt(0xb5));
  opcodes->_cache->set(opcodes->_cache, "invokevirtual", newInt(0xb6));
  opcodes->_cache->set(opcodes->_cache, "invokespecial", newInt(0xb7));
  opcodes->_cache->set(opcodes->_cache, "invokestatic", newInt(0xb8));
  opcodes->_cache->set(opcodes->_cache, "invokeinterface", newInt(0xb9));
  opcodes->_cache->set(opcodes->_cache, "new", newInt(0xbb));
  opcodes->_cache->set(opcodes->_cache, "newarray", newInt(0xbc));
  opcodes->_cache->set(opcodes->_cache, "anewarray", newInt(0xbd));
  opcodes->_cache->set(opcodes->_cache, "arraylength", newInt(0xbe));
  opcodes->_cache->set(opcodes->_cache, "athrow", newInt(0xbf));
  opcodes->_cache->set(opcodes->_cache, "checkcast", newInt(0xc0));
  opcodes->_cache->set(opcodes->_cache, "instanceof", newInt(0xc1));
  opcodes->_cache->set(opcodes->_cache, "monitorenter", newInt(0xc2));
  opcodes->_cache->set(opcodes->_cache, "monitorexit", newInt(0xc3));
  opcodes->_cache->set(opcodes->_cache, "wide", newInt(0xc4));
  opcodes->_cache->set(opcodes->_cache, "multianewarray", newInt(0xc5));
  opcodes->_cache->set(opcodes->_cache, "ifnull", newInt(0xc6));
  opcodes->_cache->set(opcodes->_cache, "ifnonnull", newInt(0xc7));
  opcodes->_cache->set(opcodes->_cache, "goto_w", newInt(0xc8));
  opcodes->_cache->set(opcodes->_cache, "jsr_w", newInt(0xc9));

  return opcodes;
}


#endif /*OPCODES_H_*/
