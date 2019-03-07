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

struct Node {
	void* data;
	struct Node* left;
	struct Node* right;
};

struct Node* Insert(struct Node* root, void* data);
bool Search(struct Node* root, void* data);
void* FindMin(struct Node* root);
void* FindMax(struct Node* root);
int FindHeight(struct Node* root);
void LevelOrder(struct Node* root);
void testBST();


#endif /* DATA_STRUCTURES_BINARYSEARCHTREE_H_ */
