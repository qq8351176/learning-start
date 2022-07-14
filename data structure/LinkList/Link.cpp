#include "LinkList.h"

LinkList *CreatNewNode(elemtype x)
{
    LinkList *newnode = (LinkList *)malloc(sizeof(LinkList));
    newnode->data = x;
    return newnode;
}
void ListPushBack(LinkList **pphead, elemtype x)
{
    LinkList *newnode = CreatNewNode(x);
    newnode->next = NULL;

    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    else
    {
        LinkList *tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}
void ListPushFront(LinkList **pphead, elemtype x)
{
    LinkList *newnode = CreatNewNode(x);

    newnode->next = *pphead;
    *pphead = newnode;
}
void LinkListPrint(LinkList *phead)
{
    LinkList *cur = phead;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
void ListPopFront(LinkList **pphead)
{
    if (*pphead == NULL)
    {
        return;
    }

    LinkList *next = (*pphead)->next;
    free(*pphead);
    *pphead = next;
}
void ListPopBack(LinkList **pphead)
{
    if (*pphead == NULL)
    {
        return;
    }
    else if (*pphead != NULL && (*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }

    else
    {
        LinkList *tail = (*pphead);
        LinkList *prev = (*pphead);

        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
    // LinkList *tail = (*phead);
    // while (tail->next->next != NULL)
    // {
    //     tail = tail->next;
    // }
    // tail->next->next = NULL;
    // tail->next = NULL;
}
LinkList *ListFind(LinkList *phead, elemtype x)
{
    LinkList *cur = phead;
    while (cur)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
}
//在pos前插入
void ListInsert(LinkList **pphead, LinkList *pos, elemtype x)
{
    LinkList *prev = *pphead;
    LinkList *newnode = CreatNewNode(x);
    if (prev == pos)
    {
        newnode->next = *pphead;
        *pphead = newnode;
    }
    else
    {
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = newnode;
        newnode->next = pos;
    }
}
void ListEarse(LinkList **pphead, LinkList *pos)
{
    LinkList *prev = *pphead;
    if (prev == pos)
    {
        ListPopFront(pphead);
    }
    else
    {
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
        pos = NULL;
    }
}

int main()
{
    LinkList *plist = NULL;
    ListPushFront(&plist, 1);
    ListPushFront(&plist, 2);
    ListPushFront(&plist, 3);
    LinkList *pos = ListFind(plist, 1);
    if (pos)
    {
        ListEarse(&plist, pos);
    }

    LinkListPrint(plist);
    return 0;
}