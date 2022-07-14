#include "SeqList.h"
#include "SeqList.c"

int main()
{
    SL sl;
    sl.size = 0;
    for (int i = 0; i < N; i++)
    {
        SeqListInit(&sl, i);
    }

    for (size_t i = 0; i < sl.size; i++)
    {
        printf("%d\n",sl.a[i]);
    }
}