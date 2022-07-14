#include "SeqList.h"

int main()
{
    SL ps;
    SeqListInit(&ps);
    int option = 0;
    int x = 0;
    while (option != -1)
    {
        menu();
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            do
            {
                printf("请输入要插入的数据，以-1结束\n");
                scanf("%d", &x);
                if (x != -1)
                {
                    SeqListPushBack(&ps, x);
                }
            } while (x != -1);

            break;
        case 2:
            do
            {
                printf("请输入要插入的数据，以-1结束\n");
                scanf("%d", &x);
                if (x != -1)
                {
                    SeqListPushFront(&ps, x);
                }
            } while (x != -1);

            break;
        case 3:

            SqeListPopBack(&ps);

            break;
        case 4:

            SeqListPopFornt(&ps);

            break;
        case 5:
            SeqListPrint(&ps);
            break;

        default:
            break;
        }
    }
}
void menu()
{
    printf("*************************************\n");
    printf("1.尾插数据，2.头插数据\n");
    printf("3.尾删数据，4.头删数据\n");
    printf("5.打印数据，-1.退出\n");
    printf("*************************************\n");
    printf("请输入你操作选项\n");
}
void SeqListInit(SL *ps)
{
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = N;
    return;
}
void SeqListPrint(SL *ps)
{
    if (ps->a == NULL)
    {
        printf("表不存在诶");
    }
    else
    {
        for (int i = 0; i < ps->size; i++)
        {
            printf("%d ", ps->a[i]);
        }
    }

    printf("\n");
}
void SeqListPushBack(SL *ps, SQDataType x)
{
    if (ps->a == NULL)
    {
        ps->a = (SQDataType *)malloc(10 * sizeof(SQDataType));
    }
    SeqListCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}
void SeqListPushFront(SL *ps, SQDataType x)
{
    SeqListCapacity(ps);
    int end = ps->size - 1;
    while (end >= 0)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    ps->a[0] = x;
    ps->size++;
}
void SqeListPopBack(SL *ps)
{
    assert(ps->size > 0);
    ps->size--;
}
void SeqListPopFornt(SL *ps)
{
    assert(ps->size > 0);
    ps->a[0] = 0;
    for (int i = 0; i < ps->size; i++)
    {
        ps->a[i] = ps->a[i + 1];
    }
    ps->size--;
}
void SeqListCapacity(SL *ps)
{
    if (ps->size >= ps->capacity)
    {
        printf("顺序表已经满啦,扩容");
        SQDataType *tmp = realloc(ps->a, ps->capacity * 2 * sizeof(SQDataType));
        if (tmp == NULL)
        {
            printf("relloc fail\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity = ps->capacity * 2;
        }
    }
}
void SeqListInsert(SL *ps, int pos, SQDataType x)
{
    assert(pos < ps->size);
    SeqListCapacity(ps);
    int end = ps->size - 1;
    while (end >= pos)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}
void SeqListEarse(SL *ps, int pos)
{
    assert(pos < ps->size);
    while (pos < ps->size)
    {
        ps->a[pos] = ps->a[pos + 1];
        pos++;
    }
    ps->size--;
}
void SeqListDestory(SL *ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->size = 0;
}
int SeqListFound(SL *ps, SQDataType x)
{
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x)
        {
            return i + 1;
        }
    }
    return -1;
}
void SeqListModify(SL *ps, int pos, SQDataType x)
{
    assert(pos < ps->size);
    ps->a[pos - 1] = x;
}