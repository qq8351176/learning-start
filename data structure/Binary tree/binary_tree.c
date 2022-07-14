#include "binary_tree.h"

void PrevOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("null ");
        return;
    }
    printf("%d ", root->data);
    PrevOrder(root->left);
    PrevOrder(root->right);
}
void PostOrder(BTNode *root)
{
    if (root == NULL)
    {
        printf("null ");
        return;
    }
    printf("%d ", root->data);
    PostOrder(root->right);
    PostOrder(root->left);
}
void InOrder(BTNode *root)
{

    if (root == NULL)
    {
        printf("null ");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}
int TreeSize(BTNode *root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode *root)
{
    if (root->right == NULL && root->left == NULL)
    {
        return 1;
    }
    if (root == NULL)
    {
        return 0;
    }
    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int main()
{
    BTNode *A = (BTNode *)malloc(sizeof(BTNode));
    A->data = 1;
    A->left = NULL;
    A->right = NULL;
    BTNode *B = (BTNode *)malloc(sizeof(BTNode));
    B->data = 2;
    B->left = NULL;
    B->right = NULL;
    BTNode *C = (BTNode *)malloc(sizeof(BTNode));
    C->data = 3;
    C->left = NULL;
    C->right = NULL;
    BTNode *D = (BTNode *)malloc(sizeof(BTNode));
    D->data = 4;
    D->left = NULL;
    D->right = NULL;
    BTNode *E = (BTNode *)malloc(sizeof(BTNode));
    E->data = 5;
    E->left = NULL;
    E->right = NULL;
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    PrevOrder(A);
    printf("\n");
    PostOrder(A);
    printf("\n");
    InOrder(A);
    printf("\n");
    printf("%d", TreeSize(A));
    printf("\n");
    printf("%d", TreeLeafSize(A));
}
