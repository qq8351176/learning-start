#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//定义一个动态数组
typedef struct
{
    int *data;
} DSqList;

//声明一个全局动态辅助数组B
DSqList B;

//动态数组初始化
void InitDSqList(DSqList *L, int len)
{
    //根据数组A的长度动态分配辅助数组B的空间
    L->data = (int *)malloc(len * sizeof(int));
}

//归并操作——表A中的两个子表A[low...mid]与A[mid+1...high]各自有序，将它们合并为一个有序表
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;

    for (int p = low; p <= high; ++p)
    { //将数组A中的元素对应复制到辅助数组B中
        B.data[p] = A[p];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k)
    {
        if (B.data[i] <= B.data[j]) //比较辅助数组B左右两段子表中的元素，并将较小的值复制到A中相应位置
            A[k] = B.data[i++];
        else
            A[k] = B.data[j++];
    }
    while (i <= mid) //如果左子表未检查完，将剩余元素依次复制到A中
        A[k++] = B.data[i++];
    while (j <= high) //如果右子表未检查完，将剩余元素依次复制到A
        A[k++] = B.data[j++];
}

//归并排序
void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;  //从中间进行划分，分成两个子表
        MergeSort(A, low, mid);      //递归的对左边的子表进行归并排序
        MergeSort(A, mid + 1, high); //递归的对右边的子表进行归并排序
        Merge(A, low, mid, high);    //将左右子表进行归并
    }
}

int main()
{
    int A[] = {49, 38, 65, 97, 76, 13, 27};
    int len = sizeof(A) / sizeof(int);
    clock_t begin, end;
    double cost;
    int bicyle = 100000000;
    begin = clock();
    while (bicyle--)
    {

        //初始化辅助数组B
        InitDSqList(&B, len);

        //归并排序
        MergeSort(A, 0, len - 1);
        //输出排序后的结果
    }

    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("CLOCKS_PER_SEC is %d\n", CLOCKS_PER_SEC);
    printf("time cost is: %lf secs\n", cost);
    // for (int i = 0; i < len; ++i)
    // {
    //     printf("%d ", A[i]);
    // }
    return 0;
}
