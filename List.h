/*
CSE 109: Fall 2018
Elliot Scribner
ejs320
Program creates nodes of a tree and traverses said tree
Program #3
*/

#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include "Node.h"

struct List_t
{
	size_t size;
	size_t freeListSize;
	struct Node_t *start;
	struct Node_t *freeListStart;
	//v. Associated metadata so you can deallocate the Free List.
};

//Creator
struct List_t *makeList(struct List_t *this);

//Destroyer
void freeList(struct List_t *this);

//Accessor
size_t size(struct List_t *this);
size_t freeSize(struct List_t *this);
struct Node_t *insert(struct List_t *this, int value);
size_t find(struct List_t *this, int value);
size_t removeItem(struct List_t *this, int value);
struct Node_t *getHead(struct List_t *this);

#endif