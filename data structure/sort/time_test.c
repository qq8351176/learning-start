#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int i;
int main()
{
    clock_t begin, end;
    double cost;
    //开始记录
    begin = clock();

    /*待测试程序段*/
	for (i=0;i<1000;i++)
	{
		printf("hello world!\n");
	}


    //结束记录
    end = clock();
    cost = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("CLOCKS_PER_SEC is %d\n",CLOCKS_PER_SEC);
    printf("time cost is: %lf secs\n",cost);
}

