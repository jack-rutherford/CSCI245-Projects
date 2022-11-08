#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"
#define MAXOP 100

int main(int argc, char* argv[])
{
    int type;
    double m = 0;
    double op2;
    char s[MAXOP];
    int flag = 0;

    while ((type = getop(s)) != EOF)
    {
        // flag = 0;
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 == 0){
                flag = 1;
                printf("Illegal attempt to divide by 0.\n");
                break;
            }
            push(pop() / op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '%':
            op2 = pop();
            if(op2 == 0){
                flag = 1;
                printf("Illegal attempt to divide by 0.\n");
                break;
            }
            push((int)pop() % (int)op2);
            break;
        case '\n':
            if(flag == 0){
                // printf("flag: %d", flag);
                printf("\t%.8g\n", pop());
            }
            flag = 0;
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
