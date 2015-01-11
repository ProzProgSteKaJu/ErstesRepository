#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int IsUpperCase(char letter){
/* function IsUpperCase ***************************************************************************
**
** checks if a letter is an uppercase letter (quite obvious)
**
** input:
**      char letter: letter that is checked
** output:
**      1 if letter is uppercase, 0 else
**
*************************************************************************************************/
    if (('A' <= letter)&&(letter <= 'Z')){
        return 1;
    }
    else{
        return 0;
    }
} /*IsUpperCase*/

int IsLowerCase(char letter){
/* function IsLowerCase ***************************************************************************
**
** checks if a letter is an lowercase letter (quite obvious)
**
** input:
**      char letter: letter that is checked
** output:
**      1 if letter is lowercase, 0 else
**
*************************************************************************************************/
    if (('a' <= letter)&&(letter <= 'z')){
        return 1;
    }
    else{
        return 0;
    }
} /*IsLowerCase*/

char codesingle(char clear, char key){
/* function codesingle *****************************************************************************
**
** Codesingle codes a clear letter by UpperCase(key)-'A' and returns the coded char.
** Any char will be accepted for clear, only letters for key, else clear will be returned
**
** input:
**      char clear: letter that will be coded
**      char key: A will be shifted to Uppercase(key)
** output:
**      char that contains the coded char
**
****************************************************************************************************/

    //shift is the difference between key and a/A
    //letternumber is the difference between clear and a/A, used to check if backshift is neccessary
    int shift, letternumber;

    // initialization of shift depending on whether key is upper or lower case
    // returns the clear char if key is not a letter*/
    if ((IsLowerCase(key) == 0) && (IsUpperCase(key) == 0)){
        printf("Bitte geben Sie einen Buchstaben als Schluessel ein!");
        return clear;
    }
    if (IsUpperCase(key)){
        shift = key - 'A';
    }
    if (IsLowerCase(key)){
        shift = key - 'a';
    }
    // initialization of letternumber depending on whether clear is uppercase, lowercase or none of both
    // if clear is not a letter, backshift won't be considered*/
    if (IsUpperCase(clear)){
        letternumber = clear-'A';
    }
    if (IsLowerCase(clear)){
        letternumber = clear-'a';
    }
    if ((IsUpperCase(clear) == 0)&&(IsLowerCase(clear) == 0)){
        letternumber = 0;
    }

    //returns shifted clear
    if (shift+letternumber<26){
        return clear+shift;
    }
    //backshift if a char behind z/Z would be reached
    else{
        return clear+shift-26;
    }
} /*codesingle*/

int main(){

    int i,j;
    char clear='A', key='a', code;

    //Tests, if Singlecode works for lower case key letters
    for (j=0;key<='z';j++){
        printf("\nSchluesselbuchstabe: %c\n", key);
        for(i=0;clear<='z';i++){
            code=codesingle(clear, key);
            printf("%c -> %c\t", clear, code);
            clear++;
        }
        key++;
        clear='A';
    }

    //Tests, if Singlecode works for upper case key letters
    key='A';
    for (j=0;key<='Z';j++){
        printf("\nSchluesselbuchstabe: %c\n", key);
        for(i=0;clear<='z';i++){
            code=codesingle(clear, key);
            printf("%c -> %c\t", clear, code);
            clear++;
        }
        key++;
        clear='A';
    }

    return 0;
}
