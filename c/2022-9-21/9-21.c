#include <stdio.h>
// // 鏋氫妇鐨勪紭鐐? 澧炲姞浠ｇ爜鐨勫彲缁存姢鎬? 鍜屽彲璇绘�?
// // 鏂逛究璋冭瘯
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
//     // int sum = BLUE + GREEN;//c涓嶄細鍑洪敊 C++姣旇緝涓ユ牸鍙兘鍑洪敊
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
//         printf("大端");
//     }
//     else
//     {
//         printf("小端");
//     }
// }

//联合体的大小
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
                                    //联合体也有对齐数   char arr 五字节 int 四字节 所以对齐后为8字节
                                    //最大成员不是最大对起数的整数倍的时候 就要对齐到最大对起数
    printf("%d", sizeof(union un_1)); // 8
}