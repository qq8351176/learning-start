#pragma once
#include <stdbool.h>
#include<stdlib.h>
#include <assert.h>
#include <stdio.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int capacity;
	int top;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

bool StackEmpty(ST* ps);
int StackSize(ST* ps);


