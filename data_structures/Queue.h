/*
 * Queue.h
 *
 *  Created on: Mar 11, 2019
 *      Author: SawyerPC
 */

#ifndef DATA_STRUCTURES_QUEUE_H_
#define DATA_STRUCTURES_QUEUE_H_

#include "LinkedList.h"
#include "stdbool.h"

typedef LinkedList* Queue;

void queueEnqueue(Queue q, void* item);
void* queueDequeue(Queue q);
bool queueEmpty(Queue q);
void testQueue();

#endif /* DATA_STRUCTURES_QUEUE_H_ */
