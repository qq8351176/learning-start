#include "Heap.h"

void test()
{
	int array[] = { 25,15,19,18,28,34,65,49,27,37 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		HeapPush(&hp, array[i]);
	}
	HeapPrint(&hp);

	int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HPDestorty(&hp);
}
void test1()
{
	int array[] = { 25,15,19,18,28,34,65,49,27,37 };
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		HeapPush(&hp, array[i]);
	}
	HeapPrint(&hp);

	int k = 5;
	while (k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HPDestorty(&hp);
}

void test2()
{
	int array[] = { 15,18,19,25,28,34,65,49,27,37 };
	HP hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(int));

	HeapPrint(&hp);

	HPDestorty(&hp);
}
//建立堆有两种方式
void HeapSort(int* a, int n)
{
	//以下为建堆的方式 并非 排序的方式
	//向上调整建堆 时间复杂度 : 
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a,i);
	//}

	//向下调整建堆
	//先建立好堆 也可以弄到循环里
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

}

void test3()
{
	int array[] = { 25,15,19,18,28,34,65,49,27,37 };
	HeapSort(array, sizeof(array) / sizeof(int));
	for (size_t i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		printf("%d ", array[i]);
	}
}

void test4()
{
	int MinHeap[5];
	FILE* fout = fopen("Data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	int k = 5;
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &MinHeap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(MinHeap, k, i);
	}
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > MinHeap[0])
		{
			MinHeap[0] = val;
			AdjustDown(MinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", MinHeap[i]);
	}
	fclose(fout);

}
void test5()
{
	int n = 10000;
	int k = 5;
	int* MinHeap = (int*)malloc(sizeof(int) * k);
	srand(time(0));
	FILE* fin = fopen("Data.txt", "w");
	FILE* fout = fopen("Data.txt", "r");

	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int val = rand();
		fprintf(fin, "%d\n", val);
	}
	fclose(fin);
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &MinHeap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(MinHeap, k, i);
	}
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > MinHeap[0])
		{
			MinHeap[0] = val;
			AdjustDown(MinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", MinHeap[i]);
	}
	fclose(fout);
}

typedef int BTDataType;
typedef struct BinaryTreeNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
#include  "queue.h"
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);

}
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTDataType*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else return 	TreeSize(root->left)+TreeSize(root->right)+1;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left ||root->right) return 	TreeSize(root->left) + TreeSize(root->right) + 1;
	else if (!root->left && !root->right) return 1;
	else return 0;
}

int TreeHeight(BTNode* root) 
{
	if (root == NULL)
	{
		return 0;
	}
	//return max(TreeHeight(root->right), TreeHeight(root->left))+1;
	//return TreeHeight(root->left) > TreeHeight(root->right) ? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//求第k层的节点个数
int TreekLevelSize(BTNode * root, int k)
{
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return TreekLevelSize(root->left, k - 1) + TreekLevelSize(root->right, k - 1);

}

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	//return TreeFind(root->left, x) || TreeFind(root->right, x);
	//两个指针不能够相互与或

	//这种写法在某些编译器下可能报错 不是每一个路径都有返回值
	//TreeFind(root->left, x);
	//TreeFind(root->right, x);

	BTNode* left = TreeFind(root->left, x);
	BTNode* right = TreeFind(root->right, x);
	if (left != NULL)
	{
		return left;
	}
	if (right != NULL)
	{
		return right;
	}
}



void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d", front->data);
		QueuePop(&q);
		if (front->left) {
			QueuePush(&q, front->left);
		}
		if (front->right) {
			QueuePush(&q, front->right);
		}

	}
	printf("\n");

	QueueDestory(&q);
}

bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	QueueDestory(&q);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	

	// 出到空以后， 如果后面全是空的话 则是一个完全的二叉树 否则不是

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
		{
			QueueDestory(&q);
			return false;
		}
	}
	
	QueueDestory(&q);
	return true;
}

void TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
}
int main()
{
	BTNode* root;
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);
	n1->left = n2;
	n2->left = n3;
	n1->right = n4;
	n4->left = n5;
	n4->right = n6;
	n3->left = n7;

	root = n1;
	//PostOrder(root);

	
	//printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	//printf("TreeHeight:%d\n", TreeHeight(root));
	//printf("TreekLevelSize(3):%d\n", TreekLevelSize(root, 3));

	//printf("TreeFind(3):%p\n", TreeFind(root, 3));

	//printf("n3:%p\n", n3);

	LevelOrder(root);
	return 0;
}
