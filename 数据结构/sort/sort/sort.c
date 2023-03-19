#include "Sort.h"

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//��������  ������ȱ��
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
//ʱ�临�Ӷ� o(n ��1.3�η�)
//ϣ������ 1.Ԥ����(��������) 2.��������
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
	//gap>1ΪԤ����
	//��gapΪ1��ʱ�� ����Ϊ��������

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
		//��ʱ��a��һ��ָ��
		//PrintArray(a, n);
	}

}

//ѡ������
//�κ��������o(n ƽf��)
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

//��������
//ð������
//ʱ�临�Ӷ�O(N ƽ��)
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

//����ȡ��
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

//�ڿӷ�
int PastSort2(int* a, int begin, int end)
{
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//�ұ���С ���ߵĿ�����
		while (left < right && a[right] >= key)
			--right;

		a[hole] = a[right];
		hole = right;

		//����Ҵ� ��ұ߿�����
		while (left < right && a[left] <= key)
			++left;
		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

//˫ָ�뷽��
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
//hoare �汾��quicksort
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


//С�����Ż� �������Сʱ ��ֱ�Ӳ������� ����һ����������  ȥ�����һ�� �ݹ������һ��
void QuickSort(int* a, int begin,int end)
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin + 1) < 15)
	{
		//С�����ʱ��ֱ�Ӳ���
		InsertSort(a+begin, end - begin + 1);
	}
	else
	{
		int keyi = PastSort3(a, begin,end);
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
}


