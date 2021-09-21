#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main(){

	tipo_pilha *pilha;
	char *frase,**aux;

	pilha=criarPilha();
    
    
	printf("\n Digite a frase a ser empilhada: ");
    scanf(" %[^\n]s", frase);

    if(empilharElemento(pilha, frase))
       printf("\n --Elemento Empilhado com sucesso \n");
    else
        printf("\n --Erro ao empilhar Elemento");
   
   if(verificaParenteses(pilha))
      printf("\nNumero de abre parenteses e de fecha parentesis e gual\n ");
   else
      printf("\nNumero de abre parenteses e de fecha parentesis nao e gual\n ");

   inverterFrase(pilha);

   aux=obterElementosPilha(pilha);
   printf("\nfrase invertida: %s\n", *aux);
    
   
   pilha=apagarPilha(pilha);
   if(pilha==NULL)
	  printf("\n Pilha apagada com sucesso, Encerrando o programa \n");
   else
	 printf("\n A pilha ainda existe \n");


  return 0;

}
