/*
 * BinarySearchTree.h
 *
 *  Created on: Mar 7, 2019
 *      Author: SawyerPC
 */

#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H_
#define DATA_STRUCTURES_BINARYSEARCHTREE_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
	void* data;
	struct Node* left;
	struct Node* right;
}Node;

Node* Insert(Node* root, void* data);
bool Search(Node* root, void* data);
void* FindMin(Node* root);
void* FindMax(Node* root);
int FindHeight(Node* root);
void LevelOrder(Node* root);
void testBST();


#endif /* DATA_STRUCTURES_BINARYSEARCHTREE_H_ */
