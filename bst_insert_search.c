#include <stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* createNode(int key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}

TreeNode* insertBST(TreeNode* root,int key)
{
	if (root == NULL)
		return createNode(key);

	if (key < root->key)
		root->left = insertBST(root->left, key);
	else if (key > root->key)
		root->right = insertBST(root->right, key);

	return root;	
}


TreeNode* searchBST(TreeNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	else if (key < root->key)
		return searchBST(root->left, key);
	else if (key > root->key)
		return searchBST(root->right, key);
}


int main() {
	TreeNode* root = NULL;

	int data[] = { 30, 20, 40, 10, 25 };

	for (int i = 0; i <5; i++)
		root = insertBST(root, data[i]);

	int target = 25;
	if (searchBST(root, target))
		printf("%d : 찾았습니다\n", target);
	else
		printf("%d : 존재하지 않습니다\n", target);

	target = 50;
	if (searchBST(root, target))
		printf("%d : 찾았습니다\n", target);
	else
		printf("%d : 존재하지 않습니다\n", target);

	return 0;
}