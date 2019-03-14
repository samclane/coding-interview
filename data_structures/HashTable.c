#include "HashTable.h"

struct Item* InitItemPtr() {
	struct Item* i = malloc(sizeof(struct Item));
	i->name = "empty";
	i->drink = "empty";
	i->next = NULL;
	return i;
}

HashTable InitHash(const int SIZE) {
	HashTable* t = malloc(sizeof(HashTable));
	t->table = (struct Item**)malloc(SIZE*sizeof(struct Item*));
	t->tableSize = SIZE;
	for (int i = 0; i < SIZE; i++) {
		t->table[i] = InitItemPtr();
	}
	return *t;
}

int Hash(HashTable t, char* key) {
	int hash = 0;
	int index;

	for(int i = 0; i < strlen(key); i++) {
		hash += (int)key[i];
		printf("hash = %d\n", hash);
	}

	index = hash % t.tableSize;

	return index;
}

void AddItem(HashTable t, char* name, char* drink) {
	int index = Hash(t, name);

	if (strcmp(t.table[index]->name, "empty") == 0) {
		t.table[index]->name = name;
		t.table[index]->drink = drink;
	}
	else {
		struct Item* i = t.table[index];
		struct Item* n = calloc(1, sizeof(struct Item));
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while(i->next != NULL) {
			i = i->next;
		}
		i->next = n;
	}
}

int NumberOfItemsInIndex(HashTable t, int index) {
	int count = 0;

	if (strcmp(t.table[index]->name, "empty") == 0) {
		return count;
	}
	else {
		count++;
		struct Item* i = t.table[index];
		while(i->next != NULL) {
			count++;
			i = i->next;
		}
	}
	return count;
}

void PrintTable(HashTable t) {
	int number;
	for(int i = 0; i < t.tableSize; i++) {
		number = NumberOfItemsInIndex(t, i);
		printf("------------------\n");
		printf("index = %d\n", i);
		printf("%s ", t.table[i]->name);
		printf("%s\n", t.table[i]->drink);
		printf("# of items %d\n", number);
		printf("------------------\n");
	}
}

void testTable() {
	HashTable Hashy = InitHash(100);
	PrintTable(Hashy);
}
