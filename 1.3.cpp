/*
 * Given two strings, write a method to decide if one is a permutation of the other.
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 130;

bool check(string s1, string s2)
{
	if (s1.length() != s2.length())
		return 0;

	int flg1[MAXN];
	int flg2[MAXN];
	for (int i = 0; i < MAXN; i++)
		flg1[i] = flg2[i] = 0;

	for (int i = 0; i < s1.length(); i++)
		flg1[s1[i]]++;
	
	for (int i = 0; i < s2.length(); i++)
		flg2[s2[i]]++;

	for (int i = 0; i < MAXN; i++)
		if (flg1[i] != flg2[i])
			return 0;
	return 1;
}

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	cout << "check " << check(s1, s2) << endl;

	return 0;
}

