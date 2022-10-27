#include "SeqList.h"
void TestSqeList1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrintf(&sl);
	SLDestory(&sl );
}
int main()
{
	TestSqeList1();
	return 0;
}