#include <stdio.h>
#include "Header.h"

char *print_postfix(char string[]){

    //Determine length of prefn

}

int main(){
    char prefixnotation[MAX_LENGTH];

    //Reading the input in prefixnotation
    printf("Geben Sie bitte einen Code in Praefixnotation ein:\n");
    gets(prefixnotation);

    //Calculation and Output of the postfixnotation
    printf("Dies ist der Code in Postfixnotation:\n");
    print_postfix(prefixnotation);

    return 0;
}
