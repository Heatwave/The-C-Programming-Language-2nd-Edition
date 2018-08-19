#include <stdio.h>

int main()
{
	char *month_name(int);

	char *n = month_name(9);
	printf("%s\n", n);

	return 0;
}

char *month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"Aprial", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

