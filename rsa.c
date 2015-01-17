#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a,b;
    int c,d;
    a=7;
    b=2;
    c=(int) pow(a,b);
    d= c%5;
    printf("%d", d);

    return 0;
}
