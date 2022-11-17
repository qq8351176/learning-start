#include "queue.h"


void TestQueue1()
{
	Queue q1;

	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	QueuePush(&q1, 5);

	//printf("%d\n",QueueSize(&q1));
	//printf("%d\n", QueueEmpty(&q1));
	//printf("%d\n",QueueFront(&q1));
	//printf("%d\n", QueueBack(&q1));
	while (!QueueEmpty(&q1))
	{
		printf("%d\n", QueueFront(&q1));
		QueuePop(&q1);
	}
	printf("%d\n", QueueEmpty(&q1));
	printf("%d\n", QueueSize(&q1));
	printf("%d\n", QueueBack(&q1));
	QueueDestory(&q1);


}

void TestQueue()
{
	Queue q1;
	Queue q2;
	QueueInit(&q1);
	QueueInit(&q2);

	QueueDestory(&q1);
	QueueDestory(&q2);

}
int main()
{
	TestQueue1();
	return 0;
}