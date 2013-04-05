/*
   How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time. */
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

class StackWithMin
{
	public:
		int &top();
		int mini();
		void push(int);
		void pop();
		bool empty();
	private:
		stack<int>data;
		stack<int>mn;
};

int &StackWithMin::top()
{
	return data.top();
}

int StackWithMin::mini()
{
	return mn.top();
}

void StackWithMin::push(int x)
{
	if (mn.empty() || x <= mn.top())
		mn.push(x);
	data.push(x);
}

void StackWithMin::pop()
{
	if (data.empty())
		return;

	if (mn.top() == data.top())
		mn.pop();
	data.pop();
}
bool StackWithMin::empty()
{
	return data.empty();
}
int main()
{
	StackWithMin s;

	s.push(10);
	s.push(8);
	s.push(11);
	s.push(8);
	s.push(8);

	printf ("mini=%d top=%d\n", s.mini(), s.top());
	s.pop();
	printf ("mini=%d top=%d\n", s.mini(), s.top());
	s.pop();
	printf ("mini=%d top=%d\n", s.mini(), s.top());
	s.pop();
	printf ("mini=%d top=%d\n", s.mini(), s.top());

	return 0;
}
