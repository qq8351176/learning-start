#include "contact.h"

void menu()
{
    printf("*******************************\n");
    printf("*******************************\n");
    printf("***    1.add    2.del       ***\n");
    printf("***    3.search 4.modify    ***\n");
    printf("***    5.show   6.sort      ***\n");
    printf("***    0.exit               ***\n");
    printf("*******************************\n");
    printf("*******************************\n");
}
void InitContact(struct Contact *pc)
{
    assert(pc);
    pc->sz = 0;
    memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
}

void AddContact(struct Contact *pc)
{
    assert(pc);
    if (pc->sz == 100)
    {
        printf("ͨѶ¼����");
        return;
    }
    printf("����������");
    scanf("%s", pc->data[pc->sz].name);
    printf("�������Ա�");
    scanf("%s", pc->data[pc->sz].sex);
    printf("����������");
    scanf("%d", &pc->data[pc->sz].age);
    printf("�������ַ");
    scanf("%s", pc->data[pc->sz].addr);
    printf("������绰");
    scanf("%s", pc->data[pc->sz].tele);
    pc->sz++;
    printf("����ɹ�");
}

void ShowContact(const struct Contact *pc)
{
    int i = 0;
    printf("%20s\t%5s\t%5s\t%12s\t%30s\t\n", "����", "�Ա�", "����", "�绰", "��ַ");

    for (int i = 0; i < pc->sz; i++)
    {
        printf("%20s\t%5s\t%5d\t%12s\t%30s\t\n",
               pc->data[i].name,
               pc->data[i].sex,
               pc->data[i].age,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

static int FindByName(const struct Contact *pc, char name[])
{
    int i = 0;
    for (int i = 0; i < pc->sz; i++)
    {
        if (!strcmp(pc->data[i].name, name))
            return i;
    }
    return -1;
}

void DelContact(struct Contact *pc)
{
    char name[MAX_NAME];
    printf("������Ҫɾ���˵�����");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
    {
        printf("Ҫɾ���˵Ĳ�����\n");
    }
    else
    {
        for (int j = ret; j < pc->sz - 1; j++)
        {
            pc->data[j] = pc->data[j + 1];
        }
    }
    pc->sz--;
}

void search(const struct Contact *pc)
{
    char name[MAX_NAME];
    printf("������Ҫ�����˵�����:");
    scanf("%s", name);
    int ret = FindByName(pc, name);
}

void modify(struct Contact *pc)
{
    char name[MAX_NAME];
    printf("������Ҫ�޸��˵�����");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
        printf("�޸ĵ��˲�����");
    else
    {
        printf("����������");
        scanf("%s", pc->data[ret].name);
        printf("�������Ա�");
        scanf("%s", pc->data[ret].sex);
        printf("����������");
        scanf("%d", &pc->data[ret].age);
        printf("�������ַ");
        scanf("%s", pc->data[ret].addr);
        printf("������绰");
        scanf("%s", pc->data[ret].tele);
        printf("����ɹ�");
    }
}

int cmpByAge(const void *e1, const void *e2)
{
    return ((struct PeoInfo *)e1)->age - ((struct PeoInfo *)e2)->age;
}

void SortContact(struct Contact *pc)
{
    qsort(pc->data, pc->sz, sizeof(struct PeoInfo), cmpByAge);
}