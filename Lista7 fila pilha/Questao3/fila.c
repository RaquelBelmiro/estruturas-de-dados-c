#include<stdlib.h>
#define TAM 20


typedef struct reg_fila
{
    int *vetor;
	int inicio;
    int fim;
	int nrElementos;
	
}tipo_fila;

tipo_fila *criarFila(){
    
	tipo_fila *fila;
	int posicao;

	fila=(tipo_fila*)malloc(sizeof(tipo_fila));
	fila->inicio=0;
    fila->fim=0;
    fila->nrElementos=0;

    fila->vetor=(int*)malloc(TAM*sizeof(int));
    for(posicao=0;posicao<TAM;posicao++)
        fila->vetor[posicao]=0;
	
	return fila;
}

int nrElementos(tipo_fila *fila){

	return fila->nrElementos;
}

int filaVazia(tipo_fila *fila){

	if(nrElementos(fila)==0)
        return 1;

    return 0;      
}

int *imprimirFila(tipo_fila *fila) //ajeitar essa parte
{
    int *vetAux, posicao= 0;

   if(!filaVazia(fila))
    {
        return fila->vetor;
    }

   return NULL;
}
int adicionarElemento(tipo_fila *fila, int dado){
    
    if(fila->fim==TAM){               //se a fila estiver cheia nao insere
       return 0;

     }
    
    fila->vetor[fila->fim]=dado;
    fila->fim++;
    fila->nrElementos++;
    return 1;
        
}
int excluirElemento(tipo_fila *fila){
	
    int dado,posicao;
    
    if(filaVazia(fila))
       return -1;                  
       
    dado=fila->vetor[fila->inicio];
    for(posicao=0;posicao<fila->nrElementos;posicao++){
        fila->vetor[posicao]= fila->vetor[posicao+1];
        
     }
   fila->fim--;
   fila->nrElementos--;                            
   return dado;
}

tipo_fila* apagarFila(tipo_fila *fila){
    

	while(!filaVazia(fila)) 
             {
               excluirElemento(fila);
             }
    
	free(fila);
    
	return NULL;
}
