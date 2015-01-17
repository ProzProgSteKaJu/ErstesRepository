#include <stdio.h>
#include <stdlib.h>

int main(){
    char* method;
    char* direction;
    char test;

    printf("Mit welcher Methode wollen Sie verschluesseln?\n'C': Caesarcode\n'V': Vigenere-Verschluesselung\n");
    fgets(&method, 10, stdin);

    printf("\nWollen Sie codieren oder decodieren?\n'c': Codieren\n'd': Decodieren\n");
    fgets(&direction, 3, stdin);

    printf("%s", method);
    return 0;
}
