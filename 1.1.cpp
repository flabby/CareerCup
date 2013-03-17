/*
 * CareerCup 1.1
 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
 */
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXM = 256;

//use bitset
bool isUnique(bitset<MAXM> flg, string str)
{
//	printf ("flg none %d\n", flg.none());
//	printf ("flg[1]=%d\n", (int)flg[1]);
	for (int i = 0; i < str.length(); i++)
	{
		if (flg[str[i]])
			return 0;
		flg[str[i]] = 1;
	}
	return 1;
}
//without data structures -- sort 
bool isUnique2(string str)
{
	sort(&str[0], &str[0] + str.length());
//	printf ("str=(%s)\n", str.c_str());
	
	for (int i = 1; i < str.length(); i++)
		if (str[i] == str[i - 1])
			return 0;
	return 1;
}

int main()
{
	bitset<MAXM> flg;

	//read test string
	string str;
	cin >> str;

	printf ("isUnique2 %d\n", isUnique2(str));
	system ("pause");
	return 0;
}
