// importando pacotes

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

// criando estruturas

typedef struct str
{
    int chave;
    struct str* prox;
    struct str* ant;

} NO;

typedef struct
{
    NO* inicio1;
    NO* inicio2;

} DEQUE;

// declarando funcoes

void inicializacao(DEQUE *d);
void exibicaoPeloInicio1(DEQUE *d);
void exibicaoPeloInicio2(DEQUE *d);

int tamanho(DEQUE *d);
int retirarDoInicio1(DEQUE *d);
int retirarDoInicio2(DEQUE *d);

bool inserirNoInicio1(DEQUE *d, int ch);
bool inserirNoInicio2(DEQUE *d, int ch);

// implementando funcoes

void inicializacao(DEQUE *d)
{
    d->inicio1 = NULL;
    d->inicio2 = NULL;

}

void exibicaoPeloInicio1(DEQUE *d)
{
    NO* aux = d->inicio1;

    while(aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

void exibicaoPeloInicio2(DEQUE *d)
{
    NO* aux = d->inicio2;

    while(aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->ant;

    }

}

int tamanho(DEQUE *d)
{
    int tam = 0;
    NO* aux = d->inicio1;

    while(aux != NULL)
    {
        aux = aux->prox;
        tam++;

    }

    return (tam);

}

bool inserirNoInicio1(DEQUE *d, int ch)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = d->inicio1;
    novo->ant = NULL;

    if(d->inicio1 == NULL && d->inicio2 == NULL) d->inicio2 = novo; // primeira insercao
    else d->inicio1->ant = novo; // lista ja tem elem

    d->inicio1 = novo;

}

bool inserirNoInicio2(DEQUE *d, int ch)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    novo->ant = d->inicio2;

    if(d->inicio1 == NULL && d->inicio2 == NULL) d->inicio1 = novo; // primeira insercao
    else d->inicio2->prox = novo; // lista ja tem elem

    d->inicio2 = novo;

}

int retirarDoInicio1(DEQUE *d)
{
    if(d->inicio1 == NULL)
    {
        return (-1); // lista vazia

    } else {

        int resp = d->inicio1->chave;

        NO* aux = d->inicio1->prox;
        free(d->inicio1);
        d->inicio1 = aux;
        d->inicio1->ant = NULL;

        if(d->inicio1 == NULL) d->inicio2 = NULL;

        return (resp);

    }

}

int retirarDoInicio2(DEQUE *d)
{
    if(d->inicio2 == NULL)
    {
        return (-1);

    } else {

        int resp = d->inicio2->chave;

        NO* aux = d->inicio2->ant;
        free(d->inicio2);
        d->inicio2 = aux;
        d->inicio2->prox = NULL;

        if(d->inicio2 == NULL) d->inicio1 = NULL;

        return (resp);

    }

}

// funcao main

int main()
{

    return 0;
}