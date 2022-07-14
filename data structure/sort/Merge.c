//二路归并排序
//收货 不能在main程序外定义 time 因为time为time.h里面的一个接口程序 所以会报错
//学习了如何输出代码运行时间
// clock_t start, finish;
// double this_time_1;
// start = clock();
// finish = clock();
// this_time_1 = (double)(finish - start) / CLOCKS_PER_SEC;
//以上为输出代码运行时间 vscode中按住alt可以隔行选中
#define MAXSIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    int *data;
} DqList;
DqList virtual;
DqList InitDqList(DqList List, int len)
{
    List.data = malloc(len * sizeof(int));
    return List;
}
void mergesort(int data[], int low, int mid, int high)
{
    int i, j, k;

    for (int p = low; p <= high; ++p)
    { //将数组A中的元素对应复制到辅助数组B中
        virtual.data[p] = data[p];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (virtual.data[i] <= virtual.data[j])
        {
            data[k] = virtual.data[i++];
        }
        else
        {
            data[k] = virtual.data[j++];
        }
    }
    while (i <= mid)
    {
        data[k++] = virtual.data[i++];
    }
    while (j <= high)
    {
        data[k++] = virtual.data[j++];
    }
}

int merge(int data[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge(data, low, mid);
        merge(data, mid + 1, high);
        mergesort(data, low, mid, high);
    }
}
int main()
{
    clock_t begin, end;
    double cost;
    int bicyle = 100000000;
    int datas[] = {49, 38, 65, 97, 76, 13, 27};

    begin = clock();
    while (bicyle--)
    {
        virtual = InitDqList(virtual, sizeof(datas) / sizeof(int));
        merge(datas, 0, 6);
    }

    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("CLOCKS_PER_SEC is %d\n", CLOCKS_PER_SEC);
    printf("time cost is: %lf secs\n", cost);
    // for (i = 0; i <= 6; i++)
    // {
    //     printf("%d ", datas[i]);
    // }
    return 0;
}

//归并排序（稳定，空间效率为O(n)，时间效率为O(nlogn)）
