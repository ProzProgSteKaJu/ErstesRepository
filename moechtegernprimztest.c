#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int Primes[20];
    int Number;
    int i;
    int status = 1;

    Primes[0] = 2;
    Primes[1] = 3;
    Primes[2] = 5;
    Primes[3] = 7;
    Primes[4] = 11;
    Primes[5] = 13;
    Primes[6] = 17;
    Primes[7] = 19;
    Primes[8] = 23;
    Primes[9] = 29;
    Primes[10] = 31;
    Primes[11] = 37;
    Primes[12] = 41;
    Primes[13] = 43;
    Primes[14] = 47;
    Primes[15] = 53;
    Primes[16] = 59;
    Primes[17] = 61;
    Primes[18] = 67;
    Primes[19] = 71;

    /*do{*/
        srand(time(NULL));
        Number = rand()%20;
        i = Primes[Number];
        printf("%d\n", Number);
        printf("%d", i);

        /*if((Number%2==0) || (Number == 1)){
            status = 0;
        }
        for (i = 2; i <= Number-1; i++){
            if (Number % i == 0){
                status = 0; break;
            }
        }

        /*if(status == 0){
            printf("Neee!");
        }
        else{
            printf("Jeppp, Primzahl :-)");
        }*/
    /*}while(status==0);
if(status !=0){
    printf("%d", Number);
}*/
return 0;
}
