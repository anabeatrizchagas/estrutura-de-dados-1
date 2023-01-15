// importando pacotes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// implementando estruturas

typedef struct str
{
    int chave;
    struct str* prox;

} NO;

typedef struct 
{
    NO* inicio;
    NO* sentinela;

} LISTA_DIN_SENT;

// declarando funcoes

void inicializarLista(LISTA_DIN_SENT *l);
void exibirLista(LISTA_DIN_SENT *l);
void anexarElem(LISTA_DIN_SENT *l, int ch);

int tam(LISTA_DIN_SENT *l);
int somaDeCh(LISTA_DIN_SENT *l);

NO* retornaPrimeiroElem(LISTA_DIN_SENT *l);
NO* retornaEnesimoElem(LISTA_DIN_SENT *l, int n);
NO* retornaUltimoElem(LISTA_DIN_SENT *l);
NO* buscaSeqOrd(LISTA_DIN_SENT *l, int ch, NO** ant);

bool insercaoOrdSemRep(LISTA_DIN_SENT *l, int ch);
bool exclusaoDeCh(LISTA_DIN_SENT *l, int ch);
bool destruirLista(LISTA_DIN_SENT *l);

// implementando funcoes

void inicializarLista(LISTA_DIN_SENT *l)
{
    l->sentinela = (NO*) malloc(sizeof(NO));
    l->inicio = l->sentinela;

}

void exibirLista(LISTA_DIN_SENT *l)
{
    NO* aux = l->inicio;

    while(aux != l->sentinela)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

NO* retornaPrimeiroElem(LISTA_DIN_SENT *l)
{
    if(l->inicio == l->sentinela) return (NULL); // lista vazia
    else return (l->inicio); // tem elem
 
}

NO* retornaEnesimoElem(LISTA_DIN_SENT *l, int n)
{
    if(l->inicio == l->sentinela)
    {
        return (NULL); // lista vazia

    } else { // lista tem elem

        NO* aux = l->inicio;
        int cont = 1;

        while(aux != l->sentinela && cont < n)
        {
            aux = aux->prox;
            cont++;

        }

        if(cont == n) return (aux); // achou o enesimo elem
        else return (NULL); // lista nao chega a ter n elems

    }
    
}

NO* retornaUltimoElem(LISTA_DIN_SENT *l)
{
    if(l->inicio == l->sentinela)
    {
        return (NULL); // lista vazia
    
    } else { // lista tem elem
        
        NO* aux = l->inicio;

        while(aux->prox != l->sentinela) aux = aux->prox;

        return (aux);

    }

}

int tam(LISTA_DIN_SENT *l)
{
    int cont = 0;
    NO* aux = l->inicio;

    while(aux != l->sentinela)
    {
        aux = aux->prox;
        cont++;

    }

    return (cont);

}

NO* buscaSeqOrd(LISTA_DIN_SENT *l, int ch, NO** ant)
{
    if(l->inicio == l->sentinela)
    {
        return (NULL); // lista vazia
    
    } else {

        NO* aux = l->inicio;
        *ant = NULL;
        l->sentinela->chave = ch;

        while(aux->chave < ch)
        {
            *ant = aux;
            aux = aux->prox;

        }

        if(aux != l->sentinela && ch == aux->chave) return (aux); // ch existe na lista
        else return (NULL); // ch nao existe na lista

    }
    
}

bool insercaoOrdSemRep(LISTA_DIN_SENT *l, int ch)
{
    NO *existe, *aux, *ant;
    existe = buscaSeqOrd(l, ch, &ant);

    if(existe != NULL) 
    {
        return (false); // chave ja existe

    } else { // chave nova

        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = ch;

        if(l->inicio == l->sentinela) { // lista vazia

            novo->prox = l->sentinela;
            l->inicio = novo;

        } else { // lista com elem

            if(ant == NULL) // primeiro elem
            {
                novo->prox = aux;
                l->inicio = novo;   

            } else { // elem com anterior

                aux = ant->prox;
                novo->prox = aux;
                ant->prox = novo;

            }

        }

        return (true);

    }

}

void anexarElem(LISTA_DIN_SENT *l, int ch)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = l->sentinela;

    if(l->inicio == l->sentinela) 
    {
        l->inicio = novo;

    } else {

        NO* aux = l->inicio;

        while(aux->prox != l->sentinela) aux = aux->prox;

        aux->prox = novo;

    }

}

bool exclusaoDeCh(LISTA_DIN_SENT *l, int ch)
{
    NO *aux, *existe, *ant;
    existe = buscaSeqOrd(l, ch, &ant);

    if(existe == NULL || l->inicio == l->sentinela) 
    {
        return (false); // lista vazia ou elem inexistente

    } else {

        aux = existe;

        if(ant == NULL) l->inicio = existe->prox; // exclusao primeiro elem
        else ant->prox = existe->prox; // exclusao elem com anterior

        free(aux);
        return(true);

    }

}

bool destruirLista(LISTA_DIN_SENT *l)
{
    if(l->inicio == l->sentinela)
    {
        return (false); // lista ja esta vazia

    } else {

        NO *atual, *prox;
        atual = l->sentinela;

        while(atual != l->sentinela)
        {
            prox = atual->prox;
            free(atual);
            atual = prox;

        }

        l->inicio = l->sentinela;

        return (true);

    }

}

int somaDeCh(LISTA_DIN_SENT *l)
{
    int soma = 0;
    NO* aux = l->inicio;

    while(aux != l->sentinela)
    {
        soma = soma + aux->chave;
        aux = aux->prox;

    }

    return (soma);

}

// funcao main

int main()
{

    return 0;
}
