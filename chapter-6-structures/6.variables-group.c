#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct list {
	struct tnode *cur;
	struct list *next;
};

const char *keywords[] = {"char", "double", "int", "float", "void"};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int iskeyword(char *word);
int binsearch(char *word, const char *keywords[], int n);
int getvariable(char *word, int lim);
void addgroup(struct list *, char *, int same_char);
void sort_groups(struct list *tlist, int same_char);
void swap_tree_cur(struct list *pre, struct list *next);
void groupprint(struct list *tlist);

// gcc 6.variables-group.c getch.c
main(int argc, char *argv[])
{
	int same_char = 1;
	if (argc > 1)
		same_char = atoi(argv[1]);

	struct list *tlist = malloc(sizeof(struct list));
	tlist->cur = NULL;
	tlist->next = NULL;

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (iskeyword(word)) {
			getvariable(word, MAXWORD);
			if (isalpha(word[0])) {
				addgroup(tlist, word, same_char);
			}
		}
	sort_groups(tlist, same_char);
	groupprint(tlist);

	return 0;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

int iskeyword(char *word)
{
	if (binsearch(word, keywords, sizeof(keywords) / sizeof(keywords[0])) != -1)
		return 1;
	else
		return 0;
}

int binsearch(char *word, const char *keywords[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, keywords[mid])) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int getvariable(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()) || c == '*')
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

struct tnode *talloc(void);
char *mystrdup(char *s);

void addgroup(struct list *tlist, char *word, int same_char)
{
	if (tlist->cur == NULL) {
		tlist->cur = talloc();
		tlist->cur->word = mystrdup(word);
		tlist->cur->count = 1;
		tlist->cur->left = tlist->cur->right = NULL;
	} else {
		struct list *p = tlist, *pre = tlist;
		while (p != NULL && p->cur != NULL && strncmp(word, p->cur->word, same_char) != 0) {
			pre = p;
			p = p->next;
		}
		if (p == NULL) {
			p = malloc(sizeof(struct list));
			p->cur = NULL;
			p->next = NULL;
			addgroup(p, word, same_char);
			pre->next = p;
		} else {
			addtree(p->cur, word);
		}
	}
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w); p->count = 1;
		p->left = p-> right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}

void sort_groups(struct list *tlist, int same_char)
{
	struct list *pre = tlist;
	struct list *p;
	int swapped = 0;
	while (pre != NULL) {
		p = pre;
		while (p != NULL && p->next != NULL) {
			if (strncmp(p->cur->word, p->next->cur->word, same_char) > 0) {
				swap_tree_cur(p, p->next);
				swapped = 1;
			}
			p = p->next;
		}
		if (swapped == 0)
			break;
		else
			swapped = 0;
	}
}

void swap_tree_cur(struct list *pre, struct list *next)
{
	struct tnode *temp;
	temp = pre->cur;
	pre->cur = next->cur;
	next->cur = temp;
}

void groupprint(struct list *tlist)
{
	int i = 0;
	struct list *p = tlist;
	while (p != NULL) {
		printf("Group %d:\n", i++);
		treeprint(p->cur);
		printf("\n");
		p = p->next;
	}
}

