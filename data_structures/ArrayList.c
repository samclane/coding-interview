#include "ArrayList.h"

const size_t ARRAY_LIST_CHUNK_SIZE = 64;

ArrayListPtr arrayListCreateWithParentAndChunkSize(ArrayListPtr parent, size_t chunk_size) {
	ArrayListPtr result = (ArrayListPtr)calloc(sizeof(ArrayList), 1);
	result->parent = parent;
	result->capacity = chunk_size;
	result->data = (int*)malloc(sizeof(int) * chunk_size);
	return result;
}

ArrayListPtr arrayListCreateWithParent(ArrayListPtr parent) {
	return arrayListCreateWithParentAndChunkSize(parent, ARRAY_LIST_CHUNK_SIZE);
}

ArrayListPtr arrayListCreate() {
	return arrayListCreateWithParentAndChunkSize(NULL, ARRAY_LIST_CHUNK_SIZE);
}

void arrayListPushBack(ArrayListPtr list, int value) {
	if (list->size >= list->capacity) {
		if (!list->child) {
			list->child = arrayListCreateWithParent(list);
		}
		arrayListPushBack(list->child, value);
	}
	else {
		list->data[list->size++] = value;
	}
}

int* arrayListGetValueByIndex(ArrayListPtr list, size_t index) {
	if (index >= list->capacity || index > list->size) {
		if (list->child) {
			return arrayListGetValueByIndex(list->child, index - list->size);
		}
		else
			return NULL;
	}
	return list->data + index;
}

void testArrays() {
	ArrayListPtr list = arrayListCreate();
	for (int i = 0l; i < 100*1000; ++i)
		arrayListPushBack(list ,i);
	size_t test[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,31,32,33,63,64,65,999,1000};
	for (int i = 0; i < sizeof(test) / sizeof(size_t); ++i) {
		int * result = arrayListGetValueByIndex(list, test[i]);
		if (result)
			printf("list[%u]  = %d\n", test[i], *result);
		else
			printf("Can't get value by index %u\n", test[i]);
	}
}
