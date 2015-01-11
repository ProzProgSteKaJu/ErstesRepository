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
** Codesingle shifts a clear letter by UpperCase(key)-'A' and returns the coded char.
** If the end of the alphabet is reached, clear will be shifted backwards.
** Any char will be accepted for clear and key, but if clear is not a letter, it will be returned as it is,
** if key is not a letter, any clear letter will be returned as it is
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
    // returns the clear char if key is not a letter
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
        return clear;
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

char decodesingle(char code, char key){
/* function decodesingle *****************************************************************************
**
** Decodesingle shifts a code letter by UpperCase(key)-'A' backwards and returns the decoded char.
** If the end of the alphabet is reached, code will be shifted forwards.
** Any char will be accepted for code and key, but if code is not a letter, it will be returned as it is,
** if key is not a letter, any code will be returned as it is
**
** input:
**      char code: letter that will be decoded
**      char key: Uppercase(key) will be shifted to A
** output:
**      char that contains the decoded char
**
****************************************************************************************************/

    //shift is the difference between key and a/A
    //letternumber is the difference between code and a/A, used to check if shifting forwards is neccessary
    int shift, letternumber;

    // initialization of shift depending on whether key is upper or lower case
    // returns the code char if key is not a letter*/
    if ((IsLowerCase(key) == 0) && (IsUpperCase(key) == 0)){
        printf("Bitte geben Sie einen Buchstaben als Schluessel ein!");
        return code;
    }
    if (IsUpperCase(key)){
        shift = key - 'A';
    }
    if (IsLowerCase(key)){
        shift = key - 'a';
    }
    // initialization of letternumber depending on whether code is uppercase, lowercase or none of both
    // if code is not a letter, code will be returned
    if (IsUpperCase(code)){
        letternumber = code-'A';
    }
    if (IsLowerCase(code)){
        letternumber = code-'a';
    }
    if ((IsUpperCase(code) == 0)&&(IsLowerCase(code) == 0)){
        return code;
    }

    //returns code shifted backwards
    if (letternumber>=shift){
        return code-shift;
    }
    //returns code shifted forwards
    else{
        return code-shift+26;
    }
} /*decodesingle*/

int main(){

    int i,j;
    char clear='A', key='a', code, decode;

    //Tests, if Codesingle and  decodesingle work for lower case key letters
    for (j=0;key<='e';j++){
        printf("\nSchluesselbuchstabe: %c\n", key);
        for(i=0;clear<='z';i++){
            code=codesingle(clear, key);
            printf("%c -> %c", clear, code);
            decode=decodesingle(code, key);
            printf(" -> %c\t", decode);
            clear++;
        }
        key++;
        clear='A';
    }

    //Tests, if codesingle and decodesingle work for upper case key letters
    key='A';
    for (j=0;key<='D';j++){
        printf("\nSchluesselbuchstabe: %c\n", key);
        for(i=0;clear<='z';i++){
            code=codesingle(clear, key);
            printf("%c -> %c", clear, code);
            decode=decodesingle(code, key);
            printf(" -> %c\t", decode);
            clear++;
        }
        key++;
        clear='A';
    }

    return 0;
}
