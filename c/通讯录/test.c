#include "contact.c"
int main()
{
    int input = 0;
    struct Contact con;
    InitContact(&con);
    do
    {
        menu();
        printf("�����������:");
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
            printf("�˳�ͨѶ¼");
            break;
        default:
            printf("ѡ�����");

            break;
        }
    } while (input != 0);
}