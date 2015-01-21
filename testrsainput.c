#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){

    char input[200];
    char* input2;
    char coded_text[200];
    char decoded_text[200];
    int i, textlength;
    unsigned long int coded_numbers[200];
    unsigned long int decoded_numbers[200];


    printf("Geben Sie bitte den Text ein:\n");
    fgets(input2, 200, stdin);

    for(i=0;*(input2+i);i++){
        textlength = i+1;
    }
    printf("textlength: %d", textlength);

    input2 = (char*) malloc (textlength*sizeof(char));
    printf("%s", input2);

    return 0;
}
