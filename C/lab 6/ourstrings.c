#include "ourstrings.h"
#include <stdio.h>

void copy(char src[], char dest[]){
    
    int count = 0;;
    while (src[count] != '\0'){
        dest[count] = src[count];
        ++count;
    }
    dest[count] = '\0';
}

int strlength(char str[]){
    int count = 0;;
    while (str[count] != '\0'){
        ++count;
    }
    return count;
}

int replace(char str[], char original[], char replacement[]){
    int olen = strlength(original);
    int rlen = strlength(replacement);
    int slen = strlength(str);

    int count = 0;
    if (olen != rlen){
        return -1;
    }
    else{
        for(int i = 0; i < slen; i++){
            for(int k = i+1; k < slen; k++){
                if(str[k] == original[count]){
                    str[k] = replacement[count];
                    count++;
                }
            }
        }
    }
}

int strtolower(char input[]){
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] > 64 && input[i] < 91){
            input[i] += 32;
        }
    }
}

int strcompare(char onec[], char twoc[]){
    int ocount = 0;
    int scount = 0;
    for(int i = 0; onec[i] != '\0' && twoc[i] != '\0'; i++){
        ocount += onec[i];
        scount += twoc[i];
    }
    if(ocount == scount){
        return 0;
    }else if(ocount > scount){
        return 1;
    }
    else{
        return -1;
    }
}