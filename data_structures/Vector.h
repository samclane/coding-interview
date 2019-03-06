/*
 * Vector.h
 *
 *  Created on: Mar 6, 2019
 *      Author: SawyerPC
 */

#ifndef DATA_STRUCTURES_VECTOR_H_
#define DATA_STRUCTURES_VECTOR_H_

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INIT_CAPACITY 4

typedef struct vector {
	void **items;
	int capacity;
	int total;
} vector;

void vectorInit(vector *);
int vectorTotal(vector *);
static void vectorResize(vector *, int index);
void vectorAdd(vector* v, void *item);
void vectorSet(vector* v, int index, void * item);
void* vectorGet(vector*v, int index);
void vectorDelete(vector*v, int index);
void vectorFree(vector*v);

void testVectors();

#endif /* DATA_STRUCTURES_VECTOR_H_ */
