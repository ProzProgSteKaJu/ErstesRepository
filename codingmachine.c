#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int IsUpperCase(char letter){
    if (('A' <= letter)&&(letter <= 'Z')){
        return 1;
    }
    else{
        return 0;
    }
}

int IsLowerCase(char letter){
    if (('a' <= letter)&&(letter <= 'z')){
        return 1;
    }
    else{
        return 0;
    }
}

char cesarsinglec(char clear, char key){

    int shift = key-'A';
    int letternumber;

    if (IsUpperCase(clear)){
        letternumber = clear-'A';
    }
    if (IsLowerCase(clear)){
        letternumber = clear-'a';
    }
    if ((IsUpperCase(clear) == 0)&&(IsLowerCase(clear) == 0)){
        letternumber = 0;
    }

    if (shift+letternumber<26){
        return clear+shift;
    }
    else{
        return clear+shift-26;
    }
}

char* cesarc(char* cleartext, int textlength, char key){
/* function cesarc *******************************************************************************
**
** input:
**      char* cleartext: includes the text that has to be coded
**      int textlength: length of the cleartext
**      char key: letter that is used as a key letter for cesar, key shall be an uppercase letter
** output:
**      char* includes the coded text
** functionality:
**      codes the cleartext by shifting all letters by key-'A' forwards,
**      which means that A is coded to the key letter.
**
*************************************************************************************************/
        for(i=0; cleartext[i]=0; i++){
                textlength = i;
        }


    int count;
    char* code = (char*) malloc(textlength*sizeof(char));

    for(count = 0; count < (textlength-1); count++){
        *(code+count)=cesarsinglec(*(cleartext+count), key);
        printf("%c", *(code+count));
    }

    return code;
}

char* cesard(char* codetext, int textlength, char key){
/* function cesard *******************************************************************************
**
** input:
**      char* codetext: includes the text that has to be decoded
**      int textlength: length of the codetext
**      char key: letter that is used as a key letter for cesar, key shall be an uppercase letter
** output:
**      char* includes the cleartext
** functionality:
**      decodes the codetext by shifting all letters backwards by key-'A',
**      which means that A is coded to the key letter.
**
*************************************************************************************************/

    /*local variables:
    *   count: int, counting varibale used for loop
    *   shift: int, shift needed for cesar decoding
    *   code: char*, contains decoded text that is returned */
    int count;
    int shift = key-'A';
    char* cleartext = (char*) malloc(textlength*sizeof(char));

    /* shifts the codetext-letters shift chars backwards until the end of the alphabet is reached,
    *  then starts again 26 letters before*/
    for(count = 0; count < textlength; count++){
        if (count+shift<26){
            *(cleartext+count) = (char) *(codetext+count)-shift;
        }
        else{
            *(cleartext+count) = (char) *(codetext+count)-shift+26;
        }
    }

    return cleartext;
}

/* function vigenerec *******************************************************************************
**
** input:
**      char* cleartext: includes the text that has to be coded
**      int textlength: length of the cleartext
**      char* keyword: key word for vigenere, shall be just uppercase letters
**      int keylength: length of keyword
** output:
**      char* includes the codetext
** functionality:
**      codes the cleartext by shifting all letters backwards by keyword[i]-'A'
**      with i=place in array mod keylength. uses cesarc therefore.
**
*************************************************************************************************/
/* not done yet char* vigenerec(char* cleartext, int textlength, char* keyword, int keylength){

    char* codetext;
    int count;

    for(count=0; count<textlength; count++){
        codetext=cesard(cleartext, 1, *(keyword));
    }

    return codetext;
}*/

int main(){

    char key, clear, coded;
    char* text, code;
    int i;

    key='B';
    printf("Klartext:\n");
    for (i=0;i<25;i++){
        *(text+i)='A'+i;
        printf("%c", *(text+i));
    }
    printf("\n");

    code = cesarc(text, 26, 'F');

    printf("\nCodierter Text:\n");
    for (i=0;i<26;i++){
        //Doesn't work!
        //printf("%c", *(code+i));
        printf("Doesn't work yet! ");
    }

    /*
    printf("Enter clear letter, a space and then the key letter, please:\n");
    scanf("%c %c", &clear, &key);

    coded=cesarsinglec(clear, key);
    printf("\nclear:%c %d key:%c %d coded:%c %d\n", clear, clear, key, key, coded, coded);*/

    return 0;
}
