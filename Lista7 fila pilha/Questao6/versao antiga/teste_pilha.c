#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main(){

	tipo_pilha *pilha;
	char *string,**aux;
    int opcao, posicao;

	pilha=criarPilha();
	
    do{
        printf("\n MENU: \n");
        printf("1-Empilhar Elemento \n");
        printf("2-Imprimir pilha \n");
        printf("3-Verificar tamanho da pilha \n");
        printf("4-Verificar parenteses \n");
        printf("5-Sair do Programa \n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
      
        switch(opcao){
                            case 1:
                                    printf("\n Digite a string a ser empilhada: ");
                                    scanf(" %[^\n]s", string);
                                    
                                    if(empilharElemento(pilha, string))
                                       printf(" --Elemento Empilhado com sucesso \n");
                                    else
                                         printf("\n --Erro ao empilhar Elemento");
                              
                                    break;

                           case 2: 
                                   aux=obterElementosPilha(pilha);

                                   if(aux!=NULL){
                                      printf("\n Elementos da Pilha: ");

                                       for(posicao=0;posicao<tamanhoPilha(pilha);posicao++)
                                       printf("%s ", aux[posicao]);
                                    }
                                   else 
                                   printf("\n Nao existem elementos na pilha"); 
                                     
                                     printf("\n");

                                     break;


                           case 3: 
	                                printf("\n Tamanho da Pilha: %d \n", tamanhoPilha(pilha));
                                      
                                    break;

                          case 4: 
                                    if(!pilhaVazia(pilha)){
                                        if(verificaParenteses(pilha)==1)
                                           printf("\n Numero de abre parenteses e de fecha parenteses sao iguais");
                                        else
                                           printf("\n Numero de abre parenteses e de fecha parenteses sao diferentes");
                                       }
                                     else
                                        printf("\n Pilha vazia");

                                     break;
                          case 5: 
                                  pilha=apagarPilha(pilha); 
	                              if(pilha==NULL)
	                                     printf("\n Pilha apagada com sucesso, Encerrando o programa \n");
	                                else
	                                     printf("\n A pilha ainda existe \n");

                                   break;
                          default:
                                  printf("\n OPCAO INVALIDA \n");
                   }
         }while(opcao!=5);
	
	
	
	return 0;
}


