#include <stdio.h>
#include <stdlib.h>


typedef double* Vector;
typedef Vector* Matrix;

//from the lecture
Matrix MatAlloc(int m, int n){

    int i;
    Matrix B;

    B = (Matrix) malloc(m*sizeof(Vector));
    if (B==NULL){
        printf("not enough memory!");
        return NULL;
    }

    for(i=0;i<m;i++){
        B[i]=(Vector) malloc(n*sizeof(double));
        if (B[i]==NULL){
            printf("not enough memory!");
            return NULL;
        }
    }
    return B;
}

//for the task
Matrix alloc_symmatrix(int n){
    int i;
    Matrix B;

    B = (Matrix) malloc(n*sizeof(Vector));
    if (B==NULL){
        printf("not enough memory!");
        return NULL;
    }

    for(i=0;i<n;i++){
        B[i]=(Vector) malloc((i+1)*sizeof(float));
                if (B[i]==NULL){
            printf("not enough memory!");
            return NULL;
        }
    }
    return B;
}

int main(){

    int i,j,m;
    printf("Die Matrix컴컴컴컴컴�\nBitte geben Sie n ein:\n");
    scanf("%d", &m);

    Matrix A,C;

    C=MatAlloc(m,m);

    //doesn't work. Why?
    C[1][1]=2;
    for (i=1;i<m;i++){
        for (j=1;j<m;j++){
            printf("C[%d][%d]=%d\n", i,j,C[i][j]);
        }
    }

    //task
    int n;

    printf("\n\nGib bitte n ein:\n");
    scanf("%d", &n);

    A = alloc_symmatrix(n);

    return 0;
}
