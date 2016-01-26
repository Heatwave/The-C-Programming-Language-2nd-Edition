#include <stdio.h>
#define MAXLINE 100    /* maximum input line size */

/* Exercise 1-16
 * Revise the main routine of the longest-line program so
 * it will correctly print the length of arbitrarily long input lines,
 * and as much as possible of the text. */

int myGetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    
    max = 0;
    while ((len = myGetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("length: %d\n%s", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int myGetline(char s[], int lim)
{
    int c, i, j;
    
	j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if ( i < lim - 2)
		{
			s[j] = c;
			++j;
		}

	}
    if (c == '\n')
    {
        s[j] = c;
        ++i;
        ++j;
    }
    s[j] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
