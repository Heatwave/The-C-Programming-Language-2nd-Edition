#include <stdio.h>
#include <string.h>

main()
{
	char s[100];
	s[0] = 'a' - 'a';
	s[1] = 'b';
	s[2] = '\0';
	printf("strlen(s): %d\n", strlen(s));
	return 0;
}
