#include "ourstrings.h"
#include <stdio.h>

int main(int argc, char** argv){
    char hello[] = "Hello world!!!!!";
    char world[17];

    copy(hello, world);
    int hlength = strlength(hello);
    int wlength = strlength(world);
    printf("hello = %s (length %d), world = %s (length %d)\n", hello, hlength, world, wlength);

    char hexAlphabet[] = "0123456789abcdef";
    replace(hexAlphabet, "acf", "ACF");
    printf("New version is %s\n", hexAlphabet);

    char sentence[] = "ChaNGe eVerTHINg to LOwerCaSe";
    strtolower(sentence);
    printf("Lower case sentence is: %s\n", sentence);

    char arr1[] = "1234567";
    char arr2[] = "abcdefg";
    int strcomp = strcompare(arr1, arr2);
    printf("Comparing strings %s and %s\n", arr1, arr2);
    printf("Comparison number: %d\n", strcomp);
}