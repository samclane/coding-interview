#include "LinkedList.h"

LinkedList* initList() {
	LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
	(*newList).head = initItem();
	(*newList).tail = initItem();
	(*newList).head->next = (*newList).tail;
	return newList;
}

ListItem* initItem() {
	ListItem* newItem = (ListItem*)malloc(sizeof(ListItem));
	(*newItem).data = NULL;
	(*newItem).next = NULL;

	return newItem;
}

void appendData(LinkedList* list, void* data) {
	list->tail->data = data;
	ListItem* newTail = initItem();
	list->tail->next = newTail;
	list->tail = newTail;
}

void printList(LinkedList* list) {
	ListItem* temp = list->head->next;
	while (temp->data != NULL) {
		printf("%d ", (int)temp->data);
		fflush(stdout);
		temp = temp->next;
	}
	printf("\n");
}

void testList() {
	LinkedList* root = initList();
	appendData(root, (void*)20);
	appendData(root, (void*)125);

	printList(root);
}
