/*
CSE 109: Fall 2018
Elliot Scribner
ejs320
Program creates nodes of a tree and traverses said tree
Program #3
*/

#ifndef LISTTRAVERSE_H
#define LISTTRAVERSE_H

#include"List.h"
#include<stdio.h>

//Pretty prints a List_t and returns a malloced char*
//user must free the returned char*
char* traverse(struct List_t*);

#endif
