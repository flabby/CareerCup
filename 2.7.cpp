/*
   Implement a function to check if a linked list is a palindrome.
   */

#include <iostream>
using namespace std;

#include "LinkedList.h"

const int MAXN = 110;

class Stack
{
	public:
		Stack();
//		~Stack();

		void pop();
		void push(const int&);
		int top();
		bool empty();
	private:
		int len;
		int sk[MAXN];
};

Stack::Stack()
{
	len = 0;
}

//Stack::~Stack()
//{
//	delete[] sk;
//}

void Stack::pop()
{
	if (len > 0)
		len--;
}

void Stack::push(const int &x)
{
	sk[len++] = x;
}

int Stack::top()
{
	return sk[len - 1];
}
bool Stack::empty()
{
	return len == 0;
}
bool isPalindrome(LinkedList *lst)
{
	Stack stk;

	lst->moveToHead();
	while (lst->hasNext())
	{
		int k = lst->next();
		stk.push(k);
		printf ("add k=%d\n", k);
	}
	
	lst->moveToHead();
	while (!stk.empty())
	{
		if (stk.top() != lst->next())
			return false;
		stk.pop();
	}
	return true;
}
int main()
{
	int a[] = {1, 3, 5, 3, 1};

	LinkedList *lst = new LinkedList(a, 5);
	lst->pr();

	printf ("isPalin %d\n", isPalindrome(lst));

	return 0;
}
