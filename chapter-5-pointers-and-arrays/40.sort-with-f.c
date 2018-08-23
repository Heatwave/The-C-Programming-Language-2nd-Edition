#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
			int reverse, int foldcase, int (*comp)(void *, void *));

int numcmp(const char *, const char *);

void strtolower(const char *src, char *dst);

// gcc 40.sort-with-f.c numcmp.c readlines-writelines.c 6.alloc.c case-convert.c
main(int argc, char *argv[])
{
	char c;
	int nlines;
	int numeric = 0;
	int reverse = 0;
	int foldcase = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch(c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				foldcase = 1;
				break;
			default:
				printf("find illegal option %c\n", c);
				return 1;
			}
	
	if (argc != 0) {
		printf("Usage: sort -n -r\n");
		return 1;
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **) lineptr, 0, nlines-1, reverse, foldcase,
			(int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right,
			int reverse, int foldcase, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	char s1[MAXLEN], s2[MAXLEN];

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		char *vi;
		char *vleft;

		if (foldcase) {
			strtolower(v[i], s1);
			vi = s1;
			strtolower(v[left], s2);
			vleft = s2;
		} else {
			vi = v[i];
			vleft = v[left];
		}

		if (reverse && ((*comp)(vi, vleft) > 0))
			swap(v, ++last, i);
		else if (!reverse && ((*comp)(vi, vleft) < 0))
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1, reverse, foldcase, comp);
	qsort(v, last+1, right, reverse, foldcase, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

