#include<stdio.h>
int soma(int n);

int main(){
    int n, resultado;
    
    do{
	    printf("Digite um numero inteiro: ");
	    scanf("%d", &n);
      }while(n<0);
      
      resultado=soma(n);
      
      printf(" Soma de 1 a %d: %d \n",n,resultado);
      
      
      return 0;
}
int soma(int n){

    if(n==1)
       return 1;
       
    else
        return n+(soma(n-1));
        
}
