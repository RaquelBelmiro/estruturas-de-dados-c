#include<stdio.h>
#include<stdlib.h>        //operacoes ordenadas
#include<string.h>
#include<ctype.h>

typedef struct no{
	char nome[20];
	struct no *proximo;
}no;

//Protótipo de funções
no *incluirNomeOrdenado(no *inicio, char nome[20]);     
no *excluirNomeOrdenado(no *inicio, char nome[20]);
void buscarNome(no *inicio, char nome[20]);
no *limparLista(no *inicio);
int main(){
	
	int opcao, i;;
	char n[20],nome[20];
	no *inicio=NULL;
	
	do{
		printf("\n\n Escolha uma opcao abaixo: \n\n");
		printf("1- Inclusão de nome \n");
		printf("2- Exclusão de nome \n");
		printf("3- Busca por um Nome \n");
		printf("4- Limpar Lista \n");
		printf("5- Finalizar Programa \n\n");
                printf("Digite a opcao desejada: ");
		scanf("%d",&opcao);
	
	
		switch(opcao){
	
			case 1:
		                printf("\n\nDigite o nome a ser inserido na lista: \n");
		                scanf("%s", nome);
               
				inicio= incluirNomeOrdenado(inicio,nome);
		                break;
		
			case 2:
			         printf("\n\nDigite o nome que deseja excluir: \n");
			         scanf("%s", nome);
                     
                                 inicio=excluirNomeOrdenado(inicio, nome);
				 break;
			
	               case 3:
	       	                 if(inicio==NULL)
                                    printf("Lista Vazia");

                                 else{
				       printf("\n\nDigite o nome que deseja buscar: \n");
				       scanf("%s", nome);
				       buscarNome(inicio,nome);
		                    }
				 break;
				 			              
		       case 4:
                                 inicio=limparLista(inicio);
                   
				 break;
		       case 5: 
                                 inicio=limparLista(inicio);
                                 if(inicio==NULL)
                                    printf("Lista desalocada \n");
                                    printf("Programa encerrado,obrigado!");
               
	              default:
				printf("\n\nOPCAO INVALIDA, DIGITE NOVAMENTE\n\n");
        }
	}while(opcao!=5);
	
	
	return 0;
}
no *incluirNomeOrdenado(no *inicio, char nome[20]){

    no * novo , * atual = inicio , * anterior = NULL ;
    
    novo = (no *) malloc ( sizeof (no));
    
    
    strcpy( novo->nome, nome);
    
    if ( inicio == NULL ) {              //1° elemento
        novo -> proximo = NULL ;
        inicio = novo ;
    }
    
    else{
           while (( atual != NULL ) && (strcmp(atual->nome, nome)<0)){   // Para em null ou encontrando nome maior
		   anterior = atual;
		   atual = atual -> proximo;
           }
         
           if (anterior == NULL){
               novo -> proximo = inicio;
               inicio = novo;
           }
           else {
                  anterior -> proximo = novo;
                  novo -> proximo = atual;
           }
        }
	return inicio; 
 }
no *excluirNomeOrdenado(no *inicio, char nome[20]){

    no * auxiliar , * anterior = NULL , * atual = inicio; 
    
    while ((atual != NULL ) && (strcmp(atual->nome,nome)!=0)){
            anterior = atual ;
            atual = atual->proximo ;
    }
    if ( strcmp(atual->nome, nome)==0){
        if (anterior == NULL){
             inicio= atual->proximo;
        }
        else{
              anterior->proximo = atual->proximo ;
        }
        auxiliar = atual ;
        free ( auxiliar );
     }
	return inicio ; 
}

void buscarNome(no *inicio, char nome[20]){
     
      no * auxiliar , * anterior = NULL , * atual = inicio; 
      int posicao=0;
      
    
     while ((atual != NULL ) && (strcmp(atual->nome,nome)!=0)){ 
            atual = atual->proximo ;
            posicao++;
    }
    if(atual==NULL){                              
       printf("\n Nome nao encontrado \n");
       
     }else                                        
          printf("Nome %s encontrado na posicao: %d", atual->nome,posicao); 
                 
}
no *limparLista(no *inicio){

   no *auxiliar=NULL;
   
  while(inicio!=NULL){
    auxiliar = inicio;
    inicio = inicio->proximo;
    free(auxiliar);
  }
    return inicio;
}
