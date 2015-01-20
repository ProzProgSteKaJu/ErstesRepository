#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int power(unsigned long int basis, unsigned long int exponent, unsigned int mod){
    int i,res;
    res=1;
    for(i=0;i<exponent;i++){
        res*=basis;
        res = res % mod;
    }
    return res;
}

int main(){
    unsigned long int a,b;
    unsigned long int N,d;
    a=76;
    b=7;
    N=187;
    d=power(a,b, N);
    printf("%lu correct would be 32", d);

    return 0;
}
