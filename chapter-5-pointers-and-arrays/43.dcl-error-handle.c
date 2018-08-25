#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

#define DATATYPE_LEN 6

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int isvalid_datatype(const char*);

int gettoken(void);
int tokentype;	// type of last token
char token[MAXTOKEN];	// last token string
char name[MAXTOKEN];	// identifier name
char datatype[MAXTOKEN];	// data type = char, int, etc.
char out[1000];	// output string

// gcc 43.dcl-error-handle.c getch.c
main()
{
	while (gettoken() != EOF) {	// 1st token on line
		strcpy(datatype, token);

		if (tokentype != NAME) {
			printf("%c is not a valid datatype\n", tokentype);
			continue;
		} else if (!isvalid_datatype(datatype)) {
			printf("%s is not a valid datatype\n", datatype);
			continue;
		}

		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}

	return 0;
}

void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*';)
		ns++;

	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();

		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME)
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");

	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;

	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}

int isvalid_datatype(const char* s)
{
	char *datatypes[DATATYPE_LEN] = { "char", "short", "int", "long", "float", "double" };

	int len = 0;
	while (len < DATATYPE_LEN)
		if (strcmp(s, datatypes[len++]) == 0)
			return 1;

	return 0;
}

