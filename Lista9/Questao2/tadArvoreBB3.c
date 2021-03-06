#include<stdio.h>
#include<stdlib.h>

struct reg_no_arvore
{
    struct reg_no_arvore *ptrEsquerda;
    int chave;
    struct reg_no_arvore *ptrDireita;
};
typedef struct reg_no_arvore **tipo_no_arvore;


tipo_no_arvore inicializar_arvore(tipo_no_arvore sub_raiz)
{
    sub_raiz = (struct reg_no_arvore**)malloc(sizeof(struct reg_no_arvore*));
    *sub_raiz = NULL;
}

void incluir_no_arvore(tipo_no_arvore sub_raiz, int chave)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = malloc(sizeof(struct reg_no_arvore));
        (*sub_raiz)->chave = chave;
        (*sub_raiz)->ptrEsquerda = NULL;
        (*sub_raiz)->ptrDireita = NULL;
    }
    else
    {
        if (chave < (*sub_raiz)->chave)
        {
            incluir_no_arvore(&((*sub_raiz)->ptrEsquerda), chave);
        }
        else
        {
            if (chave > (*sub_raiz)->chave)
            {
                incluir_no_arvore(&((*sub_raiz)->ptrDireita), chave);
            }
        }
    }
}

void percurso_em_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_ordem(&((*sub_raiz)->ptrEsquerda));
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pre_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        printf("%d ", (*sub_raiz)->chave);
        percurso_em_pre_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pre_ordem(&((*sub_raiz)->ptrDireita));
    }
}

void percurso_em_pos_ordem(tipo_no_arvore sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        percurso_em_pos_ordem(&((*sub_raiz)->ptrEsquerda));
        percurso_em_pos_ordem(&((*sub_raiz)->ptrDireita));
        printf("%d ", (*sub_raiz)->chave);
    }
}

int encontrar_elemento(tipo_no_arvore sub_raiz, int chave)
{
    if ((*sub_raiz) == NULL)
    {
        return 0;
    }
    else
    {
        if (chave == (*sub_raiz)->chave)
        {
            return 1;
        }
        else
        {
            if (chave < (*sub_raiz)->chave)
            {
                return encontrar_elemento(&((*sub_raiz)->ptrEsquerda), chave);
            }
            else
            {
                if (chave > (*sub_raiz)->chave)
                {
                    return encontrar_elemento(&((*sub_raiz)->ptrDireita), chave);
                }
            }
        }
    }
}

int numero_nos(tipo_no_arvore sub_raiz){

    if (*sub_raiz != NULL)
     { 
        return 1+numero_nos(&((*sub_raiz)->ptrEsquerda))+numero_nos(&((*sub_raiz)->ptrDireita));
     }
    
    return 0;
}

int qtdFolha(tipo_no_arvore sub_raiz){

     if (*sub_raiz !=NULL)
    {
        if(((*sub_raiz)->ptrEsquerda==NULL) && ((*sub_raiz)->ptrDireita==NULL))              //se tanto o n?? da esquerda quanto da direita for null ?? folha
	       return 1+qtdFolha(&(*sub_raiz)->ptrEsquerda) + qtdFolha(&(*sub_raiz)->ptrDireita); //incrementa o retorno
     
        else 
           return qtdFolha(&(*sub_raiz)->ptrDireita) + qtdFolha(&(*sub_raiz)->ptrEsquerda); // se n??o o ciclo continua
    }
    else
        return 0;
}
int qtdNull(tipo_no_arvore sub_raiz){ //editar
    int somaEsquerda=0, somaDireita=0;
    if (*sub_raiz !=NULL)
    {
	           return  qtdNull(&(*sub_raiz)->ptrEsquerda)+qtdNull(&(*sub_raiz)->ptrDireita);
    }
    else
        return 1;
}
int altura(tipo_no_arvore sub_raiz){
   
    if (*sub_raiz !=NULL)
    {
      if( altura(&((*sub_raiz)->ptrEsquerda)) > altura(&((*sub_raiz)->ptrDireita)))
         return 1+altura(&(*sub_raiz)->ptrEsquerda);
      else
           return 1+altura(&(*sub_raiz)->ptrDireita);
    }
   return 0;
}

void copiarArvore(tipo_no_arvore sub_raiz_original, tipo_no_arvore sub_raiz_copia){
 

     if(*sub_raiz_original!=NULL){                                           //Verifica se a ??rvore ?? diferente de NULL se for manda inserir a raiz
                                                                             //em seguidaa direita, depois tudo a esquerda.*/
        incluir_no_arvore(sub_raiz_copia,(*sub_raiz_original)->chave);
        copiarArvore(&((*sub_raiz_original)->ptrDireita),sub_raiz_copia);
        copiarArvore(&((*sub_raiz_original)->ptrEsquerda),sub_raiz_copia);
        
     }
       
}
