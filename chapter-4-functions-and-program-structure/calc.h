#define NUMBER '0'	// signal that a number was found
#define FUNC '1'	// signal that math function was found
#define VAR '2'	// signal that variable was found

void push(double);
double pop(void);

int getop(char []);

int getch(void);
void ungetch(int);
