#include<stdio.h>
#include"lista_inicio_TAD.h"

void imprimirLista(tipo_lista* lista)
{
    int *elementosLista, posicao;
    elementosLista = obterElementosLista(lista);  //elementos lista vai apontar para o endereco do vetor de elementos obtidos retornado pela funcao 
    
    for (posicao = 0; posicao < quantidadeElementosLista(lista); posicao++)
    {
        printf("%d ", elementosLista[posicao]);
    }
    printf("\n");
}

int main()
{
    tipo_lista *lista1=NULL, *lista2=NULL;

    lista1 = criarListaVazia();
    lista2 = criarListaVazia();
    
    
     //inserindo na lista1
     inserirElementoInicio(lista1, 3);
     inserirElementoInicio(lista1, 2);
     inserirElementoInicio(lista1, 1);
     inserirElementoInicio(lista1, 30);
     inserirElementoInicio(lista1, 20);
     inserirElementoInicio(lista1, 40);
     printf("\n\n Elementos da Lista1:");
     imprimirLista(lista1);
     
     //excluindo elemento de inicio lista1
     printf("\n lista apos exclusao no inicio: ");
     excluirElementoInicio(lista1);
     imprimirLista(lista1);
     printf("\n lista apos exclusao no inicio: ");
     excluirElementoInicio(lista1);
     imprimirLista(lista1);
     printf("\n lista apos exclusao no inicio: ");
     excluirElementoInicio(lista1);
     imprimirLista(lista1);
    
     if(listaVazia(lista1))
        printf("\n A lista1 esta vazia");
        else
            printf("\n A lista1 nao esta vazia ");
     printf("\n\n Quantidade de elementos lista1: %d \n", quantidadeElementosLista(lista1));

     //inserindo na lista2
     inserirElementoInicio(lista2, 6);
     inserirElementoInicio(lista2, 5);
     inserirElementoInicio(lista2, 4);
     printf("\n Elementos da Lista2: ");
     imprimirLista(lista2);
     
     printf("\n Elementos da lista 1 e 2 concatenados: ");
     concatenarListas(lista1,lista2);
     imprimirLista(lista1);

     lista2=apagarLista(lista2);
      if (!lista2)
      {
        printf("\n Lista2 apagada! \n\n");
      }
     else
        {
          printf("A lista2 ainda existe! \n\n");
        }

    return 0;
}
