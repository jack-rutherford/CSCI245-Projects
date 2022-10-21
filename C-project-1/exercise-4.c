#include <stdio.h>

#define NORMAL 1
#define READ_SLASH 2
#define IN_SL_COMMENT 3
#define IN_ML_COMMENT 4
#define MAYBE_END_ML 5
#define IN_DOUBLE_QUOTE 6
#define IN_SINGLE_QUOTE 7


int main(int argc, char *argv[]){
    int state = NORMAL;
    int c;

    c = getchar();
    while(c != EOF){
        switch (state)
        {
        case NORMAL:
            if(c == '/'){
                state = READ_SLASH;
            }
            else if(c == '"'){
                putchar(c);
                state = IN_DOUBLE_QUOTE;
            }
            else if(c == '\''){
                putchar(c);
                state = IN_SINGLE_QUOTE;
            }
            else{
                putchar(c);
            }
            break;
        
        case READ_SLASH:
            if(c == '/'){
                state = IN_SL_COMMENT;
            }
            else if(c == '*'){
                state = IN_ML_COMMENT;
            }
            else{
                state = NORMAL;
                putchar(c);
            }
            break;

        case IN_SL_COMMENT:
            if(c == '\n'){
                state = NORMAL;
                putchar(c);
            }
            break;

        case IN_ML_COMMENT:
            if(c == '*'){
                state = MAYBE_END_ML;
            }
            break;

        case MAYBE_END_ML:
            if(c == '/'){
                state = NORMAL;
            }
            break;

        case IN_DOUBLE_QUOTE:
            if(c == '"'){
                state = NORMAL;
                putchar(c);
            }
            else{
                putchar(c);
            }
            break;

        case IN_SINGLE_QUOTE:
            if(c == '\''){
                state = NORMAL;
                putchar(c);
            }
            else{
                putchar(c);
            }
            break;
        }
        
        c = getchar();
    }

}