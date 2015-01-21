#include <stdio.h>
#include <stdlib.h>

int CheckPrime(int Number){

    int i;
    int status = 1;

    for (i = 2; i <= Number - 1; i++){
        if (Number % i == 0){
            status = 0; break;
        }
    }

    if(status == 0){
        printf("Ne");
    }
    else{
        printf("Ja");
    }

    return Number;
}

int main(){

    int Number[1000];
    fgets(Number, 1000, stdin);

    CheckPrime(Number);


return 0;
}
