/*
 * Vector.h
 *
 *  Created on: Mar 6, 2019
 *      Author: SawyerPC
 *
 *  Original code found https://eddmann.com/posts/implementing-a-dynamic-vector-array-in-c/
 */

#ifndef DATA_STRUCTURES_VECTOR_H_
#define DATA_STRUCTURES_VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define VECTOR_INIT_CAPACITY 4
#define DEBUG_ON

typedef struct vector {
	void **items;
	int capacity;
	int total;
} vector;

void vectorInit(vector* v);
int vectorTotal(vector* v);
void vectorAdd(vector* v, void *item);
void vectorSet(vector* v, int index, void * item);
void vectorInsert(vector* v, int index, void* item);
void* vectorGet(vector*v, int index);
void vectorDelete(vector* v, int index);
void vectorFree(vector* v);
bool vectorIsEmpty(vector* v);

void testVectors();

#endif /* DATA_STRUCTURES_VECTOR_H_ */
