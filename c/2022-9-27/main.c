#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct MyStruct
{
	int n;
	float s;
	int *arr;
}S;
//�������� ��������ǰ������������һ��������Ա sizeof�������ֽṹ�Ĵ�С�����������������ڴ�
//�������������Ա�Ľṹ��malloc ���� �����ڴ�Ķ�̬���� ���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С 
//#include <stdio.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//}
//�������� 



//int main()
//{
//	
//	//printf("sizeof MyStruct is %d", sizeof  s);
//	S* ps = malloc(sizeof(S) + sizeof(int)*4);
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	ps->n = 100;
//	ps->s = 5.5f;
//	int i = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		scanf("%d", &(ps->arr[i]));
//	}
//	printf("%d %f", ps->n,ps->s);
//	for (size_t i = 0; i < 4; i++)
//	{
//		printf("%d ",ps->arr[i]);
//	}
//
//	//����
//	S* ptr = realloc(ps, sizeof(S) + 10 * sizeof(int));
//
//
//
//	free(ps);
//	ps = NULL;
//	return 0;
//	
//}
//

int main()
{
	S* ps = (S*)malloc(sizeof(S));
	if (ps == NULL)
	{
		return 1;
	}

	ps->n = 100;
	ps->s = 5.5f;
	int* ptr = (int*)malloc(4 * sizeof(int));
	if (ptr == NULL)
	{
		return 1;
	}
	else
	{
		ps->arr = ptr;
	}
	free(ptr);
	free(ps);

}
