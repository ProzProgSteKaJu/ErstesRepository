#include <stdio.h>
#include <stdlib.h>

typedef double* Vector;
typedef Vector* Matrix;

Matrix MatAlloc(int m, int n){
    int i; Matrix A;
    A=(Matrix) malloc(m*sizeof(Vector));
    for(i=0;i<m;i++){
        A[i]=(Vector) malloc(n*sizeof(double));
    }

    return A;
}

Matrix MatInit(Matrix A, int m, int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            /*scanf("%lf", &A[i][j]);
            fflush(stdin);*/
            A[i][j]=rand()%5;
        }
    }
    return A;
}

void MatPrint(Matrix A, int m, int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%2.0f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int a,b,c,d,i,j,k,l;

    printf("Bitte geben Sie a b c d ein:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    fflush(stdin);

    Matrix A=MatAlloc(a,b);
    Matrix B=MatAlloc(c,d);
    A=MatInit(A,a,b);
    B=MatInit(B,c,d);
    MatPrint(A,a,b);
    MatPrint(B,c,d);
    Matrix C=MatAlloc(a*c,b*d);

    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            for(k=0;k<c;k++){
                for(l=0;l<d;l++){
                    C[i*c+k][j*d+l]=A[i][j]*B[k][l];
                }
            }
        }
    }
    MatPrint(C,a*c,b*d);

    return 0;
}
