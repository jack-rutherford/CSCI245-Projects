#include <stdio.h>

#define TAB '\t'
#define SPACE ' '
#define NEW_LINE '\n'

int tabc, spc, nlc = 0;

int main(int argc, char *argv[]){
    int c;

    c = getchar();
    while(c != EOF){
        if(c == TAB){
            ++tabc;
        }
        else if(c == SPACE){
            ++spc;
        }
        else if(c == NEW_LINE){
            ++nlc;
        }
        c = getchar();  
    }
    printf("Found %d tabs, %d blanks and %d new lines\n", tabc, spc, nlc);
}