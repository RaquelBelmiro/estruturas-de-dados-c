#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tadArvoreBB3.h"
int main()
{
    tipo_no_arvore arvore, arvoreCopia;
    int chave,aux;
    srand(time(NULL));

    arvore = inicializar_arvore(arvore);
    arvoreCopia= inicializar_arvore(arvoreCopia);

    do{
        aux=rand()%100;
        if(encontrar_elemento(arvore, aux)==0)
           incluir_no_arvore(arvore, aux);
            
      }while(numero_nos(arvore)<50);

    printf("\nListagem da arvore original em ordem:\n");
    percurso_em_ordem(arvore);
    printf("\nListagem da árvore original em pré-ordem:\n");
    percurso_em_pre_ordem(arvore);
    printf("\nListagem da árvore Original em pós-ordem:\n");
    percurso_em_pos_ordem(arvore);
   
    copiarArvore(arvore,arvoreCopia);

    printf("\n\nListagem da arvore copia em ordem:\n");
    percurso_em_ordem(arvoreCopia);
    printf("\nListagem da árvore copia em pré-ordem:\n");
    percurso_em_pre_ordem(arvoreCopia);
    printf("\nListagem da árvore copia em pós-ordem:\n");
    percurso_em_pos_ordem(arvoreCopia);
    
    
    printf("\n\nnumero de nos arvore original: %d \n", numero_nos(arvore));
    printf("quantidade de folhas arvore original:%d \n", qtdFolha(arvore));
    printf("quantidade de NULLs arvore original: %d \n",qtdNull(arvore));
    printf("altura da arvore original: %d \n\n",altura(arvore));

    printf("numero de nos arvore copia: %d \n", numero_nos(arvoreCopia));
    printf("quantidade de folhas arvore copia:%d \n", qtdFolha(arvoreCopia));
    printf("quantidade de NULLs arvore copia: %d \n",qtdNull(arvoreCopia));
    printf("altura da arvore copia: %d \n",altura(arvoreCopia));


    return 0;
}
