#pragma once

#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;
typedef struct 
{
   STDataType* a;
   int top;
   int capacity;
}Stack;

