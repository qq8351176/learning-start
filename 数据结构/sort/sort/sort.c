#include "Sort.h"
#include "Stack.h"
#include <string.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//插入排序  逆序有缺陷
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}

}
//时间复杂度 o(n 的1.3次方)
//希尔排序 1.预排序(分组排序) 2.插入排序
void ShellSort(int* a, int n)
{
	//int gap = 3;
	//for (int j = 0; j < gap; ++j)
	//{
	//	for (int i = j; i < n - gap; i += gap)
	//	{
	//		int end = i;
	//		int  tmp = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (tmp < a[end])
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//			
	//		}
	//		a[end + gap] = tmp;
	//		
	//	}
	//	
	//}
	//
	int gap = n;
	//gap>1为预排序
	//当gap为1的时候 就是为插入排序！

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int  tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}

			}
			a[end + gap] = tmp;

		}
		//PrintArray(a, sizeof(a) / sizeof(int)); 
		//此时的a是一个指针
		//PrintArray(a, n);
	}

}

//选择排序
//任何情况都是o(n 平f方)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;

		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
			if (a[i] > a[maxi])
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}

}

//交换排序
//冒泡排序
//时间复杂度O(N 平方)
void BubbleSort(int* a, int n)
{
	for (int j = n - 1; j > 0; j--)
	{
		int exhange = 0;
		for (int i = 0; i < j; i++)
		{

			if (a[i] > a[i + 1])
			{
				exhange = 1;
				Swap(&a[i], &a[i + 1]);
			}
		}
		if (exhange == 0)
		{
			break;
		}
	}
}

//三数取中
int GetMidIndex(int *a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if(a[begin]>a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

int PastSort1(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
			--right;
		while (left < right && a[left] <= a[keyi])
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	keyi = left;
	
	return keyi;
}

//挖坑法
int PastSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//右边找小 填到左边的坑里面
		while (left < right && a[right] >= key)
			--right;

		a[hole] = a[right];
		hole = right;

		//左边找大 填到右边坑里面
		while (left < right && a[left] <= key)
			++left;
		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

//双指针方法
int PastSort3(int* a, int begin, int end)
{
	int keyi = begin;
	int prev, cur;
	prev = begin;
	cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] <= a[keyi])
		{
			prev++;
			if (prev != cur)
				Swap(&a[prev], &a[cur]);
		}
			cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;

}
//hoare 版本的quicksort
//void QuickSort(int* a, int begin,int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int mid = GetMidIndex(a, begin, end);
//	Swap(&a[begin], &a[mid]);
//
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//			--right;
//		while (left < right && a[left] <= a[keyi])
//			++left;
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[left], &a[keyi]);
//	keyi = left;
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi+1, end);
//	return 0;
//}


//小区间优化 当区间较小时 用直接插入排序 按照一个正三角形  去掉最后一层 递归就能少一半
//void QuickSort(int* a, int begin,int end)
//{
//	if (begin >= end)
//	{
//		return;
//	}
//
//	if ((end - begin + 1) < 15)
//	{
//		//小区间的时候直接插入
//		InsertSort(a+begin, end - begin + 1);
//	}
//	else
//	{
//		int keyi = PastSort3(a, begin,end);
//		QuickSort(a, begin, keyi - 1);
//		QuickSort(a, keyi + 1, end);
//	}
//}

//三路划分
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin + 1) < 15)
	{
		//小区间的时候直接插入
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int mid = GetMidIndex(a, begin, end);
		Swap(&a[begin], &a[mid]);

		int left = begin, right = end;
		int key = a[begin];
		int cur = begin + 1;
		while (cur <= right)
		{
			if (a[cur] < key)
			{
				Swap(&a[cur], &a[left]);
				cur++;
				left++;
			}
			else if (a[cur] > key)
			{
				Swap(&a[cur], &a[right]);
				--right;
			}
			else
			{
				cur++;
			}
		}
		QuickSort(a, begin, left - 1);
		QuickSort(a, right + 1, end);
	}
}


void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st,begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyi = PastSort3(a, left, right);

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}
 
void _MergeSort(int* a, int begin,int end,int* tmp) 
{
	if(begin >= end)
	{ 
		return;
	}

	int mid = (begin + end) / 2;
	//[begin,mid] [mid+1,end]
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin,sizeof(int)*(end-begin+1));

}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if(tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int rangeN = 1;
	while (rangeN < n)
	{
		for (int i = 0; i < n; i += 2 * rangeN)
		{

			int begin1 = i, end1 = i + rangeN - 1;
			int begin2 = i + rangeN, end2 = i + 2 * rangeN - 1;
			int j = i;
			if (end1 >= n)
			{
				break;
			}
			else if (begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
			
		}
		rangeN *= 2;
	}
	
	free(tmp);
	tmp = NULL;
}