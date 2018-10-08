/*
CSE 109: Fall 2018
Elliot Scribner
ejs320
Program creates nodes of a tree and traverses said tree
Program #3
*/

#ifndef NODE_H
#define NODE_H

struct Node_t {
	//link to next node and node value
	struct Node_t* nextNode;
	int value;
};

//Creators
struct Node_t* makeNode1(struct Node_t* this);
struct Node_t* makeNode2(struct Node_t* this, int val);
struct Node_t* makeNode4(struct Node_t* this, int val, struct Node_t* next);

//Destroyers
void freeNode(struct Node_t* this);

//Mutator
int setData(struct Node_t* this, int val);
struct Node_t* setNext(struct Node_t* this, struct Node_t* next);

//Getters
int getData(struct Node_t* this);
struct Node_t* getNext(struct Node_t* this);

#endif