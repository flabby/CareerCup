/*
   Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than of equal to x.*/
#include <iostream>
#include <list>
#include <cstdio>
using namespace std;


void pr(list<int> &lst)
{
	list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
		printf ("%d ", *it);
	puts ("");
}

bool partition(int x, list<int> &lst)
{
	list<int>::iterator it1 = lst.begin();
	list<int>::iterator it2 = lst.begin();

	for (; it1 != lst.end(); it1++)
		if (*it1 < x)
		{
			int tmp = *it1;
			*it1 = *it2;
			*it2 = tmp;
			it2++;
		}
}

int main()
{
	int a[] = { 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
	list<int> lst(a, a + 10);
	list<int>::iterator it;

	pr(lst);	
	partition(5, lst);
	pr(lst);

	return 0;
}
