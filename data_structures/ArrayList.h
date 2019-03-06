/*
 * ArrayList.h
 *
 *  Created on: Mar 6, 2019
 *      Author: SawyerPC
 *  Based on: https://codereview.stackexchange.com/questions/64423/implementing-an-arraylist
 */

#ifndef DATA_STRUCTURES_ARRAYLIST_H_
#define DATA_STRUCTURES_ARRAYLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList ArrayList;
typedef ArrayList* ArrayListPtr;

struct ArrayList {
	size_t capacity;
	size_t size;
	int *data;
	ArrayListPtr parent;
	ArrayListPtr child;
};

ArrayListPtr arrayListCreateWithParentAndChunkSize(ArrayListPtr parent, size_t chunk_size);
ArrayListPtr arrayListCreateWithParent(ArrayListPtr parent);
ArrayListPtr arrayListCreate();

void arrayListPushBack(ArrayListPtr list, int value);
int* arrayListGetValueByIndex(ArrayListPtr list, size_t index);
void testArrays();

#endif /* DATA_STRUCTURES_ARRAYLIST_H_ */
