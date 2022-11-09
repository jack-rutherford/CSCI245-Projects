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


    for(int i = 1; i < argc; i++){
        int temp[MAXOP];
        int ind = 0;
        for(int j = 0; argv[i][j] != '\0'; j++){
            temp[j] = argv[i][j];
            ind++;
        }
        ungetch('\n');
        for(int j = ind - 1; j >= 0; j--){
            ungetch(temp[j]);
        }
    }

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
        case CONSTANT:
            if(s[0] == 'e'){
                push(M_E);
            }
            else{
                push(M_PI);
            }
            break;
        case TRIG:
            if(strcmp(s, "sine") == 0){
                push(sin(M_PI * pop() / 180));
            }
            else if(strcmp(s, "cosine") == 0){
                push(cos(M_PI * pop() / 180));
            }
            else if(strcmp(s, "tangent") == 0){
                push(tan(M_PI * pop() / 180));
            }
            else{
                printf("Unrecognized function %s entered\n", s);
                flag = 1;
            }
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
