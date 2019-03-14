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
#include <stdlib.h>


typedef struct HashTable {
	int tableSize;
	struct Item** table;
} HashTable;

struct Item {
	char* name;
	char* drink;
	struct Item* next;
};

struct Item* InitItemPtr();
HashTable InitHash(const int SIZE);
int Hash(HashTable t, char* key);
void AddItem(HashTable t, char* name, char* drink);
int NumberOfItemsInIndex(HashTable t, int index);
void PrintTable(HashTable t);
void testTable();

#endif /* DATA_STRUCTURES_HASHTABLE_H_ */
