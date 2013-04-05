/*
   Describe how you could use a single array to implement three stacks.
   */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 310;

struct node
{
	int pre;
	int data;
	node(){}
	node(int _p, int _d):pre(_p), data(_d){}
	void setValue(int _p, int _d)
	{
		pre = _p;
		data = _d;
	}
};

node buf[MAXN * 3];
int head[3];
int cnt = 1;

void push(int id, int x)
{
	int p = head[id];
	head[id] = cnt++;
	buf[ head[id]].setValue(p, x);
}

int pop(int id)
{
	int p = head[id];
	int ret = buf[p].data;
	head[id] = buf[p].pre;
	return ret;
}
bool empty(int id)
{
	return head[id] == 0;
}
int main()
{
	push(0, 8);
	push(1, 18);
	push(2, 28);

	printf ("0->pop=%d\n", pop(0));
	printf ("1->pop=%d\n", pop(1));
	printf ("2->pop=%d\n", pop(2));

	return 0;
}
