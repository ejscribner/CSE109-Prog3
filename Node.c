/*
CSE 109: Fall 2018
Elliot Scribner
ejs320
Program creates nodes of a tree and traverses said tree
Program #3
*/

#include <stdlib.h>
#include "Node.h"



struct Node_t* makeNode1(struct Node_t* this) {
	//struct Node_t* new -> nextNode = this;
	this -> nextNode = NULL;
	this -> value = 0;
	return this;
}

struct Node_t* makeNode2(struct Node_t* this, int val) {
	this -> nextNode = NULL;
	this -> value = val;
	return this;
}

struct Node_t* makeNode4(struct Node_t* this, int val, struct Node_t* next) {
	this -> nextNode = next;
	this -> value = val;
	return this;
}

//Destroyers
void freeNode(struct Node_t* this) {
	free(this);
	this = NULL;
}

//Mutators
int setData(struct Node_t* this, int val) {
	this -> value = val;
	return val;
}

struct Node_t* setNext(struct Node_t* this, struct Node_t* next) {
	this -> nextNode = next;
	return next;
}

//Accessors
int getData(struct Node_t* this) {
	return this -> value;
}

struct Node_t* getNext(struct Node_t* this) {
	return this -> nextNode;
}