/*
   Implement a function to check if a binary tree is balanced. Forthe purposes of this question, a balanced tree is defined to be a tree suchthat the heights of the two subtrees of any node never differ by more than one.
   */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	node *lc, *rc;
	int val;
	node(int v = 0):val(v), lc(NULL), rc(NULL) {};
};

// create a test tree
//         0
//      0     0
//       0   0 0
node *createTree()
{
	node *root = new node();
	root->lc = new node();
	root->rc = new node();
	root->lc->rc = new node();
	root->rc->lc = new node();
	root->rc->rc = new node();
	return root;
}

int maxDep(node *p)
{
	if (p == NULL)
		return 0;
	return 1 + max(maxDep(p->lc), maxDep(p->rc));
}
int minDep(node *p)
{
	if (p == NULL)
		return 0;
	return 1 + min(minDep(p->lc), minDep(p->rc));
}
bool isBalance(node *root)
{
	int mx = maxDep(root);
	int mn = minDep(root);
	return abs(mx - mn) < 2;
}

int main()
{
	node *root = createTree();

	cout << isBalance(root) << endl;

	return 0;
}
		
/*
const int MAXN = 1000;
struct node 
{
	int lc, rc, val;
	node(int v = 0):val(v), lc(0), rc(0){}
};
int tp;

node tr[MAXN];

//create tree:   a[1]
//          a[2]      a[3] 
//      a[4]  a[4] a[6]  a[7]

void createTree(int a[], int n)
{
	tp = 0;
	for (int i = 1; i <= n; i++)
*/		
