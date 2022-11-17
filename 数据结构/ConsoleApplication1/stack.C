#include "stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	
	ps->a = (STDataType*)malloc(sizeof(ST)*4);
	if (ps->a == NULL)
	{
		perror("ps->a MALLOC ERROR");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)
{	
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a,ps->capacity*2*sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("tmp realloc ERROR");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	
	return ps->top == 0;
}
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}
