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


struct ListItem {
	void* data;
	struct ListItem* prev;
	struct ListItem* next;
};

void printList(struct ListItem* root);

#endif /* DATA_STRUCTURES_LINKEDLIST_H_ */
