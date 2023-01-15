// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    NO* fim;

} FILA_DINAMICA;

// declarando funcoes

void inicializacao(FILA_DINAMICA *f);
void inserir(FILA_DINAMICA *f, int ch);
void exibir(FILA_DINAMICA *f);

int tamanho(FILA_DINAMICA *f);
int retirar(FILA_DINAMICA *f);

// implementando funcoes

void inicializacao(FILA_DINAMICA *f)
{
    f->inicio = NULL;
    f->fim = NULL;

}

void exibir(FILA_DINAMICA *f)
{
    NO* aux = f->inicio;

    while(aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    }

}

int tamanho(FILA_DINAMICA *f)
{
    int tam = 0;
    NO* aux = f->inicio;

    while(aux != NULL)
    {
        aux = aux->prox;
        tam++;

    }

    return (tam);

}

void inserir(FILA_DINAMICA *f, int ch)
{
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if(f->inicio == NULL) f->inicio = novo; // lista vazia
    else f->fim->prox = novo; // lista com elem
    
    f->fim = novo;

}

int retirar(FILA_DINAMICA *f)
{
    if(f->inicio == NULL)
    {
        return (-1); // lista vazia

    } else {

        int resp = f->inicio->chave;

        NO* aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);

        if(f->inicio == NULL) f->fim = NULL; 

        return (resp);
        
    }

}

// funcao main

int main()
{
    
    return 0;

}
