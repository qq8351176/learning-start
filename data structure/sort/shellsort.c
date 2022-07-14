//排序的性能依据比较的次数以及移动的次数 二分可以缩短比较
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

int main()
{
    int i = 0, j = 1, m;
    SqList L;
    L.length = 13;
    int datas[] = {-1, 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    int dlta[] = {5, 3, 1}; //增量序列
    for (i = 1; i <= L.length; i++)
    {
        L.r[i].key = datas[i];
    }
    //选取增量 希尔排序会将数据变得有序
    //希尔排序的增量序列必须是递减的最后一个必须是1
    //增量序列应该是互质的
    for (int k = 0; k < 3; k++) // i应该小于dlta的长度
    {
        m = 0;
        for (i = dlta[k] + 1; i <= L.length; i++, m++) //第一个元素为已经有序的 所以从第二个元素开始往前插入
        {
            if (L.r[i].key < L.r[i - dlta[k] - dlta[k] * (m / dlta[k])].key) //将第当前所选中的元素与有序去的最后的一个元素比较 此处可以修改一下使其变成从第一个开始比较
            {                                 
                
                for (j = i - dlta[k] - dlta[k] * (m / dlta[k]); j <=L.length && (L.r[i].key > L.r[j].key); j = j + dlta[k])
                {
                    L.r[j - dlta[k]] = L.r[j];
                }
                L.r[j + dlta[k]] = L.r[0];
            }
        }
        // for (i = dlta[k] + 1; i <= L.length; i++)//第一个元素为已经有序的 所以从第二个元素开始往前插入
        // {
        //     if (L.r[i].key < L.r[i - dlta[k]].key) //将第当前所选中的元素与有序去的最后的一个元素比较 此处可以修改一下使其变成从第一个开始比较
        //     {
        //         L.r[0] = L.r[i];
        //         for (j = i - dlta[k]; j > 0 && (L.r[0].key < L.r[j].key); j=j-dlta[k])
        //         {
        //             L.r[j + dlta[k]] = L.r[j];
        //         }
        //         L.r[j + dlta[k]] = L.r[0];
        //     }
        // }
    }

    for (i = 1; i <= L.length; i++)
    {
        printf("%d ", L.r[i].key);
    }
    return 0;
}