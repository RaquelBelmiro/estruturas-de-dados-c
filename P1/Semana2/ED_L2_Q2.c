#include<stdio.h>
#include<stdlib.h>

int *somatorio(int n, int *v);

int main(){

    int n,*v,*w,posicao;
    
    printf("\n\nEntre com a quantidade de numeros do vetor v: ");
    scanf("%d",&n);
    

    v= (int*)(malloc(n*sizeof(int)));

    
    if(v==NULL){
       printf("Erro de alocação de Memoria");
       exit(1);
    }
    
    for(posicao=0;posicao<n;posicao++){
        printf("\n\n Digite o %d elemento do vetor: ", posicao+1);
        scanf("%d", &v[posicao]);
    }
    
   w=somatorio(n,v);
   
   
   printf("\n\n Valor de w:");
   for(posicao=0;posicao<n;posicao++)
       printf("%d ",w[posicao]);
    
    printf("\n\n");
   
    free(v);

    return 0;
}

int *somatorio(int n, int *v){
     int *w,posicao=0;
     
     w= (int*)(malloc(n*sizeof(int)));
    
     if(w==NULL){
       printf("Erro de alocação de Memoria");
       exit(1);
      }
     
    w[0]=v[0];
     for(posicao>0;posicao<n;posicao++){
        w[posicao] = v[posicao] + w[posicao-1];
         
      }

      return w;
}
    
     
    
