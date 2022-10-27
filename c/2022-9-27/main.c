#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct MyStruct
{
	int n;
	float s;
	int *arr;
}S;
//柔性数组 柔性数组前面必须包含至少一个其他成员 sizeof返回这种结构的大小不会包含柔性数组的内存
//包含柔性数组成员的结构用malloc 函数 进行内存的动态分配 并且分配的内存应该大于结构的大小 
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
//柔性数组 



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
//	//调整
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
