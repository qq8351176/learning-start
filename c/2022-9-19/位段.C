#include<stdio.h>
//位段的应用 网络数据的封装涉及到位段
//位段的跨平台性能不好
struct s
{
    /* data */
    char a : 3;
    char b : 4;
    char c : 5;
    char d : 4;
};

int main()
{
    printf("%d\n",sizeof(struct s));
    struct s S;
    S.a = 10;
    S.b = 12;
    S.c = 3;
    S.d = 4;
    return 0;
}
// struct s
// {
//     int a;
//     int b;
//     int c;
//     int d;

// };
// //位段 是 二进制位
// struct b
// {
//     int _a:2;
//     int _b:5;
//     int _c:10;
//     int _d:30;
// };
// int main()
// {
//     printf("%d\n",sizeof(struct s));
//     printf("%d\n",sizeof(struct b));

// }