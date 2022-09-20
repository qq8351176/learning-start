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
        printf("通讯录满了");
        return;
    }
    printf("请输入名字");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入性别");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入年龄");
    scanf("%d", &pc->data[pc->sz].age);
    printf("请输入地址");
    scanf("%s", pc->data[pc->sz].addr);
    printf("请输入电话");
    scanf("%s", pc->data[pc->sz].tele);
    pc->sz++;
    printf("输入成功");
}

void ShowContact(const struct Contact *pc)
{
    int i = 0;
    printf("%20s\t%5s\t%5s\t%12s\t%30s\t\n", "姓名", "性别", "年龄", "电话", "地址");

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
    printf("请输入要删除人的名字");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
    {
        printf("要删除人的不存在\n");
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
    printf("请输入要查找人的名字:");
    scanf("%s", name);
    int ret = FindByName(pc, name);
}

void modify(struct Contact *pc)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字");
    scanf("%s", name);
    int ret = FindByName(pc, name);
    if (ret == -1)
        printf("修改的人不存在");
    else
    {
        printf("请输入名字");
        scanf("%s", pc->data[ret].name);
        printf("请输入性别");
        scanf("%s", pc->data[ret].sex);
        printf("请输入年龄");
        scanf("%d", &pc->data[ret].age);
        printf("请输入地址");
        scanf("%s", pc->data[ret].addr);
        printf("请输入电话");
        scanf("%s", pc->data[ret].tele);
        printf("输入成功");
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