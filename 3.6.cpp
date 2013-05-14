#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

stack<int> sortStack(stack<int> &a)
{
	stack<int> ret;

	while (!a.empty())
	{
		int k = a.top();
		a.pop();
	//	cout << "k=" << k << endl;

		while (!ret.empty() && ret.top() < k)
		{
			a.push(ret.top());
			ret.pop();
		}

		ret.push(k);
	}

	return ret;
}

int main()
{
	stack<int> a;
	a.push(1);
	a.push(5);
	a.push(3);
	a.push(6);
	a.push(2);
	a.push(4);

	stack<int> ans = sortStack(a);
	while (!ans.empty())
	{
		printf ("%d ", ans.top());
		ans.pop();
	}

	return 0;
}

