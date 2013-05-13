/*
   3.5 Implement a MyQueue class which implements a queue using two stacks.
  */

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

// stack:: empty pop push size top
// queue:: empty pop push size front back

class MyQueue
{
	public:
		int size();
		void myPop();
		void myPush(const int& x);
//		int myFront();
		int myBack();
		//int& myTop();
		void pr() 
		{
			printf ("s1 size=%d\n", s1.size());
			if (s1.size())
				printf ("  top=%d\n", s1.top());
			printf ("s2 size=%d\n", s2.size());
			if (s2.size())
				printf ("  top=%d\n", s2.top());
		}
	private:
		stack<int> s1, s2;
};
int MyQueue::size()
{
	return s1.size() + s2.size();
}

void MyQueue::myPop()
{
	if (s2.empty())
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	if (s2.empty())
	{
		printf ("pop error: no element\n");
		return;
	}
	s2.pop();
}
void MyQueue::myPush(const int &x)
{
	s1.push(x);
}
int MyQueue::myBack()
{
	if (s2.empty())
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	if (s2.empty())
	{
		printf ("back error: no element\n");
		return 0;
	}
	return s2.top();
}

int main()
{
	MyQueue qu;
	qu.myPush(1);
	qu.myPush(2);
	qu.myPush(3);
	qu.myPush(4);
	qu.pr();
	qu.myPop();
	qu.pr();
	cout << qu.myBack() << endl;

	return 0;
}


