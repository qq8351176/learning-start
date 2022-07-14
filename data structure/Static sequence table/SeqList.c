#include "SeqList.h"

void SeqListInit(SL *sl, SQDataType x)
{
    sl->a[sl->size] = x;
    sl->size++;
}

void SeqListPushBack(SL *ps, SQDataType x)
{
    if (ps->size >= N)
    {
        printf("顺序表已经满啦");
        return;
    }
    
    ps->a[ps->size] = x;
    ps->size++;
}
void SeqListPushFront(SL *ps, SQDataType x)
{
}
void SqeListPopBack(SL *ps, SQDataType x)
{
}
void SeqListPopFornt(SL *ps, SQDataType x)
{
}
