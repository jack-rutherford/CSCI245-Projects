#include <stdio.h>

int main(int argc, char *argv[]){
    int c, blank;

    c = getchar();
    blank = 0;
    while(c != EOF){
        if(c != ' ' && blank == 0){
            putchar(c);
        }
        else if(blank == 1){
            if(c != ' '){
                printf(" ");
                putchar(c);
                blank = 0;
            }
        }
        else{
            blank = 1;
        }
        c = getchar();
    }
    if(blank == 0){
        printf(" ");
    }

}