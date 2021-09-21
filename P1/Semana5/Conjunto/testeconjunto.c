#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "conjunto.h"

int main(){

 tipo_conjunto *conjunto1=NULL,*conjunto2=NULL;
 int numero,opcao,*vetor=NULL;
 int i;
  srand(time(NULL));

 

 do{
    printf("\n\n----------OPCOES----------\n");
    printf("\n 1- Criar conjunto vazio \n");
    printf("\n 2- inserir elemento no conjunto 1 \n");
    printf("\n 3- inserir elemento no conjunto 2 \n");
    printf("\n 4- remover elemento no conjunto 1 \n");
    printf("\n 5- remover elemento no conjunto 2 \n");
    printf("\n 6- união do conjunto 1 e 2 \n");
    printf("\n 7- interceccao do conjunto 1 e 2 \n");
    printf("\n 8- Diferença entre o conjunto 1 e 2 \n");
    printf("\n 9- testar se um numero pertence ao conjunto 1 \n");
    printf("\n 10- Verificar menor valor conjunto 1 \n");
    printf("\n 11- Verificar maior valor conjunto 1 \n");
    printf("\n 12- Verificar se os dois conjuntos são iguais \n");
    printf("\n 13- imprimir Tamanho do conjunto 1 \n");
    printf("\n 14- Testar se o conjunto 1 é vazio \n");
    printf("\n 15- Imprimir o conjunto 1 \n");
    printf("\n 16- Imprimir o conjunto 2 \n");
    printf("\n 17- Finalizar Programa \n");
    printf("\n Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao){
           
           case 1:
                   conjunto1=cria_conjunto_vazio(conjunto1);
                   if(conjunto1!=NULL)
                      printf("\nconjunto 1 vazio criado com sucesso! \n");
                      
                   conjunto2=cria_conjunto_vazio(conjunto2);
                   if(conjunto2!=NULL)
                      printf("\nconjunto 2 vazio criado com sucesso! \n");
                      
                    break;
                    
          case 2: 
                    if(conjunto1==NULL)
                        printf("\n crie o conjunto vazio para inserir elemento\n");
                        else{
		              numero=rand()%100;
		              conjunto1= insere_elemento(conjunto1,numero);
		              printf("\n numero inserido no conjunto 1: %d",numero);
		            }

                   break;
         case 3:
                   if(conjunto2==NULL)
                        printf("\n crie o conjunto vazio para inserir elemento\n");
                        else{
                              numero=rand()%100;
                              conjunto2= insere_elemento(conjunto2,numero);
                              printf("\n\n numero inserido no conjunto 2: %d\n\n",numero);
                            }
                   break;
                 
         case 4:
         
                numero=rand()%100;
                if(remove_elemento(conjunto1, numero)==0)
                   printf("\n o numero %d nao pertence ao conjunto1 \n",numero);
                   else 
                       printf("\n numero %d removido com sucesso \n", numero);
                 break;
                 
         case 5: 
                 numero=rand()%100;
                 if(remove_elemento(conjunto2, numero)==0)
                    printf("\n o numero %d nao pertence ao conjunto2 \n",numero);
                    else 
                         printf("\n numero %d removido com sucesso \n", numero);
                 break;
         break;
         
         case 6: 
                 conjunto3=une_conjuntos(conjunto1, conjunto2);
         
                 break;
   
        case 7: 
                 conjunto3=interseccao(conjunto1, conjunto2);
                 break;
                 
        case 8: 
                 conjunto3=diferenca(conjunto1, conjunto2);
                 break;
        case 9:
                 numero=rand()%100;
                 if(verifica_numero(conjunto1, numero)==1)
                    printf("\n o numero %d pertence ao conjunto1\n",numero);
                    else
                         printf("\n o numero %d nao pertence ao vetor1\n", numero);
                         
                 break;
        case 10: 
                if((verifica_menor(conjunto1))==-1)
                   printf("\n nao existem numeros no conjunto");
                   else
                        printf("\n o menor numero do conjunto 1 e: %d\n",verifica_menor(conjunto1));
                 break;
                 
         case 11: 
                  if((verifica_maior(conjunto1))==-1)
                      printf("\n nao existem numeros no conjunto");
                     else
                        printf("\n o maior numero do conjunto 1 e: %d\n",verifica_maior(conjunto1));    
                  break;
                  
         case 12: 
                 if(conjunto1==NULL || conjunto2==NULL)
                     printf("\n nao existem conjuntos \n");
                     else{
                          if (testa_igualdade(conjunto1, conjunto2)==0)
                                             printf("\n conjuntos são diferentes \n");
                             else
                                   printf("\n conjuntos são iguais \n");
                         }
                         
                  break;
                  
         case 13: 
                   printf("\n o tamanho do conjunto 1 e:%d \n", tamanho(conjunto1));
                   break;
                   
         case 14: 
                 if(testa_vazio(conjunto1)==0)
                    printf("\n conjunto 1 nao e vazio \n");
                    else
                         printf("\n conjunto 1 e vazio \n");
                  break;
                  
         case 15:  
                 vetor= imprime_conjunto(conjunto1,vetor);
                 for(i=0;i<tamanho(conjunto1);i++){
                     printf("%d",vetor[i]);
                  }
         case 16:
                 vetor= imprime_conjunto(conjunto2,vetor);
                 for(i=0;i<tamanho(conjunto2);i++){
                     printf("%d",vetor[i]);
                  }
                  break;
                  
        case 17: 
                 conjunto1=libera(conjunto1);
                 conjunto2=libera(conjunto2);
                 
                 printf("\nEncerrando, obrigada\n");
      }
                  
    }while(opcao!=17);
    
     

    return 0;
 }
