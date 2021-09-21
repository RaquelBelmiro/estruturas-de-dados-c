#include<stdlib.h>
#include<stdio.h>
#define TAM 100

typedef struct conjunto{
       
        int *vetor;
        int tamanho;
}tipo_conjunto;

tipo_conjunto *cria_conjunto_vazio(tipo_conjunto *conjunto){

      int i;
      
      conjunto= (tipo_conjunto*) malloc(sizeof(tipo_conjunto));
      
      
      conjunto->vetor = (int*)malloc(sizeof(int)*TAM);

      for(i=0;i<TAM;i++){
	  conjunto->vetor[i]=0;
      }
	
      return conjunto;
}

tipo_conjunto *insere_elemento(tipo_conjunto *conjunto, int numero){
      
      conjunto->vetor[numero]=1;
      conjunto->tamanho++;
     
      return conjunto;
}
int remove_elemento(tipo_conjunto *conjunto, int numero) {
    int i;
       
       for(i=0;i<TAM;i++){
           if(conjunto->vetor[numero]==0){
              return 0;
            }
              else{
                   conjunto->vetor[numero]=0;
                   conjunto->tamanho--;
                   return 1;
                   }
      }
       
}

tipo_conjunto *une_conjuntos(tipo_conjunto *conjunto1, tipo_conjunto *conjunto2){
    
    int i;
    tipo_conjunto *conjunto3;
    
    conjunto3=(tipo_conjunto*) malloc(sizeof(tipo_conjunto));
    
    for(i = 0; i<TAM;i++){
        if((conjunto1->vetor[i]==1) ||(conjunto2->vetor[i]==1)) {
    
            conjunto3->vetor[i]=1;                   
         }
     }
   
    return conjunto3;
}
tipo_conjunto *interseccao(tipo_conjunto *conjunto1, tipo_conjunto *conjunto2) {
     int i; 

     tipo_conjunto *conjunto3;
    
     conjunto3=(tipo_conjunto*) malloc(sizeof(tipo_conjunto));
    
     for(i = 0; i<TAM;i++){
         if((conjunto1->vetor[i]==1)&&(conjunto2->vetor[i]==1)) {
             conjunto3->vetor[i]=1;                                       
          }
      }
    
      return conjunto3;
}

tipo_conjunto *diferenca(tipo_conjunto *conjunto1, tipo_conjunto *conjunto2){
     int i; 
     
     tipo_conjunto *conjunto3;
    
    conjunto3=(tipo_conjunto*) malloc(sizeof(tipo_conjunto));
     
     for(i = 0; i<TAM;i++){
         if((conjunto1->vetor[i]==1) && (conjunto2->vetor[i]==0)) {
             conjunto3->vetor[i]=1;                                    
          }
     }
     return conjunto3;
}
int verifica_numero(tipo_conjunto *conjunto, int numero) {
    int i;

    for(i=0;i<TAM;i++){
        if(conjunto->vetor[i]==numero)
           return 1;
      }
     return 0;
}
int verifica_menor(tipo_conjunto *conjunto){
     int i;
     
     for(i = 0; i<TAM;i++){
         if (conjunto->vetor[i]==1) {
              return i;
          }
      }
      return -1;
}
int verifica_maior(tipo_conjunto *conjunto){
    int i;
    
        for(i = TAM - 1; i>-1;i--){
            if (conjunto->vetor[i]==1) {
                return i;
             }
        }
     return -1;
}
int testa_igualdade(tipo_conjunto *conjunto1, tipo_conjunto *conjunto2){
     int i;
     
     for(i = 0; i<TAM;i++){
         if (conjunto1->vetor[i]!=conjunto2->vetor[i]) {
             return 0;
          }
      }
     return 1;
}
int tamanho(tipo_conjunto *conjunto){
     int tam;
     
     tam=conjunto->tamanho;
     
     return tam;
}
int testa_vazio(tipo_conjunto *conjunto){
     int i;

     for(i = 0; i<TAM;i++){
         if (conjunto->vetor[i]==1) {
             return 0;
          }
      }
     return 1;
}
int *imprime_conjunto(tipo_conjunto *conjunto, int *vetor){  
    int i,j, tam;
    tam=conjunto->tamanho;
    
    vetor=(int*)(malloc(sizeof(int)*tam));
    
    for(i=0;i<TAM;i++){
        for(j=0;j<tam;j++){
            if(conjunto->vetor[i]==1){
                     vetor[j]=i;
             }
          }
      }
           
    return vetor;
}

tipo_conjunto *libera(tipo_conjunto *conjunto){

      free(conjunto->vetor);
      free(conjunto);
      
      return NULL;
}
