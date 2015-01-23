#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define CESAR 1
#define VIGENERE 2
#define RSA 3
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
        printf("Bitte geben Sie einen Buchstaben als Schluessel ein!\n");
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

char* codecesar(char* message, char key){
/* function codecesar *****************************************************************************
**
** Codecesar codes a text by using the cesar chiffre with the same key for the whole text.
** Cesar shifts a/A to the lower/upper case key letter and then continues with the alphabet
** until z/z is reached, then starts agin with a/A.
**
** needs: codesingle, IsUpperCase, IsLowerCase
**
** input:
**      char* message: text that will be coded
**      char key: A will be shifted to Uppercase(key)
** output:
**      char* that contains the coded text
**
****************************************************************************************************/

    //i for counting, textlength for length of message, codetext will be returned
    int i, textlength;
    char* codetext;

    //counts textlength because message ends with \0
    //increases textlength by 1, because an additional char is needed for the codetext to end
    for(i = 0; *(message+i); i++){
        textlength = i + 1;
    }
    textlength++;

    //allocates memory for the coded text
    codetext = (char*) malloc(textlength * sizeof(char));

    //Codes every single char of message with codesingle
    for(i=0; *(message+i); i++){
        *(codetext+i) = codesingle(*(message+i), key);
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

    //i for counting, textlength for length of codetext, message will be returned
    int i, textlength;
    char* message;

    //counts textlength because message ends with \0
    //increases textlength by 1, because an additional char is needed for the message to end
    for(i = 0; *(codetext+i); i++){
        textlength = i + 1;
    }
    textlength++;

    //allocates memory for the decoded text
    message = (char*) malloc(textlength * sizeof(char));

    //Decodes every single char of message with decodesingle
    for(i=0; *(codetext+i); i++){
        *(message+i) = decodesingle(*(codetext+i), key);
    }
    //Ends the codetext with \0
    *(message+textlength-1) = '\0';

    return message;
} /*Decodecesar*/

char* codevigenere(char* message, char* keyword){
/* function codevigenere *****************************************************************************
**
** Codevigenere codes a text by using the polyalphabetical cesar chiffre with a keyword.
** The first letter of keyword will be used to code the first letter of message with cesar,
** the 2nd for the 2nd, ..., starts again with the first letter of keyword when the end is reached.
**
** needs: codesingle, IsUpperCase, IsLowerCase
**
** input:
**      char* message: text that will be coded
**      char* keyword: contains the different key letters
** output:
**      char* that contains the coded text
**
****************************************************************************************************/

    //codetext for the result, keyletter for the char in keyword that is used
    //i for counting, textlength for length of message, keylength for length of keyword
    char* codetext;
    char keyletter;
    int i, textlength, keylength;

    //counts textlength while *(message+i) because message ends with \0
    //increases textlength by 1, because an additional char is needed for the codetext to end
    for(i = 0; *(message+i); i++){
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
    for(i=0; *(message+i); i++){
        keyletter = *(keyword+(i%keylength));
        *(codetext+i) = codesingle(*(message+i), keyletter);
    }
    //ends the codetext
    *(codetext+textlength-1) = '\0';

    return codetext;
}/*codevigenere*/

char* decodevigenere(char* codetext, char* keyword){
/* function decodevigenere *****************************************************************************
**
** Decodevigenere decodes a text by using the polyalphabetical cesar chiffre with a keyword.
** The first letter of keyword will be used to decode the first letter of message with cesar,
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

    //message for the result, keyletter for the char in keyword that is used
    //i for counting, textlength for length of codetext, keylength for length of keyword
    char* message;
    char keyletter;
    int i, textlength, keylength;

    //counts textlength while *(codetext+i) because codetext ends with \0
    //increases textlength by 1, because an additional char is needed for the cmessage to end
    for(i = 0; *(codetext+i); i++){
        textlength = i + 1;
    }
    textlength++;
    //counts keylength
    for(i = 0; *(keyword+i); i++){
        keylength = i + 1;
    }

    //allocates memory for message
    message = (char*) malloc(textlength * sizeof(char));

    //Decoding here, keyletter is nr. i%keylength of keyword
    for(i=0; *(codetext+i); i++){
        keyletter = *(keyword+(i%keylength));
        *(message+i) = decodesingle(*(codetext+i), keyletter);
    }
    //ends the message
    *(message+textlength-1) = '\0';


    return message;
}/*decodevigenere*/

/**************************************
RSA
**************************************/

unsigned long int modulopower(unsigned long int basis, unsigned long int exponent, unsigned int mod){
    unsigned long int i,res;
    res=1;

    for(i=0;i<exponent;i++){
        res*=basis;
        res = res % mod;
    }
    return res;
}

unsigned long int find_d(unsigned long int e, unsigned long int Phi){

    unsigned long int d=1;
    int i;

    for(i=0;(e*d)%Phi!=1; i++){
        d++;
    }

    return d;
}

unsigned long int codingsingle(int message, unsigned long int e, unsigned long int N){
    //c=m^e mod N
    int cipher;
    cipher = modulopower(message,e,N);
    return cipher;
}

unsigned long int decodingsingle(int cipher, unsigned long int d, unsigned long int N){
    //m=c^d mod N
    int message;
    message = modulopower(cipher,d,N);
    return message;
}

unsigned long int make_ascii_letter(unsigned long int letter){

    unsigned long int ascii=letter;
    unsigned long int i;

    if(letter>90){
        for(i=1;ascii>90;i++){
            ascii -= 26;
        }
    }

    if(letter<65){
        for(i=1;ascii<65;i++){
            ascii += 26;
        }
    }

    return ascii;
}

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
    char message[] = "Marmelade schmeckt echt gut!";
    char keyword[] = "ABCD";
    char* codetext;
    char* decodedtext;

    codetext = codevigenere(message, keyword);
    printf("\nVIGENERE-CODIERUNG\n%s wird mit dem Schluesselwort %s codiert zu\n%s\n", message, keyword, codetext);

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
    char* messagecesar;
    char* messagevigenere;
    char keyletter;
    int chosenmethod, chosendirection;

    printf("\n Mit welcher Methode wollen Sie verschluesseln?\n 'C': Caesarcode\n 'V': Vigenere-Verschluesselung\n 'R': RSA-Verschluesselung\n ");
    fgets(method, 3, stdin);

    switch(*(method)){
        case 'C': chosenmethod = CESAR; break;
        case 'V': chosenmethod = VIGENERE; break;
        case 'R': chosenmethod = RSA; break;
        default: printf(" FALSCHE EINGABE: bitte C oder V eingeben!\n"); break;
    }

    if(method[0] != 'R'){
        printf("\n Wollen Sie codieren oder decodieren?\n 'c': Codieren\n 'd': Decodieren\n ");
        fgets(direction, 3, stdin);
    }

    if(method[0] != 'R'){
        switch(*(direction)){
            case 'c': chosendirection = CODING; break;
            case 'd': chosendirection = DECODING; break;
            default: printf(" FALSCHE EINGABE: bitte c oder d eingeben!\n "); break;
        }

    switch(chosendirection){
        case CODING:    printf("\n Bitte geben Sie den zu verschluesselnden Text ein:\n ");
                        fgets(message, 200, stdin);
                        switch(chosenmethod){
                            case CESAR: printf("\n Bitte geben Sie den Schluesselbuchstaben ein:\n ");
                            fgets(key, 3, stdin);
                            keyletter = *(key);
                            codetextcesar = codecesar(message, keyletter);
                            printf("\n Verschluesselt ist dies:\n%s\n ", codetextcesar);
                            break;

                            case VIGENERE: printf("\n Bitte geben Sie das Schluesselwort ein:\n ");
                            fgets(keyword, 30, stdin);
                            codetextvigenere = codevigenere(message, keyword);
                            printf("\n Verschluesselt ist dies:\n%s\n ", codetextvigenere);
                            break;

                            default: printf("Error!"); break;
                        }
                        break;
        case DECODING:  printf(" Bitte geben Sie den zu entschluesselnden Text ein:\n");
                        fgets(cipher, 200, stdin);
                        switch(chosenmethod){
                            case CESAR: printf("\n Bitte geben Sie den Schluesselbuchstaben ein:\n ");
                            fgets(key, 3, stdin);
                            keyletter = *(key);
                            messagecesar = decodecesar(cipher, keyletter);
                            printf("Entschluesselt ist dies:\n%s\n ", messagecesar);
                            break;

                            case VIGENERE: printf("\n Bitte geben Sie das Schluesselwort ein:\n ");
                            fgets(keyword, 30, stdin);
                            messagevigenere = decodevigenere(cipher, keyword);
                            printf(" Entschluesselt ist dies:\n%s\n ", messagevigenere);
                            break;

                            default: printf("Error!"); break;
                        } break;
        default: printf("Error"); break;
    }
    }
    else{
/**********************RSA******************************/
        unsigned long int p=13, q=17;
        unsigned long int N, Phi, e, d;
    /*int Primes[20];
    int Number;

    Primes[0] = 2;
    Primes[1] = 3;
    Primes[2] = 5;
    Primes[3] = 7;
    Primes[4] = 11;
    Primes[5] = 13;
    Primes[6] = 17;
    Primes[7] = 19;
    Primes[8] = 23;
    Primes[9] = 29;
    Primes[10] = 31;
    Primes[11] = 37;
    Primes[12] = 41;
    Primes[13] = 43;
    Primes[14] = 47;
    Primes[15] = 53;
    Primes[16] = 59;
    Primes[17] = 61;
    Primes[18] = 67;
    Primes[19] = 71;

        srand(time(NULL));
        Number = rand()%20;
        p = Primes[Number];
        printf("%d\n", Number);
        printf("%d", i);
        srand(time(NULL));
        Number = rand()%20;
        q = Primes[Number];
        printf("%d\n", Number);
        printf("%d", i);

        */

        //initialization of N,Phi,e and d
        N = p*q;
        Phi = (p-1)*(q-1);
        e = 23;
        d = find_d(e,Phi);


        char input[200];
        char* coded_text;
        char* decoded_text;
        int i, textlength;
        unsigned long int* coded_numbers;
        unsigned long int* decoded_numbers;


        printf("\n Geben Sie bitte den Text ein:\n ");
        fgets(input, 200, stdin);

        for(i=0;*(input+i);i++){
            textlength = i;
        }
        coded_text = (char*) malloc(textlength*sizeof(char));
        decoded_text = (char*) malloc(textlength*sizeof(char));
        coded_numbers = (unsigned long int*) malloc(textlength*sizeof(unsigned long int));
        decoded_numbers = (unsigned long int*) malloc(textlength*sizeof(unsigned long int));

        printf("\n Mit RSA verschluesselt lautet Ihr Text:\n ");
        for(i = 0; i < textlength; i++){
            *(coded_numbers+i) = codingsingle(*(input+i), e, N);
            *(coded_text+i)=make_ascii_letter(*(coded_numbers+i));
            printf("%c", *(coded_text+i));
        }

        printf("\n\n Wieder entschluesselt lautet der Text:\n ");
        for(i = 0; i < textlength; i++){
            *(decoded_numbers+i) = decodingsingle(*(coded_numbers+i), e, N);
            *(decoded_text+i)=*(decoded_numbers+i);
            printf("%c", *(decoded_text+i));
        }
    }
    return 0;
}
