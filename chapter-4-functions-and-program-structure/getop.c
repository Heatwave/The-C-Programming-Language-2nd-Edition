#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

int strrindex(char source[], char searchfor[]);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	i = 0;

	if (c == '+' || c == '-') {
		int op = c;
		c = getch();
		if (!isdigit(c) && c != '.') {
			ungetch(c);
			return op;
		} else {
			ungetch(c);
		}
	} else if (isalpha(c)) {
		while (isalpha(s[++i] = c = getch()))
			;
		ungetch(c);

		if (i == 1) {
			s[0] = tolower(s[0]) - 'a';
			s[1] = '\0';
			return VAR;
		}

		s[++i] = '\0';

		int index;
		index = strrindex(s, "sin");
		if (index == 0)
			return FUNC;

		index = strrindex(s, "exp");
		if (index == 0)
			return FUNC;

		index = strrindex(s, "pow");
		if (index == 0)
			return FUNC;

		return 0;
	} else if (!isdigit(c) && c != '.') {
		return c;
	}

	i = 0;

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s) - 2; i > 0; i--) {
		for (j = i, k = strlen(t) - 1; j > 0 && k > 0 && s[j] == t[k]; j--, k--)
			;

		if (k == 0)
			return j;
	}
	return -1;
}
