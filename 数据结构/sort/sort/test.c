#include "Sort.h"

//用来打印数组的函数
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 ,6,-7,-3,-4,-6,-1,87,745,62,9,1,2,5,7,4,8,6,3,5 ,6,-7,-3,-4,-6,-1,87,745,62 };

	//PrintArray(a, 10);
	//InsertSort(a,10);
	//PrintArray(a, 10);

	//PrintArray(a, sizeof(a)/sizeof(int));
	//ShellSort(a, sizeof(a) / sizeof(int));
	//PrintArray(a, sizeof(a) / sizeof(int));

	//PrintArray(a, sizeof(a)/sizeof(int));
	//SelectSort(a, sizeof(a) / sizeof(int));
	//PrintArray(a, sizeof(a) / sizeof(int));

	//PrintArray(a, sizeof(a) / sizeof(int));
	//BubbleSort(a, sizeof(a) / sizeof(int));
	//PrintArray(a, sizeof(a) / sizeof(int));


	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a,0,sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	int j = 0;
	for (int i = 0; i < N; ++i)
	{
		//a1[i] = rand();
		a1[i] = i;
		/*int x = rand();
		if (x % 7 == 0 && x % 3 == 0 && x % 2 == 0)
		{
		a1[i] = x;
		++j;
		}
		else
		{
		a1[i] = i;
		}*/

		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	printf("%d\n", j);

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	//HeapSort(a4, N);
	int end4 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	//QuickSortNonR(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end7 - begin7);

	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{
	TestInsertSort();
	/*TestOP();*/
	return 0;
}