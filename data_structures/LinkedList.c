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

int size(LinkedList* list) {
	ListItem* temp = list->head->next;
	int count = 0;
	while (temp != list->tail) {
		temp = temp->next;
		count++;
	}
	return count;
}

void printList(LinkedList* list) {
	ListItem* temp = list->head->next;
	while (temp != list->tail) {
		printf("%d ", (int)temp->data);
		fflush(stdout);
		temp = temp->next;
	}
	printf("\n");
}

void testList() {
	printf("Starting 'testList'...\n");
	LinkedList* root = initList();
	for(int i=0;i<500;i++)
		appendData(root, (void*)i);

	printList(root);
	printf("Size: %d\n", size(root));
	printf("'testList' finished!\n");
}
