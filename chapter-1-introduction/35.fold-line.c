#include <stdio.h>

#define MAXLINE 1000

int myGetline(char line[], int maxline);

main()
{
	int len;
	int lineLenLimit;
	char line[MAXLINE], outputLine[MAXLINE];
	int i, j;
	int foldCol;


	lineLenLimit = 10;

	while ((len = myGetline(line, MAXLINE)) > 0) {
		for (i = 0; i < len; ++i) {
			if (i != 0 && (i + 1) % lineLenLimit == 0) {
				for (j = i; j > 0; --j) {
					if (line[j] != ' ' && line[j] != '\t') {
						foldCol = j;
						break;
					}
				}

				for (j = 0; j < foldCol - i + lineLenLimit; ++j) {
					outputLine[j] = line[j + i - lineLenLimit + 1];
				}
				outputLine[j] = '\n';
				outputLine[j + 1] = '\0';

				printf("%s", outputLine);
			} else if (i == len - 1) {
				for (j = 0; j < i % lineLenLimit; ++j)
					outputLine[j] = line[j + i - (i % lineLenLimit)];

				outputLine[j] = '\0';

				printf("%s", outputLine);
			}
		}
	}
}

int myGetline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
