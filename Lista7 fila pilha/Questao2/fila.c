#include<stdlib.h>

typedef struct no
{
	int dado;
	struct no *proximo;
}tipo_no;

typedef struct reg_fila
{
	tipo_no *inicio;
    tipo_no *fim;
	int tamanhoFila;
	
}tipo_fila;

tipo_fila *criarFila(){
    
	tipo_fila *fila;
	
	fila=(tipo_fila*)malloc(sizeof(tipo_fila));
	
	fila->inicio=NULL;
    fila->fim=NULL;
   
	fila->tamanhoFila=0;
	
	return fila;
}

int adicionarElemento(tipo_fila *fila, int dado){

	tipo_no *novo, *atual=fila->inicio;

	novo=(tipo_no*) malloc(sizeof(tipo_no));
	if(novo==NULL)
       return 0;

    novo -> dado = dado ;
	novo -> proximo = NULL ;

    if( fila->inicio != NULL )           //se a fila nao estiver vazia
	 {
		 while ( atual-> proximo != NULL ) 
		 {
		 	atual = atual-> proximo ;     //percorre ate chegar no ultimo elemento
		 }
		 atual-> proximo = novo ;  
         fila->fim=novo;                //insere o endereco do novo elemento no ultimo no
	 }
	 else{
	 	fila->inicio = novo ;                    //se a fila estiver vazia o inicio e o fim comeca apontam para o novo
        fila->fim=novo;
	 }
	 
	fila->tamanhoFila++;
    return 1;
}
int filaVazia(tipo_fila *fila){

	if(fila->inicio == NULL)
	  {
        	return 1;
      }
   
    return 0;
        
}

int tamanhoFila(tipo_fila *fila){

	return fila->tamanhoFila;
}

int *imprimirFila(tipo_fila *fila)
{
    tipo_no *atual = fila->inicio;
    int *vetor, posicao= 0;

    vetor= (int*) malloc(tamanhoFila(fila) * sizeof(int));

   if(!filaVazia(fila))
    {
        while (atual != NULL)
        {
            vetor[posicao] = atual->dado;
            atual = atual->proximo;
            posicao++;
        }
        return vetor;
    }

   return NULL;
}

int excluirElemento(tipo_fila *fila){
	
	tipo_no *auxiliar=NULL;
    int dado;

	if(!filaVazia(fila))
	    {
		    auxiliar=fila->inicio;
            fila->inicio=fila->inicio->proximo;
            dado= auxiliar->dado;

		   
		    free(auxiliar);
		    fila->tamanhoFila--;
  
            return dado;
	     }

    return -1;
}

tipo_fila* apagarFila(tipo_fila *fila){
    
	tipo_no *auxiliar;

	while(!filaVazia(fila)) 
             {
               excluirElemento(fila);
             }
    
	free(fila);
    
	return NULL;
}
