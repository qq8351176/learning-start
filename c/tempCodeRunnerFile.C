#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *p;
    int length;
    int ac;
} S, *pS;
void create_s(pS s)
{
    int a;
    printf("你想要存储多少个数据\n");
    scanf("%d", &a);
    if (a <= 0)
    {
        printf("你不想存储数据!\n");
    }
    else
    {
        s->p = (int *)malloc(sizeof(int) * a);
        if (NULL == s->p)
            printf("空间申请失败!An");
        else
        {
            s->length = a;
            s->ac = -1;
            printf("能够存储%d个元素的空间申请成功!\n", s->length);
        }
    }
}

int main()
{
    pS s;
    create_s(s);

}

