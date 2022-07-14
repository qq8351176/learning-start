#include "stack.h"

void StackInit(Stack *ps)
{
    assert(ps);
    ps->a = malloc(sizeof(STDataType) * 4);
    ps->top = 0;
    ps->capacity = 4;
}
void StackDestory(Stack *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}
void StackPop(Stack *ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}
void StackPush(Stack *ps, STDataType x)
{
    assert(ps);
    ps->a[ps->top] = x;
    ps->top++;
    if (ps->top == ps->capacity)
    {
        STDataType *tmp = realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
        assert(tmp);
        ps->a = tmp;
        ps->capacity = ps->capacity * 2;
    }
}
STDataType StackTop(Stack *ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}
int StackSize(Stack *ps)
{
    assert(ps);
    return ps->top;
}
bool StackEmpty(Stack *ps)
{
    assert(ps);
    return ps->top == 0;
}
int main()
{
    Stack st;
    StackInit(&st);
    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,3);
    StackPush(&st,4);
    StackPush(&st,5);
    StackPush(&st,6);
    StackPush(&st,7);
    while (!StackEmpty(&st))
    {
        printf("%d",StackTop(&st));
        StackPop(&st);
    }
    
    StackDestory(&st);
    return 0;
}