#define MAXSIZE 20
#include <stdio.h>
typedef struct
{
    int key;
} RedType;
typedef struct
{
    RedType r[MAXSIZE + 1];
    int length;
} SqList;
int parttion(int low, int high, SqList *L)
{
    L->r[0] = L->r[low];
    int pivotkey = L->r[low].key;
    while (low < high)
    {
        while (low < high && (L->r[high].key >= pivotkey))
            --high;
        L->r[low] = L->r[high];
        while (low < high && (L->r[low].key <= pivotkey))
            ++low;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low;
}
void quick_sort(int low, int high, SqList *L)
{
    if (low < high)
    {
        int pivotloc = parttion(low,high,L);
        quick_sort(low, pivotloc-1, L);
        quick_sort(pivotloc+1, high, L);
    }
}
int main()
{
    int i = 0, j = 1, m;
    SqList L;
    L.length = 13;
    int datas[] = {-1, 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    for (i = 1; i <= L.length; i++)
    {
        L.r[i].key = datas[i];
    }
    quick_sort(1,L.length,&L);
    for (i = 1; i <= L.length; i++)
    {
        printf("%d ", L.r[i].key);
    }
    return 0;
}
