#include "LinkedList.h"

struct ListItem* initList(void* data) {
	struct ListItem* newItem = (struct ListItem*)malloc(sizeof(struct ListItem));
	(*newItem).data = data;
	(*newItem).prev = NULL;
	(*newItem).next = NULL;
	return newItem;
}

struct ListItem* append(struct ListItem* root, void* data) {
	struct ListItem* temp = root;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = initList(data);
	temp->next->prev = root;
	return temp;
}

void printList(struct ListItem* root) {
	struct ListItem* temp = root;
	while (temp != NULL) {
		printf("%d ", (int)temp->data);
		fflush(stdout);
		temp = temp->next;
	}
	printf("\n");
}

void testList() {
	struct ListItem* root = initList((void*)5);
	append(root, (void*)10);
	append(root, (void*)15);
	append(root, (void*)20);
	append(root, (void*) 5);

	printList(root);
}
