#include "DoubleLink.h"
DList *CreatNode(elemtype x)
{
    DList *newnode = (DList *)malloc(sizeof(DList));
    newnode->data = x;
    newnode->next = newnode->prev = NULL;
    return newnode;
}
void ListInsert(DLink* pos,elemtype x)
{
    assert(pos);
    DLink* prev = pos->prev;
    DLink* newnode=CreatNode(x);
    prev->next=newnode;
    newnode->prev=prev;
    newnode->next=pos;
    pos->prev=newnode;
}
void ListErase(DLink* pos)
{   assert(pos);
    DLink* prev=pos->prev;
    DLink* next=pos->next;
    prev->next=next;
    next->prev=prev;
    free(pos);
}

DList *ListInit()
{
    DList *phead = CreatNode(0);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}
void ListDestory(DList *phead) {
    assert(phead);
    DLink* cur =phead->next;
    while (cur!=phead)
    {
        DLink* next = cur->next;
        free(cur);
        cur=next;
    }
    free(phead);
    phead=NULL;
}
void PushBack(DLink *phead, elemtype x)
{
    // DLink *tail = phead->prev;
    // DLink *newnode = CreatNode(x);
    // tail->next = newnode;
    // newnode->prev = tail;
    // newnode->next = phead;
    // phead->prev = newnode;
    ListInsert(phead,x);
}
void PushFront(DLink *phead, elemtype x)
{
    /**   这个写法会导致prev链断掉
    DLink *newnode = CreatNode(x);
    newnode->next = phead->next;
    newnode->prev = phead;
    phead->next = newnode;
    phead->prev = newnode;
    **/
    /**正确写法
    DLink *first = phead->next;
    DLink *newnode = CreatNode(x);
    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = first;
    first->prev = newnode;
    **/
    
    
    // DLink *newnode = CreatNode(x);
    // newnode->next = phead->next;
    // phead->next->prev = newnode;
    // phead->next = newnode;
    // newnode->prev = phead;
        ListInsert(phead->next,x);

}
void LinkPopFornt(DLink *phead)
{
    assert(phead->next != phead);
    assert(phead);
    // DLink *first = phead->next;
    // DLink *second = first->next;
    // phead->next = second;
    // second->prev = phead;
    // free(first);
        ListErase(phead->next);

}
void LinkPopBack(DLink *phead)
{
    assert(phead->next != phead);
    assert(phead);
    // DLink* tail =phead->prev;
    // DLink* prev = tail->prev;
    // prev->next=phead;
    // phead->prev=prev;
    // free(tail);
    // tail=NULL;
    ListErase(phead->prev);
}
void LinkprintNext(DLink *phead)
{   
    assert(phead);
    DLink *cur = phead;
    while (cur->next != phead)
    {
        printf("%d->", cur->next->data);
        cur = cur->next;
    }
}
void LinkprintPrev(DLink *phead)
{
    DLink *cur = phead;
    while (cur->prev != phead)
    {
        printf("%d->", cur->prev->data);
        cur = cur->prev;
    }
}
DLink* ListFind(DLink* phead,elemtype x)
{
    assert(phead);
    DLink* cur=phead->next;
    while (cur!=phead)
    {
        if(cur->data ==x)
        {   
            
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}

int main()
{
    DList *plist = NULL;
    plist = ListInit();
    PushBack(plist, 1);
    PushBack(plist, 2);
    PushBack(plist, 3);
    PushBack(plist, 4);
    PushBack(plist, 5);
    PushFront(plist,5);
    PushFront(plist,4);
    PushFront(plist,3);
    PushFront(plist,2);
    PushFront(plist,1);
    PushFront(plist,0);
    LinkPopBack(plist);
    // DLink* pos = ListFind(plist,3);
    // if (pos!=NULL)
    // {   
    //     pos->data=30;
    //     printf("找到了");
    // }
    // else
    // {printf("没找到");}
    // ListInsert(pos,300);
    // ListErase(pos);
    LinkprintNext(plist);
        printf("\n");

    LinkprintPrev(plist);
    ListDestory(plist);
    printf("\n");
    LinkprintNext(plist);
        printf("\n");

        LinkprintPrev(plist);


}