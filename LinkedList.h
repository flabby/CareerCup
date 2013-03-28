/*
FILE: LinkedList.h
DESC: the header of linked list
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <cstdio>

class LinkedList
{
	public:
		LinkedList();
		LinkedList(int *intArray, int len);
		~LinkedList();
		
		void append(const int data);
		void insertFront(const int data);
		void pr();
		
		bool hasNext();
		int next();
		void moveToHead();
	private:
		Node *head;
		Node *nodePtr;
		int len;
};
#endif
