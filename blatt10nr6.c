#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

char* hashtab[SIZE];

int hashvalue(char* str){
    int sum=0; char* pn=str;
    for(;*pn;sum+=*pn++){}
    sum=sum%SIZE;
    return sum;
}

char** setpointer(char* str){
    int hashval=hashvalue(str);
    char** pn=hashtab+hashval;
    return pn;
}

int main(){
    char Name[]="Klioba";
    char Vorname[]="Katharina";
    char Studiengang[]="Technomathematik";
    char** pn=setpointer(Vorname);

    hashtab[hashvalue(Name)]=Name;
    *pn=Vorname;
    hashtab[hashvalue(Studiengang)]=Studiengang;

    printf("hashtab[%d]=%s\n", hashvalue(Name), hashtab[hashvalue(Name)]);
    printf("hashtab[%d]=%s\n", hashvalue(Vorname), hashtab[hashvalue(Vorname)]);
    printf("hashtab[%d]=%s\n", hashvalue(Studiengang), hashtab[hashvalue(Studiengang)]);

    return 0;
}
