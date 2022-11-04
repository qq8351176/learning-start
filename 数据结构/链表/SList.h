#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;
SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnoede =(SLTNode*)malloc
}