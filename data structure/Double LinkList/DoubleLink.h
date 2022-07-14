#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//
typedef int elemtype;
typedef struct DLink
{
    elemtype data;
    struct DLink *prev;
    struct DLink *next;
}DList;
