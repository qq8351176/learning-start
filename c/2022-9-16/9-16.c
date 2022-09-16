// 结构体
// 两个一抹一样的匿名结构体 编译器会看成是两个不一样的变量
// 结构体的自引用
#include <stdio.h>
#pragma pack(8)
struct S1
{
 char c1;
 int i;
 char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
#pragma pack(1)//设置默认对齐数为1
struct S2
{
 char c1;
 int i;
 char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
int main()
{
    //输出的结果是什么？
    printf("%d\n", sizeof(struct S1));
    printf("%d\n", sizeof(struct S2));
    return 0;
}
// struct S1
// {
//  char c1;
//  int i;
//  char c2;
// }a;
// struct S2
// {
//  char c1;
//  char c2;
//  int i;
// }b;
// int main()
// {
//     printf("s1:%d s2:%d",sizeof a,sizeof b);
// }
// struct S3
// {
//     /* data */
//     double b;
//     char c;
//     int i;
// };

// struct s4
// {
//     /* data */
//     char c1;
//     struct S3 s3;
//     double b;
    
// }s4;

// int main()
// {
//     printf("%d",sizeof s4);
//     return 0;
// }