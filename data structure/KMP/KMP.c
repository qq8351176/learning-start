#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct
{
    char ch[100];
    int length;
} sstring;

void get_next(sstring T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
void get_next_val(sstring T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
    for (int j = 2; j < T.length; j++)
    {
        if (T.ch[next[j]] == T.ch[j])
        {
            next[j] = next[next[j]];
        }
    }
}
int Index_KMP(sstring S, sstring T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j=next[j];
        }
    }
    if (j>T.length)
    {
        return i-T.length;
    }
    else
    return 0;
    
}
int main()
{
    //
    sstring T;
    T.length = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        T.ch[++(T.length)] = c;
    }
    int* next = (int*)(malloc(T.length * sizeof(int)));
    get_next(T, next);
    next[0] = -1;
    for (int i = 1; i <= T.length; i++)
    {
        printf("%d ", next[i]);
    }
    //
    sstring S;
    S.length = 0;
    char b;
    getchar();
    while ((b = getchar()) != '\n')
    {
        S.ch[++(S.length)] = b;
    }


    printf("%d", Index_KMP(S, T, next));
    return 0;
}
