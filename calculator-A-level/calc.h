#define NUMBER '0'
#define CONSTANT '1'
#define TRIG '2'
#define MEM '3'
#define PRINTMEM '4'
int getop(char []);
void push(double);
double pop();
int getch();
void ungetch(int);
