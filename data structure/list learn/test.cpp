#include "list.h"

void ListInit(List *ls)
{
    for (int i = 0; i < 5; i++)
    {
        ls->data[i] = i;
        ls->length++;
    }
    return;
}

void ListPrint(List ls)
{
    for (int i = 0; i < ls.length; i++)
    {
        printf("%d ", ls.data[i]);
    }
}
bool Empty(List ls)
{
    if (ls.length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int ListlLength(List ls)
{
    return ls.length;
}
int main()
{

    List ls;
    ls.length = 0;
    // if (Empty(ls))
    // {
    //     printf("Empty List");
    // }
    // printf("%d", ListlLength(ls));
    ListInit(&ls);
    printf("%d", ListlLength(ls));

    // ListPrint(ls);
}