#include "stack.h"

void test()
{
	ST st;

	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	StackPush(&st, 7);
	StackPush(&st, 8);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	printf("%d", StackTop(&st));

	StackDestory(&st);
}
int main()
{	
	test();
	return 0;
}