#include <stdio.h>
#include <string.h>

#define HEX 1
#define BINARY 2
#define DECIMAL 3
#define OCTAL 4
#define INVALID 5

/*
This is the atoi function we went over in class.
You can use it to convert an array of characters to 
a decimal value.
You should modify it to return -1 if s contains a 
character other than the digits 0 through 9 and 
the null terminator
 */
int a10toi(char s[]) {
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    n = 10 * n + (s[i] - '0');
  }
  if(s[i] != '\0'){
    return -1;
  }
  return n;
}

/*
This function should convert the value in the character
array s, which is assumed to be a binary value, to a 
decimal equivalent.
It should return -1 if s contains any character other than 0 or 1,
after the initial 0b
*/
int a2toi(char s[]) {
    int i, n;

    n = 0;
    for (i = 2; s[i] == '0' || s[i] == '1'; i++) {
        n = 2 * n + (s[i] - '0');
    }
    if(s[i] != '\0'){
       return -1;
    }
    // printf("The value of n is %d\n", n);
    return n;
}

/*
This function should convert the value in the character
array s, which is assumed to be an octal value, to a 
decimal equivalent
It should return -1 if s contains any character not in the range
'0' to '7'
*/
int a8toi(char s[]) {
    int i, n;

    n = 0;
    for (i = 1; s[i] >= '0' && s[i] <= '7'; i++) {
        n = 8 * n + (s[i] - '0');
    }
    if(s[i] != '\0'){
        return -1;
    }
    return n;
}

/*
This function should convert the value in the character
array s, which is assumed to be an hexadecimal value, to a 
decimal equivalent
It should return -1 if s contains any character that isn't 
either between '0' and '9' or 'A' and 'F' after the initial
0x.
*/
int a16toi(char s[]) {
    int i, n;

    n = 0;
    for (i = 2; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z'); i++) {
        n = 16 * n + (s[i] - '0');
    }
    if(s[i] != '\0'){
        return -1;
    }
    return n;
}

/*
This function should convert the int value in integer 
to its equivalent binary representation, storing that 
value into the character array named binary.  Be sure 
to add a null terminator to binary.
*/
void toBinary(int integer, char binary[]) {

    int i = 0;
    while(integer > 0){
        int c = integer % 2;
        binary[i] = c + '0';
        integer = integer / 2;
        i++;
        // printf("%d, %c\n", integer, binary[i]);
    }
    binary[i] = '\0';
    // printf("%s", binary);
}

/*
This function should convert the int value in integer 
to its equivalent octal representation, storing that 
value into the character array named octal.  Be sure 
to add a null terminator to octal.
*/
void toOctal(int integer, char octal[]) {

    char revOct[9];
    int ind = 0;
    while(integer != 0){
        int c = integer % 8;
        revOct[ind] = c + '0';
        // printf("Octal: %c\n", revOct[ind]);
        integer = integer / 8;
        ind++;
    }

    //store the octal number in reverse order
    int count = 0;
    for(int i = ind -1; i >= 0; i--){
        octal[count] = revOct[i];
        // printf("Res: %c\n", octal[count]);
        count++;
    }
    octal[count] = '\0';
    // printf("final result: %s\n", octal);
}

/*
This function should convert the int value in integer 
to its equivalent decimal representation, storing that 
value into the character array named decimal.  Be sure 
to add a null terminator to decimal.
*/
void toDecimal(int integer, char decimal[]) {
    int num = integer;
    int digit = 0;
    //find how many digits are in the number
    while (num) {
        digit++;
        num /= 10;
    }

    char revDec[digit];
    int ind = 0;
    while(integer){
        int c = integer % 10;
        revDec[ind] = c + '0';
        integer /= 10;
    }

    int i;
    for (i = 0; i < ind; i++) {
        decimal[i] = revDec[ind - i];
    }
    decimal[i] = '\0';
    // printf("Decimal array: %s\n", decimal);

}

/*
This function should convert the int value in integer 
to its equivalent hexadecimal representation, storing that 
value into the character array named hex.  Be sure 
to add a null terminator to hex.
*/
void toHex(int integer, char hex[]) {
    char revHex[9];
    int ind = 0;
    while(integer != 0){
        int c = integer % 16;
        // printf("Val of C: %d\n", c);
        revHex[ind] = c + '0';
        // printf("Hex Index: %c\n", revHex[ind]);
        integer = integer / 16;
        ind++;
    }
    revHex[ind] = '\0';

    for(int j = 0; j != '\0'; j++){
        if(revHex[j] >= 10){
            switch (revHex[j])
            {
            case 10:
                revHex[j] = 'A';
                break;
            
            case 11:
                revHex[j] = 'B';
                break;

            case 12:
                revHex[j] = 'C';
                break;

            case 13:
                revHex[j] = 'D';
                break;

            case 14:
                revHex[j] = 'E';
                break;
            
            case 15:
                revHex[j] = 'F';
                break;
            }
        }
        else{
            revHex[j] = revHex[j] + '0';
            // printf("Val 2 of revH is %c", revHex[j]);
        }
    }

    //store the hex number in reverse order
    int count = 0;
    for(int i = ind -1; i >= 0; i--){
        hex[count] = hex[i]; 
        count++;
    }
    hex[count] = '\0';
    // printf("Converted Array: %s\n", hex);
}

int main(int argc, char *argv[])
{
    //  Declare a character array named converted that is large enough to hold 
    //  the largest possible output value, along with a null 
    //  terminator

    char converted[9];

    //  Validate there are at least 2 command line arguments
    //  If not, print an error message and return 1

    if(argc < 3){
        printf("At least 2 command line arguments must be supplied\n");
        printf("Usage: convert.exe binary|octal|decimal|hex num1 [num2 num3 ... num2]\n");
        return 1;
    }

    //  Validate the first command line argument has a 
    //  value representing a valid output format.  
    //  If not, print an error message and return 2

    char* conv = argv[1];
    if((strcmp(conv, "decimal") != 0) && (strcmp(conv, "hex") != 0) && (strcmp(conv, "binary") != 0) && (strcmp(conv, "octal") != 0)){
        printf("First argument must be hex, decimal, binary, or octal\n");
        return 2;
    }

    int i;
    int integer;
    int state = 0;
    for(i = 2; i < argc; i++){

        //decide the state of the number (hex, dec, bin, oct, etc)
        char* argValue = argv[i];
        char car = argValue[0];
        char car2 = argValue[1];
        
        // printf("argValue is %s\ncar1 is %d\ncar2 is %d\n", argValue, car, car2);
        switch (car)
        {
        case '0':
            switch (car2)
            {
            case 'b':
                // printf("Bin 1\n");
                state = BINARY;
                integer = a2toi(argValue);
                break;

            case 'x':
                // printf("Hex 2\n");
                state = HEX;
                integer = a16toi(argValue);
                break;

            default:
                // printf("Oct 3\n");
                state = OCTAL;
                integer = a8toi(argValue);
                break;
            }
        default:
            break;
        }
        if(car >= '0' && car <= '9' && state == 0){
            // printf("Dec 4\n");
            state = DECIMAL;
            integer = a10toi(argValue);
        }
        else if(state == 0){
            // printf("Inv 5\n");
            state = INVALID;
        }

        // printf("Current state %d\n", state);
        //decide what to do with each state, convert depending on argv[1]

        if(strcmp(argv[1], "decimal") == 0){
            toDecimal(integer, converted);
            // printf("%s (decimal) -> ", argValue);
        }
        else if(strcmp(argv[1], "octal") == 0){
            toOctal(integer, converted);
            // printf("%s (octal) -> ", argValue);
        }
        else if(strcmp(argv[1], "binary") == 0){
            toBinary(integer, converted);
            // printf("%s (binary) -> ", argValue);
        }
        else if(strcmp(argv[1], "hex") == 0){
            toHex(integer, converted);
            // printf("%s (hex) -> ", argValue);
        }

        switch (state)
        {
        case INVALID:
            // printf("Case 1\n");
            printf("%s -> Invalid number", argValue);
            break;

        case BINARY:
            // printf("Case 2\n");
            // toBinary(integer, converted);
            printf("%s (binary) -> ", argValue);
            break;
        
        case OCTAL:
            // printf("Case 3\n");
            // toOctal(integer, converted);
            printf("%s (octal) -> ", argValue);
            break;

        case HEX:
            // printf("Case 5\nConverted: %s", converted);
            // toHex(integer, converted);
            printf("%s (hex) -> ", argValue);
            break;

        case DECIMAL:
            // printf("Case 6\n");
            // toDecimal(integer, converted);
            printf("%s (decimal) -> ", argValue);
            break;
        }

        if(strcmp(argv[1], "decimal") == 0){
            printf("%d (%s)\n", integer, argv[1]);
        }
        else if(state != INVALID && integer != -1 && state != DECIMAL){
            printf("%s (%s)\n", converted, argv[1]);
        }
        //  printf("State is %d\nInteger is %d\n\n", state, integer);

    }

    //  For each command line argument after the first one
        //  Determine the type of value based on the first 1 or 2 characters

        //  Convert the number into its decimal representation

        //  Call the appropriate toXX function to convert the number to the 
        //  desired output format, storing the result in the 
        //  array named converted 

        //  Output the result of the conversion.
}

