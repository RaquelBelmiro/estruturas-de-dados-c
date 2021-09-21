#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

int main(){

	tipo_fila *fila;
	int dado, opcao, posicao, *vetor;

	fila=criarFila();
	
    do{
        printf("\n MENU: \n");
        printf("1-Adicionar Elemento \n");
        printf("2-Imprimir fila \n");
        printf("3-Excluir Elemento \n");
        printf("4-Verificar se a fila está vazia \n");
        printf("5-Verificar Tamanho da fila \n");
        printf("6-Sair do Programa \n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
      
        switch(opcao){
                            case 1:
                                    printf("\n Digite o elemento a ser adicionado na fila: ");
                                    scanf("%d", &dado);
                                    
                                    if(adicionarElemento(fila, dado))
                                       printf(" --Elemento adicionado na fila com sucesso \n");
                                    else
                                         printf("\n --Fila cheia");
                              
                                    break;

                           case 2: 
                                     vetor=imprimirFila(fila);
                                     if(!filaVazia(fila)){
                                         printf("\n Elementos da fila: ");
                                         for(posicao=0;posicao<nrElementos(fila);posicao++)
                                             printf("[%d] ", vetor[posicao]);
                                     }
                                     else 
                                         printf("\n Nao existem elementos na fila"); 
                                     
                                     printf("\n");
                                     break;
                           case 3:
                                   
                                       dado=excluirElemento(fila);
                                       if(dado!=-1){
	                                       printf("\n Elemento excluido: %d \n", dado);
                                       }
                                       else
                                         printf("\n fila vazia- nao existem elementos para excluir");
                 
                                    break;

                           case 4:
	                                if(filaVazia(fila))
	                                    printf("\n A fila está vazia \n");
	                                else
	                                     printf("\n A fila não está vazia \n");
	

	                                 break;

                           case 5: 
	                                printf("\n Tamanho da fila: %d \n", nrElementos(fila));
                                      
                                    break;

                          case 6: 
                                    fila=apagarFila(fila); 
	                                if(fila==NULL)
	                                     printf("\n fila apagada com sucesso, Encerrando o programa \n");
	                                else
	                                     printf("\n A fila ainda existe \n");

                                   break;
	    	
                          default:
                                  printf("\n OPCAO INVALIDA \n");
                   }
         }while(opcao!=6);
	
	
	
	return 0;
}


