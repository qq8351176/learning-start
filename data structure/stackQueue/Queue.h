#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode *Next;
} QNode;
typedef struct Queue
{
    QNode* head;
    QNode* tail;
}Queue;
