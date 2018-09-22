#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAX_LINES 100

struct tnode {
	char *word;
	int count;
	int lines[MAX_LINES];
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

static int current_line = 1;

// gcc 7.words-appear-lines.c getch.c
main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);

	return 0;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	do {
		c = getch();
		if (c == '\n')
			++current_line;
	} while (isspace(c));

	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

struct tnode *talloc(void);
char *mystrdup(char *s);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	int i;

	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w);
		p->count = 1;
		p->lines[0] = current_line;
		p->left = p-> right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
		i = 0;
		while (p->lines[i] != 0)
			++i;
		//printf("i: %d\n", i);
		p->lines[i] = current_line;
	} else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	int i = 0;
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s ", p->count, p->word);
		while (p->lines[i] != 0 && i < MAX_LINES)
			printf("%d ", p->lines[i++]);
		printf("\n");
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

