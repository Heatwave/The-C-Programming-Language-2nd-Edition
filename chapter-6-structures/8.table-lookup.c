#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
struct nlist *undef(char *name);

int main()
{
	install("name", "Trump");
	struct nlist *n = lookup("name");
	if (n != NULL)
		printf("n->defn: %s\n", n->defn);
	else
		printf("n == NULL\n");

	install("name", "Obama");
	lookup("test");

	n = lookup("name");
	printf("n->defn: %s\n", n->defn);

	n = undef("name");
	printf("n->defn: %s\n", n->defn);
	free(n->name);
	free(n->defn);
	free(n);

	n = lookup("name");
	printf("n == NULL: %d\n", n == NULL);

	return 0;
}

unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			return np;
	}
	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free((void *) np->defn);

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

struct nlist *undef(char *name)
{
	struct nlist *np;

	if ((np = lookup(name)) == NULL)
		return NULL;

	unsigned hashval = hash(name);
	hashtab[hashval] = NULL;

	return np;
}

