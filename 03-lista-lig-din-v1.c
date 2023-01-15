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
NO* buscaSeqOrd(NO *p, int ch, NO **ant); // funciona para lista em ordem crescente e sem rep
NO* buscaSeqSimples(NO *p, int ch); // funciona para lista em qualquer ordem e sem rep
NO* elemComMaiorChave(NO *p); // funciona para lista em qualquer ordem e sem rep
NO* elemComMenorChave(NO *p); // funciona para lista em qualquer ordem e sem rep

int tam(NO *p);
int somaDasChaves(NO *p);

bool insercaoOrdSemRep(NO** p, int ch);
bool exclusaoCh(NO **p, int ch);
bool destruicaoLista(NO **p);


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

NO* buscaSeqOrd(NO *p, int ch, NO **ant)
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

bool insercaoOrdSemRep(NO** p, int ch)
{
    NO **ant, *aux, *existe;
    aux = *p;
    existe = buscaSeqOrd(aux, ch, ant);

    if(existe != NULL) return (false); // no ja existente na lista

    NO *novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;

    if(*p == NULL)
    {
        *p = novo;
        novo->prox = NULL;

    } else {

        if(*ant == NULL) // insercao no primeiro no
        { 
            novo->prox = aux;
            *p = novo;

        } else { // insercao quando tem anterior

            aux = *ant; 
            novo->prox = aux->prox;
            aux->prox = novo;

        } 

    }

    return (true);

}

bool exclusaoCh(NO **p, int ch)
{
    NO *existe, *aux, *ant;
    aux = *p;
    existe = buscaSeqOrd(aux, ch, &ant);

    if(aux == NULL || existe == NULL) // lista vazia ou elem inexistente
    {
        return (false); 
        
    } else {

        aux = existe;

        if(ant == NULL) // elem e o primeiro da lista
        {
            *p = existe->prox;
            free(aux);

        } else { // elem possui anterior

            ant->prox = existe->prox;
            free(aux);

        }

        return (true);

    }

}

bool destruicaoLista(NO **p)
{
    NO *aux, *prox;
    aux = *p;

    if(*p == NULL) 
    {
        return (false); // lista ja e vazia

    } else { // lista tem elem

        while(aux != NULL)
        {
            prox = aux->prox;
            free(aux);
            aux = prox;

        }

        inicializacaoLista(p);

        return (true);

    }

}

NO* buscaSeqSimples(NO *p, int ch) 
{
    NO *aux = p;

    while(aux != NULL)
    {
        if(aux->chave == ch) return (aux);
        aux = aux->prox;

    }

    return (NULL);

}

NO* elemComMaiorChave(NO *p)
{
    if(p == NULL) return (NULL); // lista vazia;

    NO *aux, *maior;
    aux = p;
    maior = p;

    while(aux != NULL)
    {
        if(maior->chave < aux->chave) maior = aux;
        aux = aux->prox;

    }

    return (maior);  

}

NO* elemComMenorChave(NO *p)
{
    if(p == NULL) return (NULL); // lista vazia

    NO *aux, *menor;
    aux = p;
    menor = p;

    while(aux != NULL)
    {
        if(menor->chave > aux->chave) menor = aux;
        aux = aux->prox;

    }

    return (menor);

}

int somaDasChaves(NO *p)
{
    if(p == NULL) return (-1); // lista vazia

    NO *aux = p;
    int soma = 0;

    while (aux != NULL)
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
