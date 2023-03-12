#pragma once
#include <stdbool.h>
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

//  前置的类型声明 第一次写结构体的声明
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
