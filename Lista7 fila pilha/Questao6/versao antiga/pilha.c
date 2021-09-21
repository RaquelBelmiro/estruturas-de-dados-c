#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#define TAM 20

typedef struct reg_pilha
{
    char *string; 
	int tamanhoPilha;
	
}tipo_pilha;

tipo_pilha *criarPilha(){
    
	tipo_pilha *pilha;
	
	pilha=(tipo_pilha*)malloc(sizeof(tipo_pilha));
	pilha->topo=NULL;
	pilha->tamanhoPilha=0;
	
	return pilha;
}

int empilharElemento(tipo_pilha *pilha, char *string){

	tipo_no *novo=NULL;
	
	novo=(tipo_no*) malloc(sizeof(tipo_no));
	if(novo==NULL)
       return 0;
     
    novo->string=(char*) malloc(strlen(string));
	strcpy(novo->string,string);
	novo->proximo=pilha->topo;
	pilha->topo=novo;
	pilha->tamanhoPilha++;	

    return 1;
}
int pilhaVazia(tipo_pilha *pilha){

	if(pilha->topo == NULL)
	  {
        	return 1;
      }
   
    return 0;
        
}

int tamanhoPilha(tipo_pilha *pilha){

	return pilha->tamanhoPilha;
}

char **obterElementosPilha(tipo_pilha *pilha)              //retorna endereço de char
{
    tipo_no *atual = pilha->topo;                //atual aponta para o topo da pilha
    char **aux;                                   //aux ira armazenar endereço inicial de uma sequencia de char
    int i,j=0;

   if(!pilhaVazia(pilha))                    //se a pilha não estiver vazia
    {
        aux= (char**) malloc(tamanhoPilha(pilha)* sizeof(char)); 
        for(i=0;i<tamanhoPilha(pilha);i++)
             aux[i]=(char*)malloc(TAM*sizeof(char));

        while (atual != NULL)                 //enquanto não chegar o fim da pilha
        {
            aux[j]=atual->string;    //
            atual = atual->proximo;
            j++;
        }
                
        return aux;

    }

   return NULL;
}

char *desempilharElemento(tipo_pilha *pilha){
	
	tipo_no *auxiliar=NULL;
    char *string;

	if(!pilhaVazia(pilha))
	    {
		    auxiliar=pilha->topo;
            pilha->topo=pilha->topo->proximo;
            string= auxiliar->string;

		   
		    free(auxiliar);
		    pilha->tamanhoPilha--;

            return string;
	     }

    return NULL;
}
int verificaParenteses(tipo_pilha *pilha){
    char **aux;
    int i,j,aberto=0,fechado=0;

    aux=obterElementosPilha(pilha);
    for(i=0;i<pilha->tamanhoPilha;i++){
          for(j=0;j<strlen(aux[i]);j++){
              if((aux[i][j])=='(')
                 aberto++;
              if((aux[i][j])==')')
                 fechado++;
           }
      }

    if(aberto==fechado)
           return 1;
        else 
            return 0;
}
tipo_pilha* apagarPilha(tipo_pilha *pilha){
    
	tipo_no *auxiliar;

	while(!pilhaVazia(pilha)) 
             {
               desempilharElemento(pilha);
             }
    
	free(pilha);
    
	return NULL;
}

