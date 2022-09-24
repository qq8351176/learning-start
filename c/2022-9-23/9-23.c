#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p = (int *)malloc(20);
    if(p == NULL) return 1;
    int i =  0;
    for(i=0;i<20;i++)
    {
        *(p+1)=i;
    }
    free(p);
    p=NULL;
    return 0;
}
// int main()
// {
//     int *p =(int*)malloc(20);
//     if (p == NULL)
//     {
//         perror("MALLOC");
//     }
//     else
//     {
//         *p=5;
//     }
//     free(p);

//     return 0;
// }
// int main()
// {
//     int *p =(int*)malloc(20);
//     *p =5;//不能确定 malloc 是否成功 可能返回NULL
//     return 0;
// }