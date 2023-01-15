// importando pacotes

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// definindo tamanho do vetor utilizado na lista seq

#define MAX 50

// criando estrutura

typedef struct 
{
    int chave; 

} REGISTRO;

typedef struct 
{
    REGISTRO V[MAX];
    int qtdElem;

} LISTA_SEQ;

// declarando as funcoes 

void inicializarLista(LISTA_SEQ *l);
void imprimirLista(LISTA_SEQ *l);
void destruirLista(LISTA_SEQ *l);
void ordenarLista(LISTA_SEQ *l);

int tamLista(LISTA_SEQ *l);
int chavePrimeiroElem(LISTA_SEQ *l);
int chaveUltimoElem(LISTA_SEQ *l);
int chaveEnesimoElem(LISTA_SEQ *l, int n);
int indiceAntecessor(LISTA_SEQ *l, int ch);
int buscaSeq(LISTA_SEQ *l, int ch);
int buscaBin(LISTA_SEQ *l, int ch);

bool inserirNoFim(LISTA_SEQ *l, int ch);
bool inserirNoIndice(LISTA_SEQ *l, int i, int ch);
bool inserirOrdenado(LISTA_SEQ *l, int ch);

// implementando funcoes 

void inicializarLista(LISTA_SEQ *l)
{
    l->qtdElem = 0;

}

void imprimirLista(LISTA_SEQ *l)
{
    int i;

    for(i = 0; i < l->qtdElem; i++) 
    {
        printf("%d ", l->V[i].chave);

    }

}

int tamLista(LISTA_SEQ *l)
{
    return (l->qtdElem);

}

int chavePrimeiroElem(LISTA_SEQ *l)
{
    if(l->qtdElem != 0) return(l->V[0].chave);
    else return (-1);

}

int chaveUltimoElem(LISTA_SEQ *l)
{
    if(l->qtdElem != 0) 
    {
        int i, aux;
        for(i = 0; i < l->qtdElem; i++) aux = l->V[i].chave;
        return (aux);

    } else return (-1);

}

int chaveEnesimoElem(LISTA_SEQ *l, int n)
{
    if(l->qtdElem == 0 || n < 1 || n > l->qtdElem) 
    {
        return (-1); // lista vazia ou elemento inexistente

    } else {

        int i, aux;
        for(i = 0; i < n; i++) aux = l->V[i].chave;

        return (aux);

    }

}

void destruirLista(LISTA_SEQ *l)
{
    l->qtdElem = 0;

}

bool inserirNoFim(LISTA_SEQ *l, int ch)
{
    if(!(l->qtdElem < MAX)) 
    {
        return (false); // lista cheia

    } else {

        l->V[l->qtdElem].chave = ch;
        l->qtdElem++;

        return (true);

    }

}

bool inserirNoIndice(LISTA_SEQ *l, int i, int ch)
{
    if(!(l->qtdElem < MAX) || i < 0 || i > l->qtdElem) 
    {
        return (false); // lista cheia ou indice invalido

    } else if (i < l->qtdElem) {

        int aux;

        for(aux = l->qtdElem; aux > i; aux--)
        {
            l->V[aux].chave = l->V[aux - 1].chave;

        }
    
    }

    l->V[i].chave = ch;
    l->qtdElem++;

    return (true);

}

int indiceAntecessor(LISTA_SEQ *l, int ch)
{
    int i, aux, resp;
    i = 0;
    aux = l->V[0].chave;

    if(aux >= ch) return (-1); // ch nao tem antecessor

    while(aux < ch && i < l->qtdElem)
    {
        aux = l->V[i].chave;
        resp = i;
        i++;

    }

    if(aux > ch) resp--;

    return (resp);

}

bool inserirOrdenado(LISTA_SEQ *l, int ch)
{
    if(!(l->qtdElem < MAX)) 
    {
        return (false); // lista cheia
    
    } else if (l->qtdElem == 0) {

        l->V[0].chave = ch; 
        l->qtdElem++;

        return (true); // primeira insercao (sem ordem para checar)

    } else {

        int indiceAnt = indiceAntecessor(l, ch);

        int i;

        for(i = l->qtdElem; i > indiceAnt + 1; i--)
        {
            l->V[i].chave = l->V[i - 1].chave;
            
        }

        l->V[indiceAnt + 1].chave = ch;
        l->qtdElem++;

        return (true);

    }

}

int buscaSeq(LISTA_SEQ *l, int ch) // retorna o indice em que esta, caso exista
{
    int i;

    for(i = 0; i < l->qtdElem; i++)
    {
        if(l->V[i].chave == ch) return (i);

    }

    return (-1); // chave inexistente

}

int buscaBin(LISTA_SEQ *l, int ch)
{
    int inicio, meio, fim;

    inicio = 0;
    fim = l->qtdElem - 1;

    while(inicio <= fim)
    {
        meio = (inicio + fim) / 2; 

        if(l->V[meio].chave == ch) 
        {
            return (meio);
        
        } else if(l->V[meio].chave > ch) {

            fim = meio - 1;

        } else if (l->V[meio].chave < ch) {

            inicio = meio + 1;

        }       

    }

    return (-1); // chave inexistente

}

void ordenarLista(LISTA_SEQ *l)
{
    int aux, j, i;

    for(i = 0; i < l->qtdElem; i++)
    {
        for(j = i + 1; j < l->qtdElem; j++)
        {
            if(l->V[i].chave > l->V[j].chave)
            {
                aux = l->V[i].chave;
                l->V[i].chave = l->V[j].chave;
                l->V[j].chave = aux;

            }

        }

    }

}

// funcao main

int main()
{

    return (0);

}