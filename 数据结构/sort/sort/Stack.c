#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	//ps->a = NULL;
	//ps->top = 0;
	//ps->capacity = 0;

	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	ps->top = 0;
	ps->capacity = 4;
}

void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackPush(ST* ps, STDatatype x)
{
	assert(ps);

	// 
	if (ps->top == ps->capacity)
	{
		STDatatype* tmp = (STDatatype*)realloc(ps->a, ps->capacity * 2 * sizeof(STDatatype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity *= 2;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

// 20:20
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

STDatatype StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return ps->top == 0;
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}
