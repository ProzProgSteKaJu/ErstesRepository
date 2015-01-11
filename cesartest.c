#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int IsUpperCase(char letter){
/* function IsUpperCase ***************************************
**
** checks if a letter is an uppercase letter (quite obvious)
**
** input:
**      char letter: letter that is checked
** output:
**      1 if letter is uppercase, 0 else
**
**************************************************************/
    if (('A' <= letter)&&(letter <= 'Z')){
        return 1;
    }
    else{
        return 0;
    }
} /*IsUpperCase*/

int IsLowerCase(char letter){
/* function IsLowerCase ****************************************
**
** checks if a letter is an lowercase letter (quite obvious)
**
** input:
**      char letter: letter that is checked
** output:
**      1 if letter is lowercase, 0 else
**
****************************************************************/
    if (('a' <= letter)&&(letter <= 'z')){
        return 1;
    }
    else{
        return 0;
    }
} /*IsLowerCase*/

char codesingle(char clear, char key){
/* function codesingle **************************************************************************************
**
** Codesingle shifts a clear letter by UpperCase(key)-'A' and returns the coded char.
** If the end of the alphabet is reached, clear will be shifted backwards.
** Any char will be accepted for clear and key, but if clear is not a letter, it will be returned as it is,
** if key is not a letter, any clear letter will be returned as it is
**
** needs: IsUpperCase, IsLowerCase
**
** input:
**      char clear: letter that will be coded
**      char key: A will be shifted to Uppercase(key)
** output:
**      char that contains the coded char
**
************************************************************************************************************/

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
    if (shift + letternumber < 26){
        return clear + shift;
    }
    //backshift if a char behind z/Z would be reached
    else{
        return clear + shift - 26;
    }
} /*codesingle*/

char decodesingle(char code, char key){
/* function decodesingle *********************************************************************************
**
** Decodesingle shifts a code letter by UpperCase(key)-'A' backwards and returns the decoded char.
** If the end of the alphabet is reached, code will be shifted forwards.
** Any char will be accepted for code and key, but if code is not a letter, it will be returned as it is,
** if key is not a letter, any code will be returned as it is
**
** needs: IsUpperCase, IsLowerCase
**
** input:
**      char code: letter that will be decoded
**      char key: Uppercase(key) will be shifted to A
** output:
**      char that contains the decoded char
**
*********************************************************************************************************/

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
    if (letternumber >= shift){
        return code - shift;
    }
    //returns code shifted forwards
    else{
        return code - shift + 26;
    }
} /*decodesingle*/

char* codecesar(char* cleartext, char key){
/* function codecesar *****************************************************************************
**
** Codecesar codes a text by using the cesar chiffre with the same key for the whole text.
** Cesar shifts a/A to the lower/upper case key letter and then continues with the alphabet
** until z/z is reached, then starts agin with a/A.
**
** needs: codesingle, IsUpperCase, IsLowerCase
**
** input:
**      char* cleartext: text that will be coded
**      char key: A will be shifted to Uppercase(key)
** output:
**      char* that contains the coded text
**
****************************************************************************************************/

    //i for counting, textlength for length of cleartext, codetext will be returned
    int i, textlength;
    char* codetext;

    //counts textlength because cleartext ends with \0
    //increases textlength by 1, because an additional char is needed for the codetext to end
    for(i = 0; *(cleartext+i); i++){
        textlength = i + 1;
    }
    textlength++;

    //allocates memory for the coded text
    codetext = (char*) malloc(textlength * sizeof(char));

    //Codes every single char of cleartext with codesingle
    for(i=0; *(cleartext+i); i++){
        *(codetext+i) = codesingle(*(cleartext+i), key);
    }
    //Ends the codetext with \0
    *(codetext+textlength-1) = '\0';

    return codetext;
} /*Codecesar*/

char* decodecesar(char* codetext, char key){
/* function decodecesar *****************************************************************************
**
** Decodecesar decodes a text by using the cesar chiffre with the same key for the whole text.
** Cesar shifts a/A to the lower/upper case key letter and then continues with the alphabet
** until z/z is reached, then starts agin with a/A. Decodecesar inverts this process.
**
** needs: decodesingle, IsUpperCase, IsLowerCase
**
** input:
**      char* codetext: text that will be decoded
**      char key: Uppercase(key) will be shifted to A
** output:
**      char* that contains the decoded text
**
****************************************************************************************************/

    //i for counting, textlength for length of codetext, cleartext will be returned
    int i, textlength;
    char* cleartext;

    //counts textlength because cleartext ends with \0
    //increases textlength by 1, because an additional char is needed for the cleartext to end
    for(i = 0; *(codetext+i); i++){
        textlength = i + 1;
    }
    textlength++;

    //allocates memory for the decoded text
    cleartext = (char*) malloc(textlength * sizeof(char));

    //Decodes every single char of cleartext with decodesingle
    for(i=0; *(codetext+i); i++){
        *(cleartext+i) = decodesingle(*(codetext+i), key);
    }
    //Ends the codetext with \0
    *(cleartext+textlength-1) = '\0';

    return cleartext;
} /*Decodecesar*/

//still counts empty spaces for coding, e.g. "AA AA" with the keyword "ABC" will be coded into "AB AB", not "AB CA"
//ask Lasse whether that is ok or whether this should be changed
char* codevigenere(char* cleartext, char* keyword){
/* function codevigenere *****************************************************************************
**
** Codevigenere codes a text by using the polyalphabetical cesar chiffre with a keyword.
** The first letter of keyword will be used to code the first letter of cleartext with cesar,
** the 2nd for the 2nd, ..., starts again with the first letter of keyword when the end is reached.
**
** needs: codesingle, IsUpperCase, IsLowerCase
**
** input:
**      char* cleartext: text that will be coded
**      char* keyword: contains the different key letters
** output:
**      char* that contains the coded text
**
****************************************************************************************************/

    //codetext for the result, keyletter for the char in keyword that is used
    //i for counting, textlength for length of cleartext, keylength for length of keyword
    char* codetext;
    char keyletter;
    int i, textlength, keylength;

    //counts textlength while *(cleartext+i) because cleartext ends with \0
    //increases textlength by 1, because an additional char is needed for the codetext to end
    for(i = 0; *(cleartext+i); i++){
        textlength = i + 1;
    }
    textlength++;
    //counts keylength
    for(i = 0; *(keyword+i); i++){
        keylength = i + 1;
    }

    //allocates memory for codetext
    codetext = (char*) malloc(textlength * sizeof(char));

    //Coding here, keyletter is nr. i%keylength of keyword
    for(i=0; *(cleartext+i); i++){
        keyletter = *(keyword+(i%keylength));
        *(codetext+i) = codesingle(*(cleartext+i), keyletter);
    }
    //ends the codetext
    *(codetext+textlength-1) = '\0';

    return codetext;
}/*codevigenere*/

int main(){

    /*int i,j;
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
    }*/

    //tests if codecesar works
    char key2 = 'B';
    char string[] = "Marmelade schmeckt echt gut!";
    char* code2;
    char* decode2;

    code2 = codecesar(string, key2);
    printf("\nCAESAR-CODIERUNG und DECODIERUNG\n%s wird mit dem Schluessel %c codiert zu\n%s\n", string, key2, code2);

    decode2 = decodecesar(code2, key2);
    printf("und wieder entschluesselt zu:\n%s\n", decode2);

    char cleartext[] = "Marmelade schmeckt echt gut!";
    char keyword[] = "ABCD";
    char* code3;

    code3 = codevigenere(cleartext, keyword);
    printf("\nVIGENERE-CODIERUNG\n%s wird mit dem Schluesselwort %s codiert zu\n%s\n", cleartext, keyword, code3);

    return 0;
}
