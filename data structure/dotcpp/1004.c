#include <stdio.h>
int fun(int n)
{
    if (n > 0 && n < 4)
    {
        return n;
    }
    return fun(n - 1) + fun(n - 3);
}
int main()
{
    int n;
    while (scanf("%d", &n) && n>0)
    {
        printf("%d \n", fun(n));
    }

    return 0;
}
