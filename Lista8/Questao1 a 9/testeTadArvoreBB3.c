#include<stdio.h>
#include"tadArvoreBB3.h"
int main()
{
    tipo_no_arvore arvore;
    int chave,resultado;

    arvore = inicializar_arvore(arvore);

    incluir_no_arvore(arvore, 100);
    incluir_no_arvore(arvore, 50);
    incluir_no_arvore(arvore, 150);
    incluir_no_arvore(arvore, 25);
    incluir_no_arvore(arvore, 75);
    incluir_no_arvore(arvore, 45);
    incluir_no_arvore(arvore, 35);
    incluir_no_arvore(arvore, 48);
    incluir_no_arvore(arvore, 125);
    incluir_no_arvore(arvore, 150);
    incluir_no_arvore(arvore, 175);
    incluir_no_arvore(arvore, 165);
    incluir_no_arvore(arvore, 160);

    printf("\nListagem em ordem:\n");
    percurso_em_ordem(arvore);
    printf("\nListagem em pré-ordem:\n");
    percurso_em_pre_ordem(arvore);
    printf("\nListagem em pós-ordem:\n");
    percurso_em_pos_ordem(arvore);

    printf("\n\nMenor Valor : %d \n", menor_valor(arvore));
    printf("Maior Valor : %d \n", maior_valor(arvore));
    printf("Soma dos valores : %d \n", soma_nos(arvore));
    printf("numero de nos: %d \n", numero_nos(arvore));
    printf("media: %d \n", calcula_media(arvore));
    printf("quantidade de folhas:%d \n", qtdFolha(arvore));
    printf("quantidade de NULLs: %d \n",qtdNull(arvore));
    printf("altura da arvore: %d \n",altura(arvore));
    printf("quantidade de nos multiplos de 3: %d \n",qtdMultiplo3(arvore));

    printf("Numero de comparacoes em busca do numero 25: %d \n", nComparacoes_busca(arvore, 25));
    printf("Numero de comparacoes em busca do numero 175: %d \n", nComparacoes_busca(arvore, 175));
    printf("Numero de comparacoes em busca do numero 48: %d \n", nComparacoes_busca(arvore, 48));

    return 0;
}
