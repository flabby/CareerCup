/*
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?
 */
#include <iostream>
#include <set>
#include <hash_set.h>
using namespace std;

struct node
{
	int data;
	node *next;
	node (){}
};

node *makeList(int n, int a[])
{
	node *head = NULL;
	for (int i = 0; i < n; i++)
	{
		node *tmp = new node();
		tmp->data = a[i];
		tmp->next = head;
		head = tmp;
	}

	return head;
}
void pr(node *head)
{
	for (node *p = head; p != NULL; p = p->next)
		printf ("%2d ", p->data);
	printf ("\n");
}
bool remove1(node *head)
{
	if (head == NULL) return 1;
	
	for (node *p = head; p != NULL; p = p->next)
	{
		for (node *q = p; q->next != NULL; )
		{
			printf ("p->data=%d ", p->data);
			if (q->next != NULL)
				printf (" q->next->data=%d\n", q->next->data);
			else
				printf (" q->next == NULL\n");

			if (p->data == q->next->data)
			{
				node *k = q->next;
				//printf ("  k->data=%d\n", k->data);
				q->next = k->next;
				delete k;
				
				pr(head);
				char ch;
				scanf ("%c", &ch);
			}
			else
				q = q->next;
		}
	}
}

bool remove2(node *head)
{
	if (head == NULL) return 1;

	set<int> flg;
	set<int>::iterator it;

	node *p = head;
	flg.insert(p->data);
	for (node *q = head->next; q != NULL; )
	{
		if (flg.find(q->data) != flg.end())
		{
			p->next = q->next;
			delete q;
			q = p->next;
/*
			pr(head);
			printf ("set:");
			for (it = flg.begin(); it != flg.end(); it++)
				printf ("%d ", *it);
			printf ("\n\n");
			*/
		}
		else
		{
			flg.insert(q->data);
			p = q;
			q = q->next;
		}
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 1, 3, 5, 7, 9};

	node *head = makeList(10, a);
	pr(head);
	
	remove2(head);
	pr(head);
	return 0;
}
