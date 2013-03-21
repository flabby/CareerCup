/*
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100;

void pr(int n, int m, int a[][MAXN])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf ("%d ", a[i][j]);
		puts("");
	}
}

bool check(int n, int m, int a[][MAXN])
{
	int rowFlg[MAXN];
	int colFlg[MAXN];

	memset(rowFlg, 0, sizeof(rowFlg));
	memset(colFlg, 0, sizeof(colFlg));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0)
				rowFlg[i] = colFlg[j] = 1;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (rowFlg[i] || colFlg[j])
				a[i][j] = 0;
}
	
int main()
{
	int a[MAXN][MAXN] = {
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1}};

	int n = 4;
	int m = 5;

	check(n, m, a);
	pr(n, m, a);

	return 0;
}	

