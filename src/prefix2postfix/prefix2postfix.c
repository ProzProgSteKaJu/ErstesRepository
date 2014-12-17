#include <stdio.h>
//#include "Header.h"
#define MAX_LENGTH 42
#define MAX_OPERATOR 6

int ist_2_op(char * arr){
    //liest erstes Zeichen in arr aus und
    //überprüft, ob es ein 2-Operator (+-*/) ist
    char content=*(arr);
    switch(content){
        case '+': return 1;
        case '-': return 1;
        case '*': return 1;
        case '/': return 1;
        default: return 0;
    }
}

int ist_1_op(char * arr){

    char op[MAX_OPERATOR];
    int oplength;
    int i;

    //liest die ersten zusammenhängenden Zeichen ein
    for (i=0; ((*(arr+i)!=' ')&&(i<MAX_OPERATOR)); i++){
        op[i]=*(arr+i);
        oplength=i;
    }

    //Alles mit 3 oder mehr Zeichen ist ein Operator, sonst Variable
    if (oplength>=2){
        return 1;
    }
    else{
        return 0;
    }
}

void write(char postfix[], int length){
    int i;
    for (i=0;i<length;i++){
        printf("%c", *(postfix+i));
    }
}

char* prefix2postfix (char string[MAX_LENGTH]){

    //bestimmt die Länge, -1, da bei fgets der zeilenumbruch mitgezählt wird
    int strlength= strlen(string)-1;

    //holt Speicher für das Postfixarray in arr
    char* arr= (char *) malloc(strlength*sizeof(char));
    //arr=read(string);

    if (ist_2_op(arr)){
        prefix2postfix(arr);
        prefix2postfix(arr);
    }
    if (ist_1_op(arr)){
        prefix2postfix(arr);
    }

    return arr;
}

int main(){

    char string[MAX_LENGTH];
    char* postfix;
    int length;

    //liest die Präfixnotation als String ein
    printf("Bitte gib einen Term in Prefixnotation ein:\n");
    //bestimmt die Länge, -1, da bei fgets der zeilenumbruch mitgezählt wird
    fgets(string,MAX_LENGTH, stdin);
    length= strlen(string)-1;

    //postfix=prefix2postfix(string);
    write(string, length);

    return 0;
}
