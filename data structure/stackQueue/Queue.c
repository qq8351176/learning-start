#include "Queue.h"

void QueueInit(Queue *q)
{
    assert(q);
    q->head = q->tail = NULL;
}

void QueueDestory(Queue *q)
{
    assert(q);
    QNode *cur = q->head;
    while (cur)
    {
        QNode *next = cur->Next;
        free(cur);
        cur = next;
    }
    q->head = q->tail = NULL;
}

void QueuePush(Queue *q, QDataType x)
{
    assert(q);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        return;
    }
    newnode->data = x;
    newnode->Next = NULL;
    if (q->tail == NULL)
    {
        q->head = q->tail = newnode;
    }
    else
    {
        q->tail->Next = newnode;
        q->tail = newnode;
    }
}

void QueuePop(Queue *q)
{
    assert(q);
    assert(q->head);
    if (q->head->Next == NULL)
    {
        free(q->head);
        q->head = q->tail = NULL;
    }
    else
    {
        QNode *next = q->head->Next;
        free(q->head);
        q->head = next;
    }
}

QDataType QueueFront(Queue *q)
{
    assert(q);
    assert(q->head);
    return q->head->data;
}

QDataType QueueBack(Queue *q)
{
    assert(q);
    assert(q->head);
    return q->head->data;
}

int QueueSize(Queue *q)
{
    assert(q);
    int size = 0;
    QNode *cur = q->head;
    while (cur)
    {
        ++size;
        cur = cur->Next;
    }
    return size;
}

bool QueueEmpty(Queue *q)
{
    assert(q);
    return q->head == NULL;
}

int main()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);
    while (!QueueEmpty(&q))
    {
        printf("%d",QueueFront(&q));
        QueuePop(&q);
    }
    QueueDestory(&q);
    return 0;
}