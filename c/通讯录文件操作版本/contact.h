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
#define DEFAULT_SZ 3
#define INC_SZ 2

//��ʾһ���˵���Ϣ
struct PeoInfo
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tele[MAX_TALE];
    int age;
    char addr[MAX_ADDR];
};

// �ϰ汾
// ��̬�İ汾
// struct Contact
// {
//     struct PeoInfo data[MAX];
//     int sz;
// };


// �°汾
struct Contact
{
    struct PeoInfo *data;
    int sz;
    int capacity;//����
};

//ͨѶ¼�ĳ�ʼ��
void InitContact(struct Contact *pc);

//ͨѶ¼����Ϣ������
void AddContact(struct Contact *pc);

//��ʾͨѶ¼�е���Ϣ
void ShowContact(const struct Contact *pc);

//ɾ����Ϣ
void DelContact(struct Contact* pc);

//������Ϣ
void search(const struct Contact* pc);

//�޸���Ϣ
void modify(struct Contact* pc);

//��������������Ϣ
void SortContact(struct Contact * pc);

//����ͨѶ¼
void DestoryContact(struct Contact * pc);

// ����
void SaveContent(struct Contact *pc);

// ����
void LoadContact(struct Contact *pc);