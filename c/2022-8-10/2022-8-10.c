#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
int result()
{
    int n;
    int num;
    scanf("%d", &n);
    for (int i = 0;i < n; i++)
    {
        for (int j = 0;j < n; j++)
        {
            if (i > j)
            {
                scanf("%d", &num);
                if (num)
                {
                    return 0;
                }
            }
            else
            {
                scanf("%d", &num);
            }
        }
    }
    return 1;
}
int main()
{
    if (result())
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;

}