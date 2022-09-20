#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TALE 12
#define MAX_ADDR 30

//表示一个人的信息
struct PeoInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TALE];
    int age;
    char addr[MAX_ADDR];
};

struct Contact
{
    struct PeoInfo data[MAX];
    int sz;
};

//通讯录的初始化
void InitContact(struct Contact *pc);

//通讯录的信息的增加
void AddContact(struct Contact *pc);

//显示通讯录中的信息
void ShowContact(const struct Contact *pc);

//删除信息
void DelContact(struct Contact* pc);

//查找信息
void search(const struct Contact* pc);

//修改信息
void modify(struct Contact* pc);

//按照年龄排序信息
void SortContact(struct Contact * pc);