#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;


TreeNode* createNode(char data)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void preorder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
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

	printf("전위 순회: ");
	preorder(A);
	printf("\n");

	printf("중위 순회: ");
	inorder(A);
	printf("\n");

	printf("후위 순회: ");
	postorder(A);
	printf("\n");

	return 0;
}