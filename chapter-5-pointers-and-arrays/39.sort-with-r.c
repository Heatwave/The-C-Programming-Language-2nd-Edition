#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
			int reverse, int (*comp)(void *, void *));

int numcmp(const char *, const char *);

// gcc 39.sort-with-r.c numcmp.c readlines-writelines.c 6.alloc.c
main(int argc, char *argv[])
{
	char c;
	int nlines;
	int numeric = 0;
	int reverse = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch(c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
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
		qsort((void **) lineptr, 0, nlines-1, reverse,
			(int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qsort(void *v[], int left, int right,
			int reverse, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++) {
		if (reverse && ((*comp)(v[i], v[left]) > 0))
			swap(v, ++last, i);
		else if (!reverse && ((*comp)(v[i], v[left]) < 0))
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1, reverse, comp);
	qsort(v, last+1, right, reverse, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

