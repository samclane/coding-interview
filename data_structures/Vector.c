#include "Vector.h"

void vectorInit(vector *v) {
	v->capacity = VECTOR_INIT_CAPACITY;
	v->total = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}

int vectorTotal(vector *v) {
	return v->total;
}

static void vectorResize(vector *v, int capacity) {
#ifdef DEBUG_ON
	printf("vectorResize: %d to %d\n", v->capacity, capacity);
#endif

	void **items = realloc(v->items, sizeof(void*) * capacity);
	if (items) {
		v->items = items;
		v->capacity = capacity;
	}
}

void vectorAdd(vector*v, void *item) {
	if (v->capacity == v->total)
		vectorResize(v, v->capacity * 2);
	v->items[v->total++] = item;
}

void vectorSet(vector*v, int index, void *item) {
	if (index >= 0 && index < v->total)
		v->items[index] = item;
}

void vectorInsert(vector* v, int index, void* item){
	int i;
	if (index >= 0 && index < v->total) {
		if (v->capacity == v->total)
			vectorResize(v, v->capacity * 2);
		for(i=v->total-1;i>=index;i--) {
			v->items[i+1] = v->items[i];
		}
		v->items[index] = item;
		v->total++;
	}
}

void* vectorGet(vector*v, int index) {
	if (index >= 0 && index < v->total)
			return v->items[index];
	return NULL;
}

void vectorDelete(vector*v, int index) {
	if (index < 0 || index >= v->total)
		return;

	v->items[index] = NULL;

	for (int i = index; i < v->total - 1; i++) {
		v->items[i] = v->items[i+1];
		v->items[i+1] = NULL;
	}

	v->total--;

	if (v->total > 0 && v->total == v->capacity / 4)
		vectorResize(v, v->capacity / 2);
}

void vectorFree(vector*v) {
	free(v->items);
}

bool vectorIsEmpty(vector* v) {
	return (v->total == 1);
}


void testVectors() {
	int i;

	vector v;
	vectorInit(&v);

	vectorAdd(&v, "Bonjour");
	vectorAdd(&v, "tout");
	vectorAdd(&v, "le");
	vectorAdd(&v, "monde");

	for (i=0; i<vectorTotal(&v);i++) {
		printf("%s ", (char*) vectorGet(&v, i));
	}
	printf("\n");

	vectorInsert(&v, 2, "TEST");

	for (i=0; i<vectorTotal(&v);i++) {
		printf("%s ", (char*) vectorGet(&v, i));
	}
	printf("\n");

	vectorDelete(&v, 4);
	vectorDelete(&v, 3);
	vectorDelete(&v, 2);
	vectorDelete(&v, 1);

	assert(vectorIsEmpty(&v));

	vectorSet(&v, 0, "Hello");
	vectorAdd(&v, "World");

	for (i=0;i<vectorTotal(&v);i++)
		printf("%s ", (char*) vectorGet(&v, i));
	printf("\n");
	vectorFree(&v);
}
