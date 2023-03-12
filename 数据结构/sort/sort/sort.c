#include "Sort.h"

//������ӡ����ĺ���
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//��������  ������ȱ��
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1 ; i++)
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
		PrintArray(a, n);
	}
		
 }
