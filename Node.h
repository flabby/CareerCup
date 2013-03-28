/*
FILE: Node.h
DESC: the node of linked list
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(){}
	Node(int _d):data(_d),next(NULL){}
};

#endif
