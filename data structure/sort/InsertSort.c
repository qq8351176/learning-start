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
    int i, j;
    SqList L;
    L.length = 11;
    int datas[] = {-1, 1, 5, 6, 7, 3, 9, 4, 5, 2, 11};
    for (i = 1; i < L.length; i++)
    {
        L.r[i].key = datas[i];
    }

    for (i = 2; i < L.length; ++i)
    {
        if (L.r[i].key <L.r[i-1].key)
        {
            L.r[0] = L.r[i];
            for (j = i - 1; L.r[0].key < L.r[j].key; --j)
            {
                L.r[j+1].key = L.r[j].key;
            }
        }

        L.r[j + 1] = L.r[0];
    }
    for (i = 1; i < L.length; i++)
    {
        printf("%d ", L.r[i].key);
    }
    return 0;
}
//收获 调试的时候出现 returned 可能为出现bug死循环 或者代码没保存
//L.r[j+1].key = L.r[j].key; 类似这种语句尽量不要写自加语句 不好理解
//在查找表里 0号位置可以存放哨兵 