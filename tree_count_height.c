#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int countNodes(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

int getHeight(TreeNode* root)
{
    if (root == NULL)
        return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

int main()
{

    TreeNode* A = createNode('A');
    TreeNode* B = createNode('B');
    TreeNode* C = createNode('C');
    TreeNode* D = createNode('D');
    TreeNode* E = createNode('E');
    TreeNode* F = createNode('F');

    A->left = B;
    A->right = C;
    B->left = D;
    C->left = E;
    C->right = F;

    printf("노드 개수: %d\n", countNodes(A));
    printf("트리 높이: %d\n", getHeight(A));

    return 0;
}