// 堆排序
//由一个无序序列构建一个堆
//输出堆顶元素后 剩下的还是堆
//输出堆顶元素后 以堆中最后一个元素代替
//然后将根节点值与左右子树比较 小者与其交换 重复步骤
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
// ai <= ai ai <= a2i+1小根堆
// ai > a2i ai >= a2i+1大根堆
void HeapAdjust(int R[], int s, int m)
{
    int rc = R[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && R[j] < R[j + 1])
            ++j;
        if (rc >= R[j])
            break;
        R[s] = R[j];
        s = j;
    }
    R[s] = rc;
}
void HeapSort(int R[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        HeapAdjust(R, i, n);
    }
    for (i = n; i > 1; i--)
    {
        int temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        HeapAdjust(R, 1, i - 1);
    }
}
int main()
{
    int i = 0, j = 1, m;
    SqList L;
    L.length = 13;
    int datas[] = {-1, 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    HeapSort(datas, L.length);

    for (i = 1; i <= L.length; i++)
    {
        printf("%d ",datas[i]);
    }
    return 0;
}