#include "Heap.h"
void test()
{
	int array[] = { 25,15,19,18,28,34,65,49,27,37 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(array)/sizeof(int); i++)
	{	
		HeapPush(&hp, array[i]);
	}
	HeapPrint(&hp);
	
	int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HPDestorty(&hp);
}
void test1()
{
	int array[] = { 25,15,19,18,28,34,65,49,27,37 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		HeapPush(&hp, array[i]);
	}
	HeapPrint(&hp);

	int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HPDestorty(&hp);
}
int main()
{
	test();
	return 0;
}
