/*
   Implement an algorithm to find the kth to last element of a singly linked list.*/
#include <iostream>
// g++ -std=c++0x
#include <forward_list>

using namespace std;

struct node 
{
	int data;
	node *next;
	node (){}
	node (int _d):data(_d){ next = NULL;}
};

node* make_list(int len, int a[])
{
	node *head = NULL;

	for (int i = len - 1; i >= 0; i--)
	{
		node *tmp = new node(a[i]);
		tmp->next = head;
		head = tmp;
	}
	return head;
}

void pr(node *p)
{
	for (; p != NULL; p = p->next)
		printf ("%d ", p->data);
	puts ("");
}

int main()
{
	int k = 3;

	//v1: use forward_list
	forward_list<int> ls = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

//	for (int &x: ls)
//		cout << x << " ";
//	cout << endl;

	auto it1 = ls.begin();
	auto it2 = ls.begin();
	for (int i = 0; i < 3; i++)
		it1++;
	
	for (; it1 != ls.end(); it1++, it2++);

	cout << "*it2=" << *it2 << endl;
	
	//v2
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	node *ls2 = make_list(10, a);
	pr(ls2);

	node *p = ls2;
	node *q = ls2;
	for (int i = 0; i < k; i++)
		p = p->next;

	for (; p != NULL; p = p->next, q = q->next);
	
	printf ("k=%d %d\n", k, q->data);
	return 0;
}
