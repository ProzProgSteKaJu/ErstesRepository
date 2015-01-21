#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    unsigned long int p=13, q=17;
    unsigned long int N, Phi, e, d;

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


    printf("Geben Sie bitte den Text ein:\n");
    fgets(input, 200, stdin);

    for(i=0;*(input+i);i++){
        textlength = i;
    }
    coded_text = (char*) malloc(textlength*sizeof(char));
    decoded_text = (char*) malloc(textlength*sizeof(char));
    coded_numbers = (unsigned long int*) malloc(textlength*sizeof(unsigned long int));
    decoded_numbers = (unsigned long int*) malloc(textlength*sizeof(unsigned long int));

    printf("\nMit RSA verschluesselt lautet Ihr Text:\n");
    for(i = 0; i < textlength; i++){
        *(coded_numbers+i) = codingsingle(*(input+i), e, N);
        *(coded_text+i)=make_ascii_letter(*(coded_numbers+i));
        printf("%c", *(coded_text+i));
    }

    printf("\n\nWieder entschluesselt lautet der Text:\n");
    for(i = 0; i < textlength; i++){
        *(decoded_numbers+i) = decodingsingle(*(coded_numbers+i), e, N);
        *(decoded_text+i)=*(decoded_numbers+i);
        printf("%c", *(decoded_text+i));
    }

    return 0;
}
