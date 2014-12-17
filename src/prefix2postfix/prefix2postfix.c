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
        oplength=i+1;
    }

    //Alles mit 3 oder mehr Zeichen ist ein Operator, sonst Variable
    if (oplength>=3){
        return oplength;
    }
    else{
        return 0;
    }
}

char* prefix2postfix (char* string){

    //bestimmt die Länge, -1, da bei fgets der zeilenumbruch mitgezählt wird
    int strlength= strlen(string)-1;
    int oplength;
    int i;

    //holt Speicher für das Postfixarray in arr
    char* arr= (char *) malloc(strlength*sizeof(char));

    if (ist_2_op(string)){
        prefix2postfix(arr);
        prefix2postfix(arr);
    }
    if (ist_1_op(string)){
        oplength=ist_1_op(arr);
        //schreibt Operator ans Ende
        *(arr+strlength-oplength-1)=' ';
        for (i=0; i<oplength; i++){
            *(arr+strlength-oplength+i)=*(string+i);
        }
        //Rest wird als 1 Operand angesehen und rekursiv verarbeitet
        prefix2postfix(string + oplength+1);
    }

    return arr;
}

void write(char postfix[], int length){
    int i;
    for (i=0;i<length;i++){
        printf("%c", *(postfix+i));
    }
}

int main(){

    char string[MAX_LENGTH];
    char* postfix;
    int length;

    //liest die Präfixnotation als String ein
    printf("Bitte gib einen Term in Prefixnotation ein:\n");
    fgets(string,MAX_LENGTH, stdin);

    //bestimmt die Länge, -1, da bei fgets der zeilenumbruch mitgezählt wird
    length= strlen(string)-1;

    //postfix=prefix2postfix(string);
    write(string, length);

    return 0;
}
