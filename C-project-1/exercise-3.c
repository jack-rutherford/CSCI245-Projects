#include <stdio.h>

int main(int argc, char *argv[]){
    int c;

    c = getchar();
    while(c != EOF){
        if(c == '\t'){
            printf("\\t");
        }
        else if(c == '\\'){
            printf("\\\\");
        }
        else{
            putchar(c);
        }
        c = getchar();
    }
}