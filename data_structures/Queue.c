#include "Queue.h"

void queueEnqueue(Queue q, void* item) {
	appendData(q, item);
}

void* queueDequeue(Queue q) {
	void* item = q->head->next->data;
	ListItem* temp = q->head->next;
	free(q->head);
	q->head = temp;
	q->head->data = NULL;
	return item;
}

bool queueEmpty(Queue q) {
	return q->head->next == q->tail;
}

void testQueue() {
	Queue testQueue = initList();
	printf(queueEmpty(testQueue)? "Empty\n" : "Not Empty\n");
	queueEnqueue(testQueue, (void*)15);
	queueEnqueue(testQueue, (void*)125);
	queueEnqueue(testQueue, (void*)300);
	printList(testQueue);
	printf(queueEmpty(testQueue)? "Empty\n" : "Not Empty\n");
	printf("Removed %d\n", (int)queueDequeue(testQueue));
	printf("Removed %d\n", (int)queueDequeue(testQueue));
	printList(testQueue);
	printf("Removed %d\n", (int)queueDequeue(testQueue));
	printf(queueEmpty(testQueue)? "Empty\n" : "Not Empty\n");
	fflush(stdout);
}
