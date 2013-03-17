/*
 * Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.
 */
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(char *str)
{
	int len = strlen(str);
	for (int i = 0, j = len - 1; i < j; i++, j--)
		swap(str[i], str[j]);
}

int main()
{
	char a[] = "hello";

	reverse(a);

	printf ("str=(%s)\n", a);

	return 0;
}
