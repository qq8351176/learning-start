#include <stdio.h>
// // 枚举的优�? 增加代码的可维护�? 和可读�?
// // 方便调试
// // #define RED 5
// // #define GREEN 7
// // #define BLUE 10
// enum Color
// {
//     RED = 5,
//     GREEN = 7,
//     BLUE = 10,
// };
// int main()
// {
//     // enum Color color = BLUE;
//     // printf("%d",color);
//     // int sum = BLUE + GREEN;//c不会出错 C++比较严格可能出错
//     // printf("%d",sum);
//     printf("%d", sizeof(enum Color));
//     return 0;
// }
// #include <stdio.h>
// union un
// {
//     char c;
//     int i;
//     double b;
// };
// int main()
// {
//     union un U;
//     // U.c = '1';
//     U.i = 1;
//     // U.b = 1.0;
//     // printf("%d\n", sizeof(union un));
//     // printf("%d\n", U.c);
//     printf("%d\n", U.i);
//     // printf("%d\n", U.b);
// }

// int check_sys()
// {
//     union UN
//     {
//         char c;
//         int i;
//     }U;
//     U.i=1;
//     return U.c;
// }
// int main()
// {
//     int ret = check_sys();
//     if (ret == 1)
//     {
//         printf("���");
//     }
//     else
//     {
//         printf("С��");
//     }
// }

//������Ĵ�С
union un
{
    int i;
    char arr[5];
};
union un_1
{
    int i;
    short s[7];
};
int main()
{
    // printf("%d", sizeof(union un)); // 8
                                    //������Ҳ�ж�����   char arr ���ֽ� int ���ֽ� ���Զ����Ϊ8�ֽ�
                                    //����Ա����������������������ʱ�� ��Ҫ���뵽��������
    printf("%d", sizeof(union un_1)); // 8
}