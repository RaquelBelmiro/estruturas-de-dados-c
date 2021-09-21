#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int numero;
	struct no *proximo;
}no;

//Protótipo de funções
no *incluirElementoInicio(no *inicio, int numero);
no *incluirElementoFim(no *inicio, int numero);
no *excluirElementoInicio(no *inicio);
no *excluirElementoFim(no *inicio);
void imprimirElementos(no *inicio);



int main(){
	
	int opcao, posicao, numero;
	no *inicio=NULL;
	
	do{
		printf("\n\n Escolha uma opcao abaixo: \n\n");
		printf("1- Inclusão de elemento no inı́cio da lista \n");
	        printf("2- Inclusão de elemento no fim da lista \n");
		printf("3- Exclusão de elemento do inı́cio da lista \n");
		printf("4- Exclusão de elemento do fim da lista \n");
		printf("5- Impressão dos elementos da lista \n");
		printf("6- Limpar a lista - Excluir todos os elementos \n");
		printf("7- Finalização do Programa \n\n");
                printf("Digite a opcao desejada: ");
		scanf("%d",&opcao);
	
	
		switch(opcao){
	
			case 1:
                               printf("\n\nDigite o numero inteiro a ser inserido: \n");
                               scanf("%d", &numero);
		               inicio= incluirElementoInicio(inicio,numero);
			       break;
			       
		        case 2:
		               printf("\n\nDigite o numero inteiro a ser inserido: \n");
                               scanf("%d", &numero);
		               inicio=incluirElementoFim(inicio,numero);
		               break;
		
			case 3:
                               inicio= excluirElementoInicio(inicio);  
                               printf("\nElemento de inicio excluído com sucesso\n");
			       break;
				        
		        case 4:
		               inicio= excluirElementoFim(inicio);
		               printf("\nElemento de fim excluído com sucesso\n");
		               break;
			
	                case 5:
		               
                               if(inicio==NULL)
                                   printf("\nLista vazia\n");
                                   else
                                       imprimirElementos(inicio);
                                        
			       break;
				        
		        case 6:
		              
		               if(inicio!=NULL)
		               {
		                  do{
		                       inicio= excluirElementoInicio(inicio);
		                    }while(inicio!=NULL);
		                }
		                  printf("\nTodos os Elementos foram excluídos com sucesso\n");
		                break;
			
			case 7:
                     
                                if(inicio!=NULL)
                                {
		                    do{
		                        inicio= excluirElementoInicio(inicio);
		                       }while(inicio!=NULL);
                                 }
                         
                                 printf("\n\nPROGRAMA FINALIZADO, OBRIGADO!\n\n");
		                 return 0;
		
			default:
		
				printf("\n\nOPCAO INVALIDA, DIGITE NOVAMENTE\n\n");
				
        }//FECHA SWITCH
    }while(opcao!=7);
	
	
    return 0;
}
no *incluirElementoInicio(no *inicio, int numero){
 
     no *novo=NULL;
     
     novo= (no*)(malloc(sizeof(no)));
     if(novo==NULL){
       printf("Nao foi possivel alocar o espaco");
       return 0;
     }
     
     novo->numero=numero;
     novo->proximo=inicio;       //proximo vai apontar para o no criado anteriormente
     inicio=novo;                //inicio passa a apontar para o novo nó

     return inicio; 
}
no *incluirElementoFim(no *inicio, int numero){
    no *novo, *atual=inicio;
    
    novo = (no *) malloc(sizeof (no));
    
         novo -> numero = numero ;
	 novo -> proximo = NULL ;
	 
	 if( inicio != NULL )           //se a lista nao estiver vazia
	 {
		 while ( atual-> proximo != NULL ) 
		 {
		 	atual = atual-> proximo ;     //percorre ate chegar no ultimo elemento
		 }
		 atual-> proximo = novo ;            //insere o endereco do novo elemento no ultimo no
	 }
	 else{
	 	inicio = novo ;                    //se a lista estiver vazia o inicio comeca a apontar para o novo
	 }
	 
	 return inicio ;
}


no *excluirElementoInicio(no *inicio){
   
    no *auxiliar=NULL;

    auxiliar = inicio;
    inicio = inicio->proximo;
    free(auxiliar);

    return inicio;
}
no *excluirElementoFim(no *inicio){

   no * anterior = NULL , * atual = inicio ;
   
   if ( inicio != NULL )
   {
   
	while ( atual-> proximo != NULL ){      //percorre até o último elemento
	   anterior = atual ;              
	   atual = atual-> proximo ;
        }
	 free (atual);
	 
	 if ( anterior != NULL ){            //se existir o elemento anterior, atualiza o campo proximo
	     anterior-> proximo = NULL ;
	   }
	   
         else{
             inicio = NULL ;             // se nao existir o campo anterior, o que foi apagado foi o primeiro e unico elemento
         }
   }
 return inicio ;

}
void imprimirElementos(no *inicio){

      no *atual=NULL;
      atual=inicio;
      
      while(atual!=NULL){
          printf("%d ",atual->numero);
          atual=atual->proximo;
      }
}
