#pragma once

#include <stdio.h>
#include <string.h>

#define N 10
typedef int SQDataType;
//静态数据表
typedef struct SeqList
{
    SQDataType a[N];
    int size;
} SL;
//增删改查等接口
//头插 尾插 头删 尾删
void SeqListInit(SL *s1, SQDataType x);
void SeqListPushBack(SL *ps, SQDataType x);
void SeqListPushFront(SL *ps, SQDataType x);
void SqeListPopBack(SL *ps, SQDataType x);
void SeqListPopFornt(SL *ps, SQDataType x);
