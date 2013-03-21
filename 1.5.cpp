/*
 * Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string.
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 200;

string compress(string str)
{
	string ret;

	for (int i = 0; i < str.length(); )
	{
		int cnt = 1;
		while (str[i + cnt] == str[i])
			cnt++;

		ret += str[i];
		ret += (char)cnt + '0';

		i += cnt;
	}

	if (ret.length() < str.length())
		return ret;
	return str;
}

int main()
{
	string s;
	cin >> s;

	cout << compress(s) << endl;

	return 0;
}
