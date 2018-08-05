#include <stdio.h>

#define MAX_LEN 1024

void unescape(char[], char[]);

main()
{
	char t[] = "Hello\\tWorld!!!\\r\\nEOF\\v";
	printf("%s\n", t);
	char s[MAX_LEN] = "";
	unescape(s, t);
	printf("%s\n", s);
}

void unescape(char s[], char t[])
{
	int i, j, n;

	for (i = 0, j = 0; t[j] != '\0'; i++, j++) {
		if (t[j] == '\\' && t[j+1] != '\0') {
			j++;

			switch(t[j]) {
				case 'a':
					s[i] = '\a';
					break;
				case 'b':
					s[i] = '\b';
					break;
				case 'f':
					s[i] = '\f';
					break;
				case 'n':
					s[i] = '\n';
					break;
				case 'r':
					s[i] = '\r';
					break;
				case 't':
					s[i] = '\t';
					break;
				case 'v':
					s[i] = '\v';
					break;
				default:
					s[i++] = '\\';
					s[i] = t[j];
					break;
			}
		} else {
			s[i] = t[j];
		}
	}

	s[i] = '\0';
}

