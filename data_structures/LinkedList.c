#include "LinkedList.h"

struct LinkedList* initList() {
	struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	(*newList).head = initItem();
	(*newList).tail = (*newList).head;
	return newList;
}

struct ListItem* initItem() {
	struct ListItem* newItem = (struct ListItem*)malloc(sizeof(struct ListItem));
	(*newItem).data = NULL;
	(*newItem).next = NULL;
	(*newItem).prev = NULL;

	return newItem;
}

void appendData(struct LinkedList* list, void* data) {
	list->tail->data = data;
	struct ListItem* newTail = initItem();
	list->tail->next = newTail;
	newTail->prev = list->tail;
	list->tail = newTail;
}

void printList(struct LinkedList* list) {
	struct ListItem* temp = list->head;
	while (temp->data != NULL) {
		printf("%d ", (int)temp->data);
		fflush(stdout);
		temp = temp->next;
	}
	printf("\n");
}

void testList() {
	struct LinkedList* root = initList();
	appendData(root, (void*)20);
	appendData(root, (void*)125);

	printList(root);
}
