#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main(){

	tipo_pilha *pilha;
	int dado, opcao, posicao, *vetor;

	pilha=criarPilha();
	
    do{
        printf("\n MENU: \n");
        printf("1-Empilhar Elemento \n");
        printf("2-Imprimir pilha \n");
        printf("3-Desempilhar Elemento \n");
        printf("4-Verificar se a pilha está vazia \n");
        printf("5-Verificar Tamanho da pilha \n");
        printf("6-Sair do Programa \n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
      
        switch(opcao){
                            case 1:
                                    printf("\n Digite o elemento a ser empilhado: ");
                                    scanf("%d", &dado);
                                    
                                    if(empilharElemento(pilha, dado))
                                       printf(" --Elemento Empilhado com sucesso \n");
                                    else
                                         printf("\n --Erro ao empilhar Elemento");
                              
                                    break;

                           case 2: 
                                   vetor=imprimirPilha(pilha);

                                   if(vetor!=NULL){
                                      printf("\n Elementos da Pilha: ");

                                       for(posicao=0;posicao<tamanhoPilha(pilha);posicao++)
                                       printf("[%d] ", vetor[posicao]);
                                    }
                                   else 
                                   printf("\n Nao existem elementos na pilha"); 
                                     
                                     printf("\n");
                                     break;
                           case 3:
                                   dado=desempilharElemento(pilha);
                                   if(dado!=-1)
	                                  printf("\n Elemento desempilhado: %d \n", dado);
                                   else
                                       printf("\n pilha vazia- nao existem elementos para desempilhar");
                 
                                    break;

                           case 4:
	                                if(pilhaVazia(pilha))
	                                    printf("\n A pilha está vazia \n");
	                                else
	                                     printf("\n A pilha não está vazia \n");
	
	                                break;

                           case 5: 
	                                printf("\n Tamanho da Pilha: %d \n", tamanhoPilha(pilha));
                                      
                                    break;

                          case 6: 
                                    pilha=apagarPilha(pilha); 
	                                if(pilha==NULL)
	                                     printf("\n Pilha apagada com sucesso, Encerrando o programa \n");
	                                else
	                                     printf("\n A pilha ainda existe \n");

                                   break;
	    	
                          default:
                                  printf("\n OPCAO INVALIDA \n");
                   }
         }while(opcao!=6);
	
	
	
	return 0;
}


