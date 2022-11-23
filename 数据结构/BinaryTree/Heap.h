#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include<time.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
void HPInit(HP* php);
void HPDestorty(HP* php);
void HeapPush(HP* php, HPDataType x);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);
void HeapPrint(HP* php);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
void HeapCreate(HP* php, HPDataType* a, int n);