/*
CSE 109: Fall 2018
Elliot Scribner
ejs320
Program creates nodes of a tree and traverses said tree
Program #3
*/

#include <stdio.h>
#include <stdlib.h>
#include "List.h"


struct List_t* makeList(struct List_t* this) {
	this -> size = 0;
	this -> freeListSize = 0;
	this -> start = NULL;
	this -> freeListStart = NULL;
	//Associated metadata so you can deallocate the free list
	return this;
}

void freeList(struct List_t* this) {
	free(this -> start);
	free(this -> freeListStart);
	this -> start = NULL;
	this -> freeListStart = NULL;
}

size_t size(struct List_t* this) {
	return this -> size;
}

size_t freeSize(struct List_t* this) {
	return this -> freeListSize;
}

struct Node_t* insert(struct List_t* this, int value) {
	if(this -> freeListSize == 0) {
		this -> freeListStart = (struct Node_t*)malloc(256 * sizeof(struct Node_t));
		this -> freeListSize = 256;
	}
	struct Node_t* temp = getHead(this);
	if (temp == NULL) {
		struct Node_t* newNode = &this -> freeListStart[this -> size];
		this -> start = newNode;
		newNode -> value = value;
		this -> size += 1;
		return newNode;

	}
	while(temp -> nextNode != NULL) {
		temp = temp -> nextNode;
	}

	struct Node_t* newNode = &this -> freeListStart[this -> size];
	newNode -> nextNode = this -> freeListStart;
	this -> size += 1;
	this -> freeListSize -= 1;
	setData(newNode, value);
	setNext(newNode, NULL);

	temp -> nextNode = newNode;
	this -> start = this -> freeListStart; //Causes freeListStart to free 1 extra time

	return newNode;
}

size_t find(struct List_t* this, int value) {
	size_t counter = 0;
	struct Node_t* current = this -> start;
	for(int i = 0; i < this -> size; i++) {
		if(getData(current) == value) {
			counter++;
			current = getNext(current);
		}
	}
	return counter;
}

size_t removeItem(struct List_t* this, int value) {
	if(this -> size <= 0) {
		return 0;
	}
	struct Node_t* temp = getHead(this);
	while(temp != NULL) {
		if(temp -> value == value) {
			free(temp);
		}
		temp = getNext(temp);
	}
	return 0;
}

struct Node_t* getHead(struct List_t* this) {
	return this -> start;
}

