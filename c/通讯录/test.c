#include "contact.c"
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
        case 1:
            AddContact(&con);
            break;
        case 2:
            DelContact(&con);
            break;
        case 3:
            search(&con);
            break;
        case 4:
            modify(&con);
            break;
        case 5:
            ShowContact(&con);
            break;
        case 6:
            SortContact(&con);
            break;
        case 0:
            printf("退出通讯录");
            break;
        default:
            printf("选择错误");

            break;
        }
    } while (input != 0);
}