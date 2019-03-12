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

struct LinkedList {
	struct ListItem* head;
	struct ListItem* tail;
};


struct ListItem {
	void* data;
	struct ListItem* next;
	struct ListItem* prev;
};

struct LinkedList* initList();
struct ListItem* initItem();
void appendData(struct LinkedList* root, void* data);
void printList(struct LinkedList* root);
void testList();

#endif /* DATA_STRUCTURES_LINKEDLIST_H_ */
