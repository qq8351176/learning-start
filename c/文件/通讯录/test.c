#include "contact.c"
enum option
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};
int main()
{
    int input = 0;
    struct Contact con;
    InitContact(&con);
    do
    {
        menu();
        printf("请输入操作数:");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            search(&con);
            break;
        case MODIFY:
            modify(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            DestoryContact(&con);
            printf("退出通讯�?");
            break;
        default:
            printf("选择错误");

            break;
        }
    } while (input != 0);
}