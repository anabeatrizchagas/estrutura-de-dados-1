// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

// implementando estruturas

typedef struct str
{
    int chave;
    struct str* ant;
    struct str* prox;

} NO;

typedef struct 
{
    NO* cabeca;

} LISTA_DUP_CIR_CAB;

// declarando estruturas

void inicializarLista(LISTA_DUP_CIR_CAB *l);
void exibirLista(LISTA_DUP_CIR_CAB *l);

int tam(LISTA_DUP_CIR_CAB *l);

NO* retornaPrimeiroElem(LISTA_DUP_CIR_CAB *l);
NO* retornaEnesimoElem(LISTA_DUP_CIR_CAB *l, int n);
NO* retornaUltimoElem(LISTA_DUP_CIR_CAB *l);

bool insercaoOrdSemRep(LISTA_DUP_CIR_CAB *l, int ch);
bool exclusaoDeCh(LISTA_DUP_CIR_CAB *l, int ch);
bool destruirLista(LISTA_DUP_CIR_CAB *l);

// implementando estruturas

void inicializarLista(LISTA_DUP_CIR_CAB *l)
{
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;

}

void exibirLista(LISTA_DUP_CIR_CAB *l)
{
    NO* aux = l->cabeca->prox;

    while(aux != l->cabeca)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

int tam(LISTA_DUP_CIR_CAB *l)
{
    int tamanho = 0;
    NO* aux = l->cabeca->prox;

    while(aux != l->cabeca)
    {
        aux = aux->prox;
        tamanho++;

    }

    return(tamanho);

}

NO* retornaPrimeiroElem(LISTA_DUP_CIR_CAB *l)
{
    if(l->cabeca == l->cabeca->prox && l->cabeca == l->cabeca->ant) 
    {
        return (NULL); // lista vazia
    
    } else return (l->cabeca->prox); // lista com elem

}

NO* retornaEnesimoElem(LISTA_DUP_CIR_CAB *l, int n)
{
    NO* aux = l->cabeca->prox;
    int cont = 1;

    while(aux != l->cabeca && cont != n)
    {
        aux = aux->prox;
        cont++;

    }

    if(aux != l->cabeca && cont == n) return (aux); // achou o enesimo elem
    else return(NULL); // lista vazia ou com menos de n elems

}

NO* retornaUltimoElem(LISTA_DUP_CIR_CAB *l)
{
    if(l->cabeca == l->cabeca->prox && l->cabeca == l->cabeca->ant)
    {
        return (NULL); // lista vazia

    } else {

        NO* aux = l->cabeca->prox;

        while(aux->prox != l->cabeca) aux = aux->prox;

        return(aux);

    }

}

bool insercaoOrdSemRep(LISTA_DUP_CIR_CAB *l, int ch)
{
    NO* aux = l->cabeca->prox;
    l->cabeca->chave = ch;

    while(aux->chave < ch) aux = aux->prox;

    if(aux->chave == ch && aux != l->cabeca)
    {
        return (false); // chave ja existe na lista
    
    } else {

        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = ch;

        aux->ant->prox = novo;
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant = novo;

    }

}

bool exclusaoDeCh(LISTA_DUP_CIR_CAB *l, int ch)
{
    NO* aux = l->cabeca->prox;
    l->cabeca->chave = ch;

    while(aux->chave < ch) aux = aux->prox;

    if(aux != l->cabeca && aux->chave == ch)
    {
        aux->ant->prox = aux->prox;
        free(aux);

        return (true);

    } else return (false);

}

bool destruirLista(LISTA_DUP_CIR_CAB *l)
{
    if(l->cabeca == l->cabeca->prox && l->cabeca == l->cabeca->ant)
    {
        return (false); // lista vazia

    } else {

        NO *atual, *prox;
        atual = l->cabeca->prox;

        while(atual != l->cabeca)
        {
            prox = atual->prox;
            free(atual);
            atual = prox;
        
        }

        l->cabeca->prox = l->cabeca;
        l->cabeca->ant = l->cabeca;

        return (true); // destruiu

    }

}

// funcao main

int main()
{

    return 0;
}