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
void appendData(LinkedList* root, void* data);
void printList(LinkedList* root);
void testList();

#endif /* DATA_STRUCTURES_LINKEDLIST_H_ */
