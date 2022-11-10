#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

extern double memory[10];

int getop(char s[])
{

    int i, c, d, f;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
       ;
    s[1] = '\0';
    i = 0;
    if(!isdigit(c) && c !='.'){
        if(c == 'e'){
           return CONSTANT;
        }
        else if(c == 'p'){
            if(s[++i] = c = getch() == 'i'){
                return CONSTANT;
            }
            ungetch(c);
            return c;
        }

        int k = i;
        if(c == '>'){
            if((c = getch()) >= '0' && c <= '9'){
                double result = pop();
                memory[c - '0'] = result;
                push(result);
                return MEM;
            }
        }

        if(c == 'M'){
            int index = getch();
            if(index >= '0' && index <= '9'){
                int nxt = getch();
                if(nxt == ' ' || nxt == '\n'){ //check to make sure it's not a double digit number
                    ungetch(nxt);
                    push(memory[index-'0']);
                    return PRINTMEM;
                }
                // else{
                //     printf("Invalid memory input, please enter a number 0-9");
                //     while(c = getch() != ' ' || c == '\n')
                //         ;
                //     return c;
                // }
            }
        }

        if(c == '*'){
            d = getch();
            if(d == '*'){
                return '^';
            }
            ungetch(d);
            return c;
        }
        if(c == '\n'){
            return c;
        }
        
        while((s[++i] = d = getch()) >= 'a' && d <= 'z') // put letters in s char array, check in main
            ;


        s[i] = '\0';
        if(d != EOF){
            ungetch(d);
        }

        if(i < 2){
            c = s[0];
            return c;
        }
        return TRIG;
    }
    i = 0;
    if (isdigit(c))
        while(isdigit(s[++i] = c = getch()))
           ;
    if(c=='.')
        while (isdigit(s[++i] = c = getch()))
           ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
