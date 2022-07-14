#include "list.h"

void ListInit(List *ls)
{
    ls->length = 0;
    ls->capcity = cap;
    ls->data = (elemtype *)malloc(cap * sizeof(elemtype));
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
    ListInit(&ls);
}