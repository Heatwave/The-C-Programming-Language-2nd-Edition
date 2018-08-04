#include <stdio.h>

main()
{
	int c, i, nwhite, nother, ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;
	
	while ((c = getchar()) != EOF) {
		switch(c) {
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9': 
			ndigit[c-'0']++;
			break;
		case ' ':
		case '\n':
		case '\t':
			nwhite++;
			break;
		default:
			nother++;
			break;
		}
	}
	printf("digits = ");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n",
		nwhite, nother);
	return 0;
}
