#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

int getop(char s[])
{
   int i, c, d;

   while ((s[0] = c = getch()) == ' ' || c == '\t')
       ;
   s[1] = '\0';
   if(!isdigit(c) && c !='.'){
       if(c == 'e'){
           s[++i] = M_E;
           c = getch();
       }
       else if(c == 'p'){
           if(c = getch() == 'i'){
              s[++i] = M_PI;
              c = getch();
           }
       }
       else if(c == '*'){
           d = getch();
           if(d == '*'){
              return '^';
           }
           ungetch(d);
       }
           return c;
       
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
