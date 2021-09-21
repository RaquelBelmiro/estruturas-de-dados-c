#include <stdio.h>

#define TAM 5

int soma(int *vetor, int n);

int main(){

    int resultado, vetor[TAM]= {1, 2, 3, 4, 5};

    resultado = soma(vetor, TAM-1); 

    printf("\nSoma dos valores do vetor: %d\n\n", resultado);
    
    return 0;    
}

int soma(int *vetor, int n){

    if(n == 0)

        return vetor[n];

    else

        return (vetor[n] + soma(vetor, n-1));

}
