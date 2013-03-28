/*
   You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
   EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(){}
	Node(int _d):data(_d), next(NULL){}
};

class LinkedList
{
	public:
		LinkedList();
		LinkedList(int* intArray, int len);
		~LinkedList();

		void append(const int data);
		void insertFront(const int data);
		void pr();
		void reverse();

		void addOp1(LinkedList *lst1, LinkedList *lst2);
		void addOp2(LinkedList *lst1, LinkedList *lst2);
	private:
		Node *head;
		int len;
};

void LinkedList::addOp1(LinkedList *lst1, LinkedList *lst2)
{
	int cr = 0;
	for (Node *p = lst1->head, *q = lst2->head; p != NULL || q != NULL; )
	{
		int x = 0;
		if (p != NULL)
		{
			x = p->data;
			p = p->next;
		}
		int y = 0;
		if (q != NULL)
		{
			y = q->data;
			q = q->next;
		}

//		printf ("x=%d y=%d cr=%d\n", x, y, cr);
//		char ch;
//		getchar();

		int s = x + y + cr;
		cr = s / 10;
		s = s % 10;
		append(s);
	}
	if (cr)
		append(cr);
}
void LinkedList::addOp2(LinkedList *lst1, LinkedList *lst2)
{
	lst1->reverse();
	lst2->reverse();
	this->addOp1(lst1, lst2);
	
//	puts ("before add");
//	lst1->pr();
//	lst2->pr();
//	this->pr();
//	puts("");

	this->reverse();
	lst1->reverse();
	lst2->reverse();
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

void LinkedList::pr()
{
	for (Node *p = head; p != NULL; p = p->next)
		printf ("%d ", p->data);
	puts ("");
}

void LinkedList::append(const int data)
{
	//printf ("\nstart append\n");
	Node *tmp = new Node(data);

//	printf ("head==NULL %d\n", head == NULL);

	if (head == NULL)
	{
		head = tmp;
//		printf ("append first\n");
	}
	else
	{
		Node *p = head;
		for (; p->next != NULL; p = p->next);

		p->next = tmp;
	}
	len++;
}

void LinkedList::reverse()
{
	Node *pre = NULL;
	Node *q = head;
	while (q != NULL)
	{
		Node *t = q->next;
		q->next = pre;
		pre = q;

		head = q;

		q = t;
	}
}
void LinkedList::insertFront(const int data)
{
	Node *tmp = new Node(data);
	
	tmp->next = head;
	head = tmp;
	len++;

//	printf ("insertFront(%d)\n", data);
}

int main()
{
	int a[] = {7, 1, 6};
	int b[] = {5, 9, 2};
	LinkedList *lst1 = new LinkedList(a, 3);
	LinkedList *lst2 = new LinkedList(b, 3);
	lst1->pr();
//	lst1->reverse();
//	printf ("reverse\n");
//	lst1->pr();

	lst2->pr();

	puts ("-----sum1---------------");
	LinkedList *sum = new LinkedList;
	sum->addOp1(lst1, lst2);
	sum->pr();
	puts ("-----sum2---------------");
	LinkedList *sum2 = new LinkedList;
	lst1->reverse();
	lst2->reverse();
//	lst1->pr();
//	lst2->pr();
	sum2->addOp2(lst1, lst2);
	sum2->pr();

	return 0;
}
