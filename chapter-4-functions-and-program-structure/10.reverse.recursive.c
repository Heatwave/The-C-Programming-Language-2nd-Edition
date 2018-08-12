#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);
void swap(char s[], int i, int j);

int main()
{
	char s[] = "Hello, World!!!";
	reverse(s, 0, strlen(s) - 1);
	printf("%s", s);
}

void reverse(char s[], int left, int right)
{
	if (left >= right)
		return;
	
	swap(s, left, right);
	reverse(s, ++left, --right);
}

void swap(char s[], int i, int j)
{
	char temp = s[j];
	s[j] = s[i];
	s[i] = temp;
}

