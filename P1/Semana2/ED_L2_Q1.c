#include<stdio.h>
#include<stdlib.h>

void troca(int *valor1, int *valor2);

int main(){

  int valor1, valor2;
  
  printf("\n\n Digite o valor1: ");
  scanf("%d", &valor1);
  
  printf("\n Digite o valor2: ");
  scanf("%d", &valor2);
  
  troca(&valor1,&valor2);
  
  printf("\n\n---Troca de valores---");
  printf("\n\n   valor1: %d \n   valor2: %d \n",valor1,valor2);
  
  printf("\n\n");
  return 0;
 
 }
 
void troca(int *valor1, int *valor2){

  int aux;
	
  aux=*valor1;
  *valor1=*valor2;
  *valor2=aux;
	
}
