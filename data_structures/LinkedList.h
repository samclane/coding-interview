/*
 * LinkedList.h
 *
 *  Created on: Mar 7, 2019
 *      Author: SawyerPC
 */

#ifndef DATA_STRUCTURES_LINKEDLIST_H_
#define DATA_STRUCTURES_LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListItem {
	void* data;
	struct ListItem* next;
}ListItem;

typedef struct LinkedList {
	ListItem* head;
	ListItem* tail;
}LinkedList;

LinkedList* initList();
ListItem* initItem();
void appendData(LinkedList* list, void* data);
int size(LinkedList* list);
void printList(LinkedList* list);
void testList();

#endif /* DATA_STRUCTURES_LINKEDLIST_H_ */
