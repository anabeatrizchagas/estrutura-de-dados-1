// importando pacotes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// implementando estrutura

typedef struct str
{
    int chave;
    struct str* prox;

} NO;

typedef struct 
{
    NO *cabeca;

} LISTA_CIRC_COM_CABECA;

// declarando funcoes

void inicializarLista(LISTA_CIRC_COM_CABECA *l);
void exibirLista(LISTA_CIRC_COM_CABECA *l);

int tam(LISTA_CIRC_COM_CABECA *l);

NO* retornaPrimeiroElem(LISTA_CIRC_COM_CABECA *l);
NO* retornaEnesimoElem(LISTA_CIRC_COM_CABECA *l, int n);
NO* retornaUltimoElem(LISTA_CIRC_COM_CABECA *l);
NO* buscaSeqOrd(LISTA_CIRC_COM_CABECA *l, int ch, NO** ant);

bool insercaoOrdSemRep(LISTA_CIRC_COM_CABECA *l, int ch);
bool exclusaoDeCh(LISTA_CIRC_COM_CABECA *l, int ch);
bool destruirLista(LISTA_CIRC_COM_CABECA *l);

// implementando funcoes

void inicializarLista(LISTA_CIRC_COM_CABECA *l)
{
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;

}

void exibirLista(LISTA_CIRC_COM_CABECA *l)
{
    NO* aux = l->cabeca->prox;

    while(aux != l->cabeca)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

int tam(LISTA_CIRC_COM_CABECA *l)
{
    int tamanho = 0;
    NO* aux = l->cabeca->prox;

    while(aux != l->cabeca)
    {
        aux = aux->prox;
        tamanho++;

    }

    return (tamanho);

}

NO* retornaPrimeiroElem(LISTA_CIRC_COM_CABECA *l)
{
    if(l->cabeca == l->cabeca->prox) return (NULL); // lista vazia
    else return (l->cabeca->prox); // lista tem elem e deve-se ignorar a cabecaeca

}

NO* retornaEnesimoElem(LISTA_CIRC_COM_CABECA *l, int n) // ?
{
    int cont = 1;
    NO* aux = l->cabeca->prox;

    while(aux != l->cabeca && cont < n)
    {
        aux = aux->prox;
        cont++;

    }

    if(l->cabeca != l->cabeca->prox && cont == n) return (aux); // achou o enesimo
    else return (NULL); // lista vazia ou nao chega a ter n elems

}

NO* retornaUltimoElem(LISTA_CIRC_COM_CABECA *l)
{
    if(l->cabeca == l->cabeca->prox) 
    {
        return (NULL); // lista vazia
    
    } else {

        NO* aux = l->cabeca->prox;

        while(aux->prox != l->cabeca) aux = aux->prox;

        return (aux);

    }

}

NO* buscaSeqOrd(LISTA_CIRC_COM_CABECA *l, int ch, NO** ant)
{

    *ant = l->cabeca;
    l->cabeca->chave = ch;
    NO* aux = l->cabeca->prox;

    while(aux->chave < ch)
    {
        *ant = aux;
        aux = aux->prox;

    }

    if(aux != l->cabeca && ch == aux->chave) return (aux);
    else return (NULL); 

}

bool insercaoOrdSemRep(LISTA_CIRC_COM_CABECA *l, int ch)
{
    NO *existe, *ant;
    existe = buscaSeqOrd(l, ch, &ant);

    if(existe != NULL)
    {
        return (false); // elem ja existe

    } else {

        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = ch;

        novo->prox = ant->prox;
        ant->prox = novo;

        return(true);

    }

}

bool exclusaoDeCh(LISTA_CIRC_COM_CABECA *l, int ch)
{
    NO *existe, *ant, *aux;
    existe = buscaSeqOrd(l, ch, &ant);

    if(l->cabeca == l->cabeca->prox || existe == NULL) 
    {
        return (false); // lista vazia ou elem inexistente

    } else {

        aux = existe;
        ant->prox = existe->prox;
        free(aux);

        return (true);

    }

}

bool destruirLista(LISTA_CIRC_COM_CABECA *l)
{
    if(l->cabeca == l->cabeca->prox)
    {
        return (false); // lista ja esta vazia
    
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

        return (true);

    }

}

// funcao main

int main()
{

    return 0;
}
