#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

int main(){

	tipo_fila *filaOriginal=NULL,*filaImpares=NULL,*filaPares=NULL;
	int dado,*elementos, opcao, posicao;

	filaOriginal=criarFila();
	filaImpares=criarFila();
    filaPares=criarFila();

    
    do{
        printf("\n MENU: \n");
        printf("1-Adicionar Elemento na fila Original\n");
        printf("2-Imprimir filas \n");
        printf("3-Sair do Programa \n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
      
        switch(opcao){
                            case 1:
                                    printf("\n Digite o elemento a ser adicionado na fila: ");
                                    scanf("%d", &dado);
                                    
                                    if(adicionarElemento(filaOriginal, dado))
                                       printf(" --Elemento adicionado na fila com sucesso \n");
                                    else
                                         printf("\n --Erro ao adicionar elemento na fila");
                              
                                    break;

                           case 2:  
                                     
                                     if(!filaVazia(filaOriginal)){
                                         printf("\n Elementos da fila Original: ");
                                         elementos= obterElementos(filaOriginal); 
                                         for(posicao = 0; posicao < tamanhoFila(filaOriginal); posicao++)
                                            {
                                              printf("%d ", elementos[posicao]);
                                            }
                                         separaFilas(filaOriginal,filaPares,filaImpares);
                                      }
                                      else 
                                         printf("\n Nao existem elementos na fila Original"); 

                                
                                     if(!filaVazia(filaPares)){
                                         printf("\n Elementos da fila de pares: ");
                                         elementos= obterElementos(filaPares); 
                                         for(posicao = 0; posicao < tamanhoFila(filaPares); posicao++)
                                            {
                                              printf("%d ", elementos[posicao]);
                                            }
                                      }
                                     else 
                                         printf("\n Nao existem elementos na fila pares"); 
                                     
                                     if(!filaVazia(filaImpares)){
                                         printf("\n Elementos da fila de impares: ");
                                         elementos= obterElementos(filaImpares); 
                                         for(posicao = 0; posicao < tamanhoFila(filaImpares); posicao++)
                                            {
                                              printf("%d ", elementos[posicao]);
                                            }
                                      }
                                      else 
                                         printf("\n Nao existem elementos na fila impares"); 

                                     printf("\n");
                                     break;



                          case 3: 
                                    filaOriginal=apagarFila(filaOriginal); 
	                                if(filaVazia(filaOriginal))
	                                     printf("\n fila Original apagada com sucesso \n");
	                                else
	                                     printf("\n A fila Original ainda existe \n");

                                    filaPares=apagarFila(filaPares); 
	                                if(filaVazia(filaPares))
	                                     printf("\n fila Pares apagada com sucesso\n");
	                                else
	                                     printf("\n A fila pares ainda existe \n");
                                   
                                    filaImpares=apagarFila(filaImpares); 
	                                if(filaVazia(filaImpares))
	                                     printf("\n fila Impares apagada com sucesso \n");
	                                else
	                                     printf("\n A fila impares ainda existe \n");
                                   break;
	    	
                          default:
                                  printf("\n OPCAO INVALIDA \n");
                   }
         }while(opcao!=3);
	
	
	
	return 0;
}


