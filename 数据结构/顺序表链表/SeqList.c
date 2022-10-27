#include "SeqList.h"

void SLInit(SL* s)
{
	s->a = NULL;
	s->size = 0;
	s->capacity = 0;
}

void SLDestory(SL* ps)
{
	assert(ps);

	// 温柔的检查
	/*if (ps->size == 0)
	{
	return;
	}*/

	// 暴力的检查
	assert(ps->size > 0);

	//ps->a[ps->size - 1] = 0;
	ps->size--;

}

void SLPushBack(SL* ps, SLDataType x)
{
	if (ps->size == ps->capacity)
	{	

		int newcapacity = ps->capacity ? 0 : ps->capacity * 2;
		SLDataType* tmp = realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->size] = x;
	ps->size++;  
}; 

void SLPrintf(SL* ps)
{
	assert(ps);
	for (int  i = 0; i < ps->size ; ++i)
	{
		printf("%d ", ps->a[i]);
	}
}

void SLPopBack(SL* ps)
{
	assert(ps);

	//if (ps->a != NULL)
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}

}
