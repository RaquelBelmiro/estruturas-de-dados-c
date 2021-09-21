#include<stdio.h>
int calculaFatorial(int n);

int main(){
    int n,resultado_fatorial;

    do{
        printf("\n Digite um numero inteiro N: ");
        scanf("%d", &n);

      }while(n<0);

     resultado_fatorial=calculaFatorial(n);

     printf("\n Fatorial de %d: %d \n\n", n, resultado_fatorial);

    return 0;
}                   1
int calculaFatorial(int n){
    
    if(n==0)
       return 1;
    else   
    return n*(calculaFatorial(n-1));
        
}
