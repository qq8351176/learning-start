#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define N 10
typedef int SQDataType;
//静态数据表
typedef struct SeqList
{ 
    SQDataType* a;
    int size;
    int capacity;//有效数据的个数
} SL;
//增删改查等接口
//头插 尾插 头删 尾删
void SeqListInit(SL *ps);
void SeqListPushBack(SL *ps, SQDataType x);
void SeqListPushFront(SL *ps, SQDataType x);
void SqeListPopBack(SL *ps);
void SeqListPopFornt(SL *ps);
void SeqListPrint (SL *ps);
void SeqListCapacity(SL* ps);
void SeqListInsert(SL* ps,int pos,SQDataType x);
void SeqListEarse(SL* ps,int pos);
void SeqListDestory(SL *ps);
int SeqListFound(SL* ps, SQDataType x);
void SeqListModify(SL *ps, int pos, SQDataType x);
void menu();