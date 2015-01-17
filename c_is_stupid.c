#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a,b;
    int c,d;
    a=76;
    b=7;
    c=(int) pow(a,b);
    d= c%187;
    printf("%d correct would be 32", d);

    return 0;
}
