#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node {
      int val;
      struct Node *next;
      struct Node *random;
 };

struct Node* copyRandomList(struct Node* head) {

    //在每一个节点都后面添加一个新的节点 新的节点内容和原来一样 但是新创建的节点
    assert(head);
    struct Node* cur = head;
    while (cur != NULL)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        assert(newnode);
        newnode->next = cur->next;
        newnode->random = cur->random;
        newnode->val = cur->val;
        cur->next = newnode;
        cur = newnode->next;
    }

    struct Node* phead, * ptail;
    phead = (struct Node*)malloc(sizeof(struct Node));
    ptail = (struct Node*)malloc(sizeof(struct Node));

    phead = ptail = cur = head->next;
    while (cur != NULL)
    {
        if (cur->random)
            cur->random = cur->random->next;
        else
            cur->random = NULL;
        ptail->next = cur;
        ptail = ptail->next;
        if (cur->next)
            cur = cur->next->next;
        else
            break;
    }
    return phead;



}
struct Node* init(int val, struct Node* self, struct Node* next, struct Node* random)
{   
    self->val = val;
    self->next = next;
    self->random = random;
    return self;
}
struct Node* buynode()
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct  Node));
    assert(newnode);
    return newnode;
}
void test()
{
    struct Node
        * data1 = buynode(),
        * data2 = buynode(),
        * data3 = buynode(),
        * data4 = buynode(),
        * data5 = buynode();
    init(7, data1, data2, NULL);
    init(13, data2, data3, data1);
    init(11, data3, data4, data5);
    init(10, data4, data5, data3);
    init(1, data5, NULL, 0);
    copyRandomList(data1);
}
void test1()
{
    struct Node
        * data1 = buynode(),
        * data2 = buynode();
    init(1, data1, data2, data1);
    init(2, data2, NULL, data1);
    copyRandomList(data1);
}
int main()
{
    test1();
}
