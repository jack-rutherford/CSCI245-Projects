#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]){
    int c, state, ml, sl, ml2, dq = 0;

    state = OUT;
    c = getchar();
    while(c != EOF){
        if(state == OUT){
            if(c == '/'){
                state = IN;
            }
            else{
                putchar(c);
            }
        }
        else if(state == IN){
            if(c == '/' && sl == 0){
                sl = 1;
            }
            else if(c == '*' && ml == 0){
                ml = 1;
            }
            else if(sl == 1 && c == '\n'){
                state = OUT;
                sl = 0;
                printf("\n");
            }
            else if(ml == 1 && c == '*'){
                ml2 = 1;
            }
            else if(ml == 1 && ml2 == 1 && c == '/'){
                state = OUT;
                ml = 0;
                ml2 = 0;
            }
        }

        c = getchar();
    }
}