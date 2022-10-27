#include <stdio.h>
int main()
{
    int f0 = 0;
    int f1 = 1;
    int tmp = 0;
    int n = 0;
    scanf("%d", &n);
    while (1)
    {
        if (n == f0 && n == f1)
        {
            printf("0");
            return 0;
        }
        tmp = f1;
        f1 = f1 + f0;
        f0 = tmp;
        if (f1 > n)
        {
            if (f1 - n < n - f0)
            {
                printf("%d", f1 - n);
                return 0;
            }
            else
            {
                printf("%d", n - f0);
               return 0;
            }
        }
    }

    return 0;
}