#include <stdio.h>

int fibonacci(int n);

int main(){      //serie fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...

    int n, resultado;

    do{
        printf("\nDigite a posicao para saber qual é o termo (posicao >= 1): ");
        scanf("%d", &n);
    }while(n < 1);

    resultado = fibonacci(n);    

   printf("\nO %d termo da Sequencia de Fibonacci = %d\n\n", n, resultado); //O 3 termo da Sequencia de Fibonacci = 2
    
   return 0;    
}

int fibonacci(int n){

    if((n == 0) || (n == 1))
        return n;

    else
        return (fibonacci(n-1) + fibonacci(n-2));

}
