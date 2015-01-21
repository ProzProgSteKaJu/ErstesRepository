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

int main(){

    unsigned long int p=13, q=17;
    unsigned long int N, Phi, e, d, cipher, message, test;

    N = p*q;
    Phi = (p-1)*(q-1);
    //Waehle 1<e<Phi mit e teilerfremd zu Phi
    e = 23;
    //e*d=1 mod Phi here: d=167
    d = find_d(e,Phi);

    message = 5;
    cipher = codingsingle(message, e,N);
    test = decodingsingle(cipher, d, N);

    printf("message:%lu e:%lu N:%lu\ncipher: %lu\ntest: %lu\n", message, e, N, cipher, test);

    return 0;
}
