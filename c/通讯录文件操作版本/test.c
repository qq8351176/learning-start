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
        printf("�����������:");
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
            SaveContent(&con);
            DestoryContact(&con);
            printf("�˳�ͨѶ¼:");
            break;
        default:
            printf("ѡ�����");

            break;
        }
    } while (input != 0);
}