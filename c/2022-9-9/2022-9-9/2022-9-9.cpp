#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//}
//int main()
//{
//	char arr[10] = "xxxxxxxxx";
//	const char* p = "abcdef";
//	char arr2[] = { 'b','i','t' };
//	strcpy(arr, p);
//	printf("%s", p);
//	return 0;
//}
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* cur= dest;
//	while (*cur != '\0')
//	{
//		cur++;
//	}
//	while (*cur++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//int main()
//{
//	char arr[20] = "hello xxxx\0xxxxxx";
//	char arr2[] = "world";
//	
//	printf("%s", my_strcat(arr, arr));//这样写就报错 因为一直在覆盖
//
//	return 0;
//}
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1);
	assert(s2);
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return 0;
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return 1;
	else
		return -1;
}
int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcf";
	int ret = my_strcmp(arr1, arr2);
	printf("%d", ret);
}