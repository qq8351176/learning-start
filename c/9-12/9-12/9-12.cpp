#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
	//
	//strerror 将错误码转换为错误信息
	//printf("%s\n", strerror(0));
	//printf("%s\n", strerror(1));
	//printf("%s\n", strerror(2));
	//printf("%s\n", strerror(3));
	//printf("%s\n", strerror(4));
	//printf("%s\n", strerror(5));
	//c语言库函数报错的时候的错误码
	//

	//错误码记录到错误码变量中
	//<errno.h>
	FILE* pf =  fopen("test.txt", "r");
	if(pf==NULL)
	{ 
		perror("fopen");
		return 1;
	}

	fclose(pf);
	pf = NULL;
	return 0;
}
//int main()
//{
//	char arr[] = "kwd@qq.com";
//	char buf[200] = { 0 };
//	strcpy(buf, arr);
//
//	char* str = NULL;
//	char p[] = "@.";
//	for (str = strtok(buf,p) ;str!=NULL;str=strtok(NULL,p))
//	{
//		printf("%s\n",str);
//	}
//	//const char* p = "@.";
//	//char* str = strtok(buf, p);
//	//printf("%s\n", str);
//
//	//str = strtok(NULL, p);
//	//printf("%s\n", str);
//
//	//str = strtok(NULL, p);
//	//printf("%s\n", str);
//}