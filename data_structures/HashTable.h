/*
 * HashTable.h
 *
 *  Created on: Mar 14, 2019
 *      Author: SawyerPC
 */

#ifndef DATA_STRUCTURES_HASHTABLE_H_
#define DATA_STRUCTURES_HASHTABLE_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct HashTable {
	int tableSize;
	struct Item** table;
} HashTable;

struct Item {
	char* key;
	char* value;
	struct Item* next;
};

struct Item* InitItemPtr();
HashTable InitHash(const int size);
int Hash(HashTable t, char* key);
void AddItem(HashTable t, char* key, char* value);
int NumberOfItemsInIndex(HashTable t, int index);
void PrintTable(HashTable t);
void PrintItemsInIndex(HashTable t, int index);
void FindValue(HashTable t, char* key);
void testTable();

#endif /* DATA_STRUCTURES_HASHTABLE_H_ */
