#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* function cesarc
** input:
**      char* cleartext: includes the text that has to be coded
**      int textlength: length of the cleartext
**      char key: letter that is used as a key letter for cesar, key shall be an uppercase letter
** output:
**      char* including the coded text
** functionality:
**      codes the cleartext by shifting all letters by key-'A',
**      which means that A is coded to the key letter.
**     */
char* cesarc(char* cleartext, int textlength, char key){

    /*local variables:
    *   count: int, counting varibale used for loop
    *   shift: int, shift needed for cesar coding
    *   code: char*, contains coded text that is returned */
    int count;
    int shift = key-'A';
    char* code = (char*) malloc(textlength*sizeof(char));

    /* shifts the cleartext-letters by shift until the end of the alphabet is reached,
    *  then starts again 26 letters before*/
    for(count = 0; count < textlength; count++){
        if (count+shift<26){
            *(code+count) = (char) *(cleartext+count)+shift;
        }
        else{
            *(code+count) = (char) *(cleartext+count)+shift-26;
        }
    }

    return code;
}

int main(){

    char key='D';
    char* text; char* code;
    int i;

    for (i=0;i<26;i++){
        *(text+i)='a'+i;
        printf("%c", *(text+i));
    }
    printf("\n");
    code=cesarc(text, 26, key);

    for (i=0;i<26;i++){
        printf("%c", *(code+i));
    }

    return 0;
}
