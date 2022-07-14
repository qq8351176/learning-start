#include <stdio.h>
int prime(int n)
{
    for (size_t i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 2; i <= n; i++)
        {
            if (prime(i))
            {
                printf("%d ", i);
            }
        }
    }
    return 0;
}