#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define CESAR 1
#define VIGENERE 2
#define CODING 5
#define DECODING 6

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

char* decodevigenere(char* codetext, char* keyword){
/* function decodevigenere *****************************************************************************
**
** Decodevigenere decodes a text by using the polyalphabetical cesar chiffre with a keyword.
** The first letter of keyword will be used to decode the first letter of cleartext with cesar,
** the 2nd for the 2nd, ..., starts again with the first letter of keyword when the end is reached.
**
** needs: decodesingle, IsUpperCase, IsLowerCase
**
** input:
**      char* codetext: text that will be decoded
**      char* keyword: contains the different key letters
** output:
**      char* that contains the decoded text
**
****************************************************************************************************/

    //cleartext for the result, keyletter for the char in keyword that is used
    //i for counting, textlength for length of codetext, keylength for length of keyword
    char* cleartext;
    char keyletter;
    int i, textlength, keylength;

    //counts textlength while *(codetext+i) because codetext ends with \0
    //increases textlength by 1, because an additional char is needed for the cleartext to end
    for(i = 0; *(codetext+i); i++){
        textlength = i + 1;
    }
    textlength++;
    //counts keylength
    for(i = 0; *(keyword+i); i++){
        keylength = i + 1;
    }

    //allocates memory for cleartext
    cleartext = (char*) malloc(textlength * sizeof(char));

    //Decoding here, keyletter is nr. i%keylength of keyword
    for(i=0; *(codetext+i); i++){
        keyletter = *(keyword+(i%keylength));
        *(cleartext+i) = decodesingle(*(codetext+i), keyletter);
    }
    //ends the cleartext
    *(cleartext+textlength-1) = '\0';

    return cleartext;
}/*decodevigenere*/

int main(){

    /*//tests if codecesar and decodecesar work
    char key = 'B';
    char string[] = "Marmelade schmeckt echt gut!";
    char* code;
    char* decode;

    code = codecesar(string, key);
    printf("CAESAR-CODIERUNG und DECODIERUNG\n%s wird mit dem Schluessel %c codiert zu\n%s\n", string, key, code);

    decode = decodecesar(code, key);
    printf("und wieder entschluesselt zu:\n%s\n", decode);

    //tests if codevigenere and decodevigenere work
    char cleartext[] = "Marmelade schmeckt echt gut!";
    char keyword[] = "ABCD";
    char* codetext;
    char* decodedtext;

    codetext = codevigenere(cleartext, keyword);
    printf("\nVIGENERE-CODIERUNG\n%s wird mit dem Schluesselwort %s codiert zu\n%s\n", cleartext, keyword, codetext);

    decodedtext = decodevigenere(codetext, keyword);
    printf("und wieder entschluesselt zu:\n%s\n", decodedtext);*/
    char method[3];
    char direction[3];
    char message[200];
    char cipher[200];
    char key[3];
    char keyword[30];
    char* codetextcesar;
    char* codetextvigenere;
    char keyletter;
    int chosenmethod, chosendirection;

    printf("Mit welcher Methode wollen Sie verschluesseln?\n'C': Caesarcode\n'V': Vigenere-Verschluesselung\n");
    fgets(method, 3, stdin);

    printf("\nWollen Sie codieren oder decodieren?\n'c': Codieren\n'd': Decodieren\n");
    fgets(direction, 3, stdin);

    switch(*(method)){
        case 'C': chosenmethod = CESAR; break;
        case 'V': chosenmethod = VIGENERE; break;
        default: printf("Falsche Eingabe: bitte C oder V eingeben! "); break;
    }
    switch(*(direction)){
        case 'c': chosendirection = CODING; break;
        case 'd': chosendirection = DECODING; break;
        default: printf("Falsche Eingabe: bitte c oder d eingeben!"); break;
    }

    switch(chosendirection){
        case CODING:    printf("\nBitte geben Sie den zu verschluesselnden Text ein:\n");
                        fgets(message, 200, stdin);
                        switch(chosenmethod){
                            case CESAR: printf("\nBitte geben Sie den Schluesselbuchstaben ein:\n");
                            fgets(key, 3, stdin);
                            keyletter = *(key);
                            codetextcesar = codecesar(message, keyletter);
                            printf("\nVerschluesselt ist dies:\n%s\n", codetextcesar);
                            break;
                            case VIGENERE: printf("\nBitte geben Sie das Schluesselwort ein:\n");
                            fgets(keyword, 30, stdin);
                            codetextvigenere = codevigenere(message, keyword);
                            printf("\nVerschluesselt ist dies:\n%s\n", codetextcesar);
                            break;
                            default: printf("Error!"); break;
                        }
                        break;
        case DECODING:  printf("Bitte geben Sie den zu entschluesselnden Text ein:\n");
                        fgets(cipher, 200, stdin);
                        break;
        default: printf("Error"); break;
    }

    return 0;
}
