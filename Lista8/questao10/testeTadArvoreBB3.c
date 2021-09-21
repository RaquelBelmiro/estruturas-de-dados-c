#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"tadArvoreBB3.h"
int main()
{
    tipo_no_arvore arvore;
    int chave,aux;
    //srand(time(NULL));

    arvore = inicializar_arvore(arvore);

    do{
        aux=rand()%10000;
        if(encontrar_elemento(arvore, aux)==0)
           incluir_no_arvore(arvore, aux);
            
      }while(numero_nos(arvore)<1000);

    
    printf("\nListagem em ordem:\n");
    percurso_em_ordem(arvore);
    printf("\nListagem em pré-ordem:\n");
    percurso_em_pre_ordem(arvore);
    printf("\nListagem em pós-ordem:\n");
    percurso_em_pos_ordem(arvore);
    printf("\nEncontrar 45: %d", encontrar_elemento(arvore, 45));
    printf("\nEncontrar 44: %d \n", encontrar_elemento(arvore, 44));

    printf("\nMenor Valor : %d \n", menor_valor(arvore));
    printf("Maior Valor : %d \n", maior_valor(arvore));
    printf("Soma dos valores : %d \n", soma_nos(arvore));
    printf("numero de nos: %d \n", numero_nos(arvore));
    printf("media: %d \n", calcula_media(arvore));
    printf("quantidade de folhas:%d \n", qtdFolha(arvore));
    printf("quantidade de NULLs: %d \n",qtdNull(arvore));
    printf("altura da arvore: %d \n",altura(arvore));
    printf("quantidade de nos multiplos de 3: %d \n",qtdMultiplo3(arvore));

    printf("Numero de comparacoes em busca 59: %d \n",nComparacoes_busca(arvore,59));    //ncomparacoes de 59: 5 - lista anterior: ncomparacoes de 59: 9
    printf("Numero de comparacoes em busca 5000: %d \n",nComparacoes_busca(arvore,5000));//ncomparacoes de 5000: 15 lista anterior: ncomparacoes de 5000: 15

     
    return 0;
}
