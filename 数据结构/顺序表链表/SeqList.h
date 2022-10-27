#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//¾²Ì¬µÄË³Ðò±í
//#define N 10
//typedef struct SeqList
//{
//	int a[N];
//	int size;
//}SL;

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;

}SL;

void SLInit(SL* ps);
void SLDestory(SL* ps);
void SLPushBack(SL* ps,int x);
void SLOPopBack(SL* ps);
void SLPrintf(SL* ps);