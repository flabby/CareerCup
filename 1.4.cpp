/*

Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so you can perform this operation in place.)

EXAMPLE
Input  : "Mr John Smith    "
Output: "Mr%20John%20Smith"
 */
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 256;

void replaceSpace(char *s)
{
	int cnt = 0;
	int len = strlen(s);

	for (int i = 0; i < len; i++)
		if (' ' == s[i])
			cnt++;

	//printf ("len=%d cnt=%d\n", len, cnt);

	for (int i = len, j = len + 2 * cnt; i >=0; i--)
	{
	//	printf ("s[%d]=%c s[%d]=%c\n", i, s[i], j, s[j]);

		if (' ' == s[i])
		{
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';
		}
		else
			s[j--] = s[i];
	}	
}

int main()
{
//	char str[] = "1234";
//	for (int i = 0; i < 5; i++)
//		printf ("str[%d]=(%d)\n", i, (int)str[i]);

	char s[MAXN];

	gets(s);
//	printf ("s=(%s)\n", s);
//	printf ("s[4]=%c s[5]=%d\n", s[4], (int)s[5]);
	
	replaceSpace(s);
	printf ("s=(%s)\n", s);

	return 0;
}

