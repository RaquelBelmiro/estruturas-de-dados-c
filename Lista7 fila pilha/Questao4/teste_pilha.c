#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main(){

	tipo_pilha *pilha1, *pilha2;
	int dado, opcao, posicao, *vetor;

	pilha1=criarPilha();
    pilha2=criarPilha();
	
    do{
        printf("\n MENU: \n");
        printf("1-Empilhar Elemento na pilha 1 \n");
        printf("2-Empilhar Elemento na pilha 2 \n");
        printf("3-Imprimir pilhas \n");
        printf("4-Desempilhar Elemento pilha 1 \n");
        printf("5-Desempilhar Elemento pilha 2 \n");
        printf("6-Verificar se as pilhas estao vazias \n");
        printf("7-Verificar Tamanho das pilhas \n");
        printf("8-Testar igualdade entre duas pilhas \n");
        printf("9-Sair do Programa \n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
      
        switch(opcao){
                            case 1:
                                    printf("\n Digite o elemento a ser empilhado na pilha 1: ");
                                    scanf("%d", &dado);
                                    
                                    if(empilharElemento(pilha1, dado))
                                       printf(" --Elemento Empilhado com sucesso na pilha 1\n");
                                    else
                                         printf("\n --Erro ao empilhar Elemento na pilha 1");
                              
                                    break;

                           case 2: 
                                    printf("\n Digite o elemento a ser empilhado na pilha 2: ");
                                    scanf("%d", &dado);
                                    
                                    if(empilharElemento(pilha2, dado))
                                       printf(" --Elemento Empilhado com sucesso na pilha 2\n");
                                    else
                                         printf("\n --Erro ao empilhar Elemento na pilha 2");
                              
                                    
                                     break;
                            case 3:
                                     vetor=imprimirPilha(pilha1);
                                     if(vetor!=NULL){
                                         printf("\n Elementos da Pilha 1: \n");
                                        for(posicao=0;posicao<tamanhoPilha(pilha1);posicao++)
                                             printf("[%d] \n", vetor[posicao]);
                                     }
                                     else 
                                         printf("\n Nao existem elementos na pilha 1"); 
                                     
                                     printf("\n");
                                     
                                     vetor=imprimirPilha(pilha2);
                                     if(vetor!=NULL){
                                         printf("\n Elementos da Pilha 2: ");
                                        for(posicao=0;posicao<tamanhoPilha(pilha2);posicao++)
                                             printf("[%d] ", vetor[posicao]);
                                     }
                                     else 
                                         printf("\n Nao existem elementos na pilha 2"); 
                                     
                                     printf("\n");
                                    
                                     break;

                           case 4: 
                                       dado=desempilharElemento(pilha1);
                                       if(dado!=-1){
	                                   printf("\n Elemento desempilhado: %d \n", dado);
                                    }
                                    else
                                         printf("\n pilha 1 vazia- nao existem elementos para desempilhar");
                 
                                    break;
	                                
                           case 5: 

                                    
                                       dado=desempilharElemento(pilha2);
                                       if(dado!=-1){
	                                   printf("\n Elemento desempilhado: %d \n", dado);
                                    }
                                    else
                                         printf("\n pilha 2 vazia- nao existem elementos para desempilhar");
                 
                                    break;
	                                
                          case 6:   
                                     if(pilhaVazia(pilha1))
	                                    printf("\n A pilha 1 está vazia \n");
	                                else
	                                     printf("\n A pilha 1 não está vazia \n");

                                    if(pilhaVazia(pilha2))
	                                    printf("\n A pilha 2 está vazia \n");
	                                else
	                                     printf("\n A pilha 2 não está vazia \n");
	
	                                 break;

                              case 7: 
                                     printf("\n Tamanho da Pilha 1: %d \n", tamanhoPilha(pilha1));
                                     printf("\n Tamanho da Pilha 2: %d \n", tamanhoPilha(pilha2));
                                      
                                    break;


                             case 8:
                                    if(testarIgualdade(pilha1,pilha2))
                                       printf(" --Pilhas iguais \n");
                                    else
                                         printf("\n --Pilhas diferentes \n");

                                    break;
                             case 9:
                                    pilha1=apagarPilha(pilha1); 
	                                if(pilha1==NULL)
	                                     printf("\n Pilha 1 apagada com sucesso\n");
	                                else
	                                     printf("\n A pilha 1 ainda existe \n");

                                    pilha2=apagarPilha(pilha2); 
	                                if(pilha2==NULL)
	                                     printf("\n Pilha 2 apagada com sucesso, Encerrando o programa \n");
	                                else
	                                     printf("\n A pilha 2 ainda existe \n");
                                    break; 
	    	
                          default:
                                  printf("\n OPCAO INVALIDA \n");
                   }
         }while(opcao!=9);
	
	
	
	return 0;
}


