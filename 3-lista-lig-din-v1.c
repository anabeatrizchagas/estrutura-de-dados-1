// LISTA LIGADA DINAMICA NA VERSAO 1 (UTILIZANDO APENAS A STRUCT 'NO')

// importando pacotes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// implementando estrutura

typedef struct estr
{
    int chave;
    struct estr *prox;

} NO;

// declarando funcoes 

void inicializacaoLista(NO **p); 
void exibicaoLista(NO *p); 
void insercaoSimples(NO **p, int ch); 

NO* primeiroElem(NO *p);
NO* ultimoElem(NO *p);
NO* enesimoElem(NO *p, int n);
NO* buscaSeq(NO *p, int ch, NO **ant);

int tam(NO *p);

// implementando funcoes

void inicializacaoLista(NO **p)
{
    *p = NULL;

}

void exibicaoLista(NO *p)
{
    NO *aux = p;

    while(aux != NULL) 
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

NO* primeiroElem(NO *p)
{
    return (p); // p pode ter chave ou ser NULL em caso de lista vazia

}

NO* ultimoElem(NO *p)
{
    if (p == NULL) return (NULL); // lista vazia

    NO *aux = p;

    while(aux->prox != NULL) aux = aux->prox;

    return (aux);

}

NO* enesimoElem(NO *p, int n)
{
    int cont = 0;
    NO* aux = p;

    while(aux != NULL && cont != n - 1)
    {
        aux = aux->prox;
        cont++;

    }

    if(cont == n - 1) return (aux);
    
    return (NULL); // lista vazia ou elem inexistente

}

void insercaoSimples(NO **p, int ch)
{
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if(*p == NULL) // lista vazia
    {
        *p = novo;

    } else {

        NO *aux = *p;

        while(aux->prox != NULL) aux = aux->prox;

        aux->prox = novo;
    
    }

}

int tam(NO *p)
{
    int cont = 0;
    NO *aux = p;

    while(aux != NULL)
    {
        aux = aux->prox;
        cont++;

    }

    return (cont);

}

NO* buscaSeq(NO *p, int ch, NO **ant)
{
    if (p == NULL) return (NULL); // lista vazia

    *ant = NULL;
    NO *aux = p;

    while(aux != NULL) 
    {
        if(aux->chave >= ch) break;

        *ant = aux;
        aux = aux->prox;

    }

    if(aux->chave == ch) return (aux); // encontrou
    else return (NULL); // nao encontrou

}

// funcao main 

int main()
{

    return 0;
}