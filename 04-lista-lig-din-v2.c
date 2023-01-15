// importando pacotes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// implementando estruturas

typedef struct str
{
    int chave;
    struct str *prox;
    
} NO;

typedef struct 
{
    NO *inicio;

} LISTA_LIG_DIN;

// declarando funcoes

void inicializacaoLista(LISTA_LIG_DIN *l);
void exibicaoLista(LISTA_LIG_DIN *l);
void anexarElem(LISTA_LIG_DIN *l, int ch);

int tam(LISTA_LIG_DIN *l);

NO* primeiroElem(LISTA_LIG_DIN *l);
NO* enesimoElem(LISTA_LIG_DIN *l, int n);
NO* ultimoElem(LISTA_LIG_DIN *l);
NO* buscaSeqOrd(LISTA_LIG_DIN *l, int ch, NO** ant);

bool insercaoOrdSemRep(LISTA_LIG_DIN *l, int ch);
bool exclusaoCh(LISTA_LIG_DIN *l, int ch);
bool destruirLista(LISTA_LIG_DIN *l);

// implementando funcoes

void inicializacaoLista(LISTA_LIG_DIN *l)
{
    l->inicio = NULL;

}

void exibicaoLista(LISTA_LIG_DIN *l)
{
    NO* aux = l->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    } 

}

NO* primeiroElem(LISTA_LIG_DIN *l)
{
    return (l->inicio);

}

NO* enesimoElem(LISTA_LIG_DIN *l, int n)
{
    NO* aux = l->inicio;
    int cont = 1;

    while (aux != NULL && cont < n)
    {
        aux = aux->prox;
        cont++;

    }

    if(aux != NULL && cont == n) return (aux); // encontrou o enesimo elem
    else return (NULL); // lista vazia ou nao existe n elems
    
}

NO* ultimoElem(LISTA_LIG_DIN *l)
{
    NO* aux = l->inicio;

    while(aux->prox != NULL) aux = aux->prox;

    return (aux);

}

int tam(LISTA_LIG_DIN *l)
{
    int tamanho = 0;
    NO* aux = l->inicio;

    while(aux != NULL)
    {
        aux = aux->prox;
        tamanho++;

    }

    return (tamanho);

}

NO* buscaSeqOrd(LISTA_LIG_DIN *l, int ch, NO** ant)
{
    *ant = NULL;
    NO* aux = l->inicio;

    while (aux != NULL)
    {
        if(aux->chave >= ch) break;
        *ant = aux;
        aux = aux->prox;

    }

    if(aux != NULL) if (aux->chave == ch) return (aux);
    
    else return (NULL);   

}

bool insercaoOrdSemRep(LISTA_LIG_DIN *l, int ch)
{
    NO *aux, *existe, *ant;
    existe = buscaSeqOrd(l, ch, &ant);

    if(existe != NULL) // chave ja existe na lista
    {
        return (false);

    } else {

        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = ch;

        if(l->inicio == NULL) // lista vazia
        {
            novo->prox = NULL;
            l->inicio = novo;

        } else { // lista com elementos

            if(ant == NULL) // insercao do primeiro elem
            {
                aux = l->inicio;
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

bool exclusaoCh(LISTA_LIG_DIN *l, int ch)
{
    NO *existe, *ant, *aux;
    existe = buscaSeqOrd(l, ch, &ant);

    if(existe == NULL) 
    {
        return (false); // chave nao existe

    } else { // chave existe

        if(ant == NULL) // exclusao do primeiro elem
        {
            aux = l->inicio;
            l->inicio = l->inicio->prox;
            free(aux);

        } else { // exclusao de elem com anterior

            aux = existe;
            ant->prox = existe->prox;
            free(aux);

        }

        return (true);

    }

}

void anexarElem(LISTA_LIG_DIN *l, int ch)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    NO* aux = l->inicio;

    if(l->inicio == NULL) // lista vazia
    {
        l->inicio = novo;
    
    } else { // lista com elem

        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;

    }

}

bool destruirLista(LISTA_LIG_DIN *l)
{

    if(l->inicio == NULL) // lista ja esta vazia
    {
        return (false); 

    } else {

        NO* aux = l->inicio;
        NO *prox;

        while(aux != NULL)
        {
            prox = aux->prox;
            free(aux);
            aux = prox;

        }
        
        l->inicio = NULL;

        return (true);

    }
    
}

// funcao main

int main()
{

    return 0;
}
