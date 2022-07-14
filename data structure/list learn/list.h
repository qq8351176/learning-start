#pragma once

//1.导入头文件 有stdio.h这个头文件才可以用printf
//stdlib可以用 malloc relloc
#include <stdio.h>
#include <stdlib.h>

//宏定义 编译器会把maxsize 自动修正成10
// #define maxsize 10
#define cap 10
//typedef 就是定义变量类型
//typedef int elemtype  类似宏定义
//编译器看到elemtype 就会把它变成int
typedef int elemtype;

//我们不是有 int float double char 
//struct List 里边包含了 elemtype data[] 和一个int
typedef struct 
{
    elemtype* data;
    int length,capcity;
}List;
