#include "BinarySearchTree.h"

Node* GetNewNode(void* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, void* data) {
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

bool Search(Node* root, void* data) {
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root-> data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}

void* FindMin(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty\n");
		return NULL;
	}
	while(root->left != NULL) {
		root = root->left;
	}
	return root->data;
}

void* FindMax(Node* root) {
	if (root == NULL) {
		printf("Error: Tree is empty\n");
		return NULL;
	}
	while(root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

int FindHeight(Node* root) {
	if (root == NULL)
		return -1;
	int leftHeight = FindHeight(root->left);
	int rightHeight = FindHeight(root->right);
	return fmax(leftHeight, rightHeight) + 1;
}

void LevelOrder(Node* root) {
	if (root == NULL)
		return;
}

void testBST() {
	Node* root = NULL; // Create empty tree
	// Insert dummy data
	root = Insert(root, (void*)15);
	root = Insert(root, (void*)10);
	root = Insert(root, (void*)20);
	root = Insert(root, (void*)8);

	// User searches for a number
	int number;
	printf("Search BST: ");
	fflush(stdout);
	scanf("%d", &number);
	if (Search(root, (void*)number) == true)
		printf("Found\n");
	else
		printf("Not found\n");

	printf("BST height: %d\n", FindHeight(root));
}
