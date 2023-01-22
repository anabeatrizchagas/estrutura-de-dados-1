// importando pacotes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// criando estruturas

typedef struct str
{
    int chave;
    struct str* prox;

} NO;

typedef struct
{
    NO* topo;

} PILHA_DIN;

// declarando funcoes

void inicializacao(PILHA_DIN *p);
void exibicao(PILHA_DIN *p);

int tamanho(PILHA_DIN *p);
int pop(PILHA_DIN *p);

bool push(PILHA_DIN *p, int ch);

// implementando funcoes

void inicializacao(PILHA_DIN *p)
{
    p->topo = NULL;

}

void exibicao(PILHA_DIN *p)
{
    NO* aux = p->topo;

    while(aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

int tamanho(PILHA_DIN *p)
{
    int tam = 0;
    NO* aux = p->topo;

    while(aux != NULL) 
    {
        aux = aux->prox;
        tam++;

    }

    return (tam);

}

int pop(PILHA_DIN *p)
{
    if(p->topo == NULL)
    {
        return (-1);

    } else {

        int resp = p->topo->chave;

        NO* aux = p->topo->prox;
        free(p->topo);
        p->topo = aux;

        return (resp);

    }

}

bool push(PILHA_DIN *p, int ch)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = p->topo;
    p->topo = novo;

}

// funcao main

int main()
{

    return 0;
}