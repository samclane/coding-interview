#include "HashTable.h"

struct Item* InitItemPtr() {
	struct Item* i = malloc(sizeof(struct Item));
	i->key = "empty";
	i->value = "empty";
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
		hash = (hash + (int)key[i]) * 17;
	}

	index = hash % t.tableSize;

	return index;
}

void AddItem(HashTable t, char* key, char* value) {
	int index = Hash(t, key);

	if (strcmp(t.table[index]->key, "empty") == 0) {
		t.table[index]->key = key;
		t.table[index]->value = value;
	}
	else {
		struct Item* i = t.table[index];
		struct Item* n = calloc(1, sizeof(struct Item));
		n->key = key;
		n->value = value;
		n->next = NULL;
		while(i->next != NULL) {
			i = i->next;
		}
		i->next = n;
	}
}

int NumberOfItemsInIndex(HashTable t, int index) {
	int count = 0;

	if (strcmp(t.table[index]->key, "empty") == 0) {
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
		printf("%s\n", t.table[i]->key);
		printf("%s\n", t.table[i]->value);
		printf("# of items %d\n", number);
		printf("------------------\n");
	}
}

void PrintItemsInIndex(HashTable t, int index) {
	struct Item* itemPtr = t.table[index];

	if (strcmp(itemPtr->key, "empty") == 0) {
		printf("index = %d is empty\n", index);
	}
	else {
		printf("index %d contains the following items:\n", index);

		while(itemPtr != NULL) {
			printf("------------------\n");
			printf("%s\n", itemPtr->key);
			printf("%s\n", itemPtr->value);
			printf("------------------\n");
			itemPtr = itemPtr->next;
		}
	}
}

void FindValue(HashTable t, char* key) {
	int index = Hash(t, key);
	bool foundKey = false;
	char * value;

	struct Item* itemPtr = t.table[index];
	while (itemPtr != NULL) {
		if (strcmp(itemPtr->key, key) == 0) {
			foundKey = true;
			value = itemPtr->value;
		}
		itemPtr = itemPtr->next;
	}
	if (foundKey == true) {
		printf("Favorite drink = %s\n", value);
	}
	else {
		printf("Name '%s' not found in Hash Table\n", key);
	}
}

void RemoveItem(HashTable t, char* key) {
	int index = Hash(t, key);

	struct Item* delPtr;
	struct Item* P1;
	struct Item* P2;

	// Case 0 - Bucket is empty
	if (strcmp(t.table[index]->key, "empty") == 0 && strcmp(t.table[index]->value, "empty") == 0) {
		printf("%s was not found in the Hash Table\n", key);
	}

	// Case 1 - Only 1 Item in bucket + matching name
	else if (strcmp(t.table[index]->key, key) == 0 && t.table[index]->next == NULL) {
		t.table[index]->key = "empty";
		t.table[index]->value = "empty";

		printf("%s was removed from the Hash Table\n", key);
	}

	// Case 2 - There's a match in the first item, but there's more items too
	else if (strcmp(t.table[index]->key, key) == 0) {
		delPtr = t.table[index];
		t.table[index] = t.table[index]->next;
		free(delPtr);

		printf("%s was removed from the Hash Table\n", key);
	}

	// Case 3 - Bucket contains items, first item doesn't match
	else {
		P1 = t.table[index]->next;
		P2 = t.table[index];

		while(P1 != NULL && strcmp(P1->key, key) != 0) {
			P2 = P1;
			P1 = P1->next;
		}
		// Case 3.1 - All items don't match
		if(P1 == NULL) {
			printf("%s was not found in the Hash Table\n", key);
		}
		// Case 3.2 - Match is found
		else {
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			free(delPtr);
			printf("%s was removed from the Hash Table\n", key);
		}
	}


}

void testTable() {
	HashTable Hashy = InitHash(4);
	char name[256];

	AddItem(Hashy, "Paul", "Locha");
	AddItem(Hashy, "Kim", "Iced Mocha");
	AddItem(Hashy, "Emma", "Strawberry Smoothie");
	AddItem(Hashy, "Annie", "Hot Chocolate");
	AddItem(Hashy, "Sarah", "Passion Tea");
	AddItem(Hashy, "Pepper", "Caramel Mocha");
	AddItem(Hashy, "Mike", "Chai Tea");
	AddItem(Hashy, "Steve", "Apple Cider");
	AddItem(Hashy, "Bill", "Root Beer");
	AddItem(Hashy, "Marie", "Skinny Latte");
	AddItem(Hashy, "Susan", "Water");
	AddItem(Hashy, "Joe", "Green Tea");

	PrintTable(Hashy);

	while(strcmp(name, "exit") != 0) {
		printf("Search for : ");
		fflush(stdout);
		fgets(name, sizeof(name), stdin);
		// Replace newline with null-terminator
		name[strlen(name)-1] = '\0';
		if (strcmp(name, "exit") != 0) {
			// FindValue(Hashy, name);
			RemoveItem(Hashy, name);
		}
		fflush(stdout);
	}

	PrintTable(Hashy);
}
