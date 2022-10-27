// #include <stdio.h>
// #define PRINT(val, format) printf("the value of "#val" is " format "\n", val)
// #val 是特殊用法 会把变量名字写到这
// int main()
// {
    // printf("__FILE__:%s", __FILE__);
    // printf("__DATE__:%s", __DATE__);
    // printf("__LINE__:%d", __LINE__);
    // printf("__TIME__:%s", __TIME__);
    // printf("hello"  "world");
//     int a = 10;
//     PRINT(a, "%d");
// }

// bug .C:2:67: error: unable to find string literal operator 'operator""format' with 'const char [20]', 'long long unsigned int' arguments
//  #define PRINT(val, format) printf("the value of "#val" is "format "\n", val)
// 问题:看到网上说是C++11要求，当字符串跟变量连接的时候，必须format前后增加一个空格才行
// 在format前面加一个空格便可以解决问题
#include <stdio.h>
#define CAT(A, B)  A##B
int main()
{
    int class107 = 100;
    printf("%d\n", CAT(class,107)); 
}