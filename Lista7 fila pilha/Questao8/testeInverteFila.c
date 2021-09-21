#include<stdio.h>
#include<stdlib.h>
#include "inverteFila.h"

int main(){

	tipo_fila *fila;
    tipo_pilha *pilha;
	int posicao, *vetor;

	fila=criarFila();
    pilha=criarPilha();
	

                                    
   adicionarElemento(fila, 1);
   adicionarElemento(fila, 2);
   adicionarElemento(fila, 3);   
   adicionarElemento(fila, 4);
   adicionarElemento(fila, 5);
  
   vetor=obterElementosFila(fila);
   if(vetor!=NULL){
       printf("\n Elementos da fila: ");
       for(posicao=0;posicao<tamanhoFila(fila);posicao++){
           printf("[%d] ", vetor[posicao]);
       }
       printf("\n\n");
    }
    else 
        printf("\n Nao existem elementos"); 


   inverteFila(fila,pilha);
                                     
   vetor=obterElementosFila(fila);
   if(vetor!=NULL){
       printf("\n Fila invertida: ");
       for(posicao=0;posicao<tamanhoFila(fila);posicao++){
           printf("[%d] ", vetor[posicao]);
       }
       printf("\n\n");
    }
    else 
        printf("\n Nao existem elementos"); 
 
                                     

   fila=apagarFila(fila); 
	
	
	return 0;
}


