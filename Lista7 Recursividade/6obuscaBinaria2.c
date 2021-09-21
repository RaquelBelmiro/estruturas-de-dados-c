#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 1000
void atribuirValores_Unicos(int *vetor);
void ordenar(int *vetor);
int buscaBinaria(int *vetor, int n, int *nComparacoes);

int main(){
    int *vetor, n, i,resultado, nComparacoes=0;

    vetor=(int*)malloc(TAM*sizeof(int));

    atribuirValores_Unicos(vetor);
    ordenar(vetor);

    printf("Vetor:\n");
    for(i=0;i<TAM;i++)
        printf("posicao[%d] valor %d \n",i,vetor[i]);   //printando posicoes e valores para checar funcionamento


    resultado=buscaBinaria(vetor,59, &nComparacoes);
    if(resultado==-1)
       printf("numero 59 nao encontrado no vetor \n");
    else
        printf("numero 59, encontrado na posicao: %d, Numero de Comparacoes: %d \n ", resultado, nComparacoes);

    resultado=buscaBinaria(vetor,5000, &nComparacoes);
    if(resultado==-1)
       printf("numero 5000 nao encontrado no vetor \n");
    else
        printf("numero 5000, encontrado na posicao: %d, Numero de Comparacoes: %d \n ", resultado, nComparacoes);


    free(vetor);
        
     return 0; 
  } 
  
void atribuirValores_Unicos(int *vetor){
     int i,j,aux, valido;
     
    for (i = 0; i < TAM; i++) {
       do {
          vetor[i] = rand() % 10000;
          valido=1;
          for (j = 0; j < i; j++)
             if (vetor[i] == vetor[j])
                valido = 0;
       } while (valido== 0);   
    }
}
void ordenar(int *vetor){
     int i,j,aux;

     for(i=0;i<TAM;i++){
         for(j=0;j<TAM-1;j++){
             if(vetor[j]>vetor[j+1]){
                 aux=vetor[j];
                 vetor[j]=vetor[j+1];
                 vetor[j+1]=aux;
             }
         }
      }
}
             
int buscaBinaria(int *vetor, int n, int *nComparacoes){
    int inicio,meio,fim,pos=0;

    inicio=0;
    fim=TAM-1;

    while(inicio<=fim){
          meio=(inicio+fim)/2;
          if(n<vetor[meio]){
             fim=meio-1;
             *nComparacoes=*nComparacoes+1;
          }
          else{ 
                  if(n>vetor[meio]){
                     inicio=meio+1;
                     *nComparacoes=*nComparacoes+1;
                   }
                  else
                     return meio;
              }
     }
      return -1;
      
}   
