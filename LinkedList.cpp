/*
FILE: LinkedList.cpp
DESC: the code of linked list
*/
#include "LinkedList.h"

void LinkedList::moveToHead()
{
	nodePtr = head;
}
bool LinkedList::hasNext()
{
	return (nodePtr != NULL);
}

int LinkedList::next()
{
	int ret = nodePtr->data;
	nodePtr = nodePtr->next;
	return ret;
}

void LinkedList::pr()
{
	puts ("--------------------");
	for (Node *p = head; p != NULL; p = p->next)
		printf ("%d ", p->data);
	puts("----------");
}

void LinkedList::append(const int data)
{
	Node *tmp = new Node(data);

	if (head == NULL)
		head = tmp;
	else
	{
		Node *p = head;
		for (; p->next != NULL; p = p->next);
		p->next = tmp;
	}
}

void LinkedList::insertFront(const int data)
{
	Node *tmp = new Node(data);

	tmp->next = head;
	head = tmp;
	len++;
}
LinkedList::LinkedList()
{
	head = NULL;
	len = 0;
}

LinkedList::LinkedList(int *intArray, int len)
{
	head = NULL;
	this->len = 0;

	for (int i = len - 1; i >= 0; i--)
		this->insertFront(intArray[i]);
	nodePtr = head;
}

LinkedList::~LinkedList()
{
	if (head != NULL)
	{
		Node *p = head;
		Node *q = head->next;

		while (q != NULL)
		{
			delete p;
			p = q;
			q = q->next;
		}
		delete p;
	}
}

