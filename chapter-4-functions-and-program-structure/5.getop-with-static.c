#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define MAX_LEN 1024
#define NUMBER '0'

int getop(char []);

int main()
{
	while (1) {
		char s[MAX_LEN];
		int op = getop(s);
		printf("op: %c\n", op);
	}
}

int getop(char s[])
{
	static int buffer = EOF;
	printf("buffer: %d\n", buffer);
	int i, c;

	while ((s[0] = c = (buffer == EOF ? getchar() : buffer)) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = (buffer == EOF ? getchar() : buffer)))
			;
			
	if (c == '.')
		while (isdigit(s[++i] = c = (buffer == EOF ? getchar() : buffer)))
			;
	s[i] = '\0';
	if (c != EOF) {
		if (buffer != EOF)
			printf("getop: cannot ungetch more char\n");
		else
			buffer = c;
	}
	return NUMBER;
}

