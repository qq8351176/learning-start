#include "Sort.h"

void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 ,6,-7,-3,-4,-6,-1,87,745,62};

	//PrintArray(a, 10);
	//InsertSort(a,10);
	//PrintArray(a, 10);

	PrintArray(a, sizeof(a)/sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
int main()
{
	TestInsertSort();
	return 0;
}