#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int numero;
	struct no *proximo;
}no;

//Protótipo de funções
no *incluirElementoInicio(no *inicio, int numero);
void imprimirElementos(no *inicio);
no *excluirElementoInicio(no *inicio);


int main(){
	
	int opcao, posicao, numero;
	no *inicio=NULL;
	
	do{
		printf("\n\n Escolha uma opcao abaixo: \n\n");
		printf("1- Inclusão de elemento no inı́cio da lista \n");
		printf("2- Exclusão de elemento do inı́cio da lista \n");
		printf("3- Impressão dos elementos da lista \n");
		printf("4- Finalização do Programa \n\n");
                printf("Digite a opcao desejada: ");
		scanf("%d",&opcao);
	
	
		switch(opcao){
	
			case 1:
		                printf("\n\nDigite o numero inteiro a ser inserido: \n");
		                scanf("%d", &numero);
				inicio= incluirElementoInicio(inicio,numero);
				break;
		
			case 2:
		                inicio= excluirElementoInicio(inicio);  
		                printf("\nElemento de inicio excluído com sucesso\n");
			        break;
			
	                case 3:
                                if(inicio==NULL)
                                   printf("\nLista vazia\n");
                                   else
                                       imprimirElementos(inicio);
			        break;
			case 4:
                     
                                do{
                                    inicio= excluirElementoInicio(inicio);
                                  }while(inicio!=NULL);
                       
                               printf("\n\nPROGRAMA FINALIZADO, OBRIGADO!\n\n");
		               return 0;
			       break;
		
			default:
		
				printf("\n\nOPCAO INVALIDA, DIGITE NOVAMENTE\n\n");
        }
	}while(opcao!=4);
	
	
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
     novo->proximo=inicio;          //proximo vai apontar para o endereço do nó criado anteriormente
     inicio=novo;                   //inicio comeca a apontar para o novo nó que passa a ser o inicio da estrutura

     return inicio; 
}
void imprimirElementos(no *inicio){

      no *atual=inicio;
      
      while(atual!=NULL){                     //o último elemento aponta para NULL significando que não existe próximo elemento
          printf("%d ",atual->numero);
          atual=atual->proximo;                 
      }
}

no *excluirElementoInicio(no *inicio){
   
    no *auxiliar=inicio;
    
    inicio = inicio->proximo;
    free(auxiliar);

    return inicio;
}
