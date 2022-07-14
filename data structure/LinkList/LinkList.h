#pragma once
#include<stdio.h>
#include<stdlib.h>

//此例子为 带头双向循环链表

//单向 双向
//带头 不带头
//循环 不循环
typedef int elemtype;

struct LinkList
{
    elemtype data;
    struct LinkList* next;
};
typedef struct  LinkList LinkList;
