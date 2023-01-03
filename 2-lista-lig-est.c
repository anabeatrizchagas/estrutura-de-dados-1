// importando pacotes

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// declarando tamanho padrao do vetor

#define MAX 50

// criando estruturas

typedef struct 
{
    int chave;
    int prox;

} REGISTRO;

typedef struct
{
    int inicio;
    int dispo;
    REGISTRO V[MAX];

} LISTA_LIG_EST;

// declarando funcoes 

void inicializarLista(LISTA_LIG_EST *l);
void exibirLista(LISTA_LIG_EST *l);
void devolverNo(LISTA_LIG_EST *l, int i);

int buscaSeq(LISTA_LIG_EST *l, int ch, int *ant);
int obterNo(LISTA_LIG_EST *l);
int tam(LISTA_LIG_EST *l);
int chavePrimeiroElem(LISTA_LIG_EST *l); // primeiro em ordem logica;
int chaveUltimoElem(LISTA_LIG_EST *l); // ultimo em ordem logica

bool exclucaoDeChave(LISTA_LIG_EST *l, int ch);
bool insercaoOrdSemRep(LISTA_LIG_EST *l, int ch);

// implementando funcoes

void inicializarLista(LISTA_LIG_EST *l)
{
    l->inicio = -1; // lista vazia
    l->dispo = 0; // primeiro no disponivel

    int i;

    for(i= 0; i < MAX - 1; i++) l->V[i].prox = i + 1;
    l->V[MAX - 1].prox = -1; // ultimo no nao tem sucessor

}

void exibirLista(LISTA_LIG_EST *l)
{
    int aux = l->inicio;

    while(aux != -1) 
    {
        printf("%d ", l->V[aux].chave);
        aux = l->V[aux].prox;

    }

}

int buscaSeq(LISTA_LIG_EST *l, int ch, int *ant)
{
    *ant = -1;

    if(l->inicio == -1) return (-1); // lista vazia 

    int aux = l->inicio;

    while(aux != -1)
    {
        if(l->V[aux].chave >= ch) break;

        *ant = aux;
        aux = l->V[aux].prox;

    }
    
    if(l->V[aux].chave == ch) return (aux); // chave encontrada na posicao aux

    return (-1); // chave inexistente 
}

int obterNo(LISTA_LIG_EST *l)
{
    int no = l->dispo;

    if(l->dispo != -1) l->dispo = l->V[l->dispo].prox;

    return (no);

}

void devolverNo(LISTA_LIG_EST *l, int i)
{
    l->V[i].prox = l->dispo;
    l->dispo = i;

}

bool exclucaoDeChave(LISTA_LIG_EST *l, int ch)
{
    int ant, aux;

    aux = buscaSeq(l, ch, &ant);

    if(aux != -1) 
    {
        if(ant == -1) 
        {
            l->inicio = l->V[l->inicio].prox; // exclusao do primeiro elem
        
        } else {

            l->V[ant].prox = l->V[aux].prox; // exclusao de qualquer outro elem

        }

        devolverNo(l, aux);
        return (true);

    }

    return (false);

}

bool insercaoOrdSemRep(LISTA_LIG_EST *l, int ch)
{
    int ant, aux;

    aux = buscaSeq(l, ch, &ant);

    if(aux != -1 || l->dispo == -1) 
    {
        return (false); // chave existente ou lista cheia

    }

    int no = obterNo(l);
    l->V[no].chave = ch;

   if(l->inicio == -1) // lista vazia
   {
        l->inicio = no;
        l->V[l->inicio].prox = -1;

   } else { // lista ja tem elementos

        if(ant == -1) // insercao na primeira posicao
        {
            l->V[no].prox = l->inicio;
            l->inicio = no;

        } else { // insercao em posicao qualquer

            l->V[no].prox = l->V[ant].prox;
            l->V[ant].prox = no;

        }

   }

    return (true);

}

int tam(LISTA_LIG_EST *l)
{
    int cont, aux;

    cont = 0;
    aux = l->inicio;
    
    if(l->inicio != -1)
    {
        while(aux != -1)
        {
            aux = l->V[aux].prox;
            cont++;

        }

    }

    return (cont);

}

int chavePrimeiroElem(LISTA_LIG_EST *l)
{
    if(l->inicio == -1) 
    {
        return (-1); // lista vazia

    } else {

        return (l->V[l->inicio].chave); // primeiro elem

    } 

}

int chaveUltimoElem(LISTA_LIG_EST *l)
{
    int aux = l->inicio;

    if(l->inicio == -1) 
    {
        return (-1); // lista vazia

    } else { // lista com elementos

        while(l->V[aux].prox != -1) aux = l->V[aux].prox;

        return (l->V[aux].chave);

    }

}

int main()
{

    return 0;
}
