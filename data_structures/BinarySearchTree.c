#include "BinarySearchTree.h"

struct Node* GetNewNode(void* data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
struct Node* Insert(struct Node* root, void* data) {
	if (root == NULL) {
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

bool Search(struct Node* root, void* data) {
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root-> data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}

void testBST() {
	struct Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 8);

	int number;
	printf("Search: ");
	fflush(stdout);
	scanf("%d", &number);
	if (Search(root, number) == true)
		printf("Found\n");
	else
		printf("Not found\n");
}
