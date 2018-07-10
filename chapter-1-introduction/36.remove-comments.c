#include <stdio.h>

#define OUT_COMMENT 0
#define IN_COMMENT 1
#define IN_ONE_LINE_COMMENT 2

#define OUT_STRING 0
#define IN_STRING 1

/*
 * This is the exercise 1-23 of The C Programming Language
 * remove all of the comments in the C program
 */

main()
{
	int c;
	int status, stringStatus;
	int preChar;

	printf("/*asdqwe*/");

	status = OUT_COMMENT;
	stringStatus = OUT_STRING;

	while((c = getchar()) != EOF) {
		/*	This is the comment for test */
		if (status == OUT_COMMENT) {
			if (stringStatus == OUT_STRING) {
				if (c == '"') {
					stringStatus = IN_STRING;
					putchar(c);
					continue;
				}

				if (c == '/' && preChar == '/') {
					status = IN_ONE_LINE_COMMENT;
					preChar = '\n';
					continue;
				} else if (c == '/') {
					preChar = c;
					continue;
				}

				if (c == '*' && preChar == '/') {
					status = IN_COMMENT;
				} else if (preChar == '/') {
					putchar('/');
					putchar(c);
				} else {
					putchar(c);
				}
			} else {
				if (c == '"') {
					stringStatus = OUT_STRING;
					putchar(c);
				} else {
					putchar(c);
				}
			}
		} else if (status == IN_ONE_LINE_COMMENT) {
			if (c == '\n') {
				putchar('\n');
				status = OUT_COMMENT;
			}
		} else {
			if (c == '/' && preChar == '*') {
				status = OUT_COMMENT;
				preChar = 0;
				continue;	// comment for test
			}
		}
		preChar = c;
	}

	printf("// test one line comment");
}
