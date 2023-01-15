// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definindo tamanho padrao do vetor

#define MAX 50

// implementando estruturas

typedef struct
{
    int chave;

} REGISTRO;

typedef struct 
{
    REGISTRO V[MAX];
    int inicio;
    int fim;

} FILA_ESTAT;

// declarando funcoes

void inicializacao(FILA_ESTAT *f);
void exibicao(FILA_ESTAT *f);

bool inserir(FILA_ESTAT *f, int ch);

int retirar(FILA_ESTAT *f);
int tamanho(FILA_ESTAT *f);

// implementando funcoes

void inicializacao(FILA_ESTAT *f)
{
    f->inicio = -1;
    f->fim = -1;

}

int tamanho(FILA_ESTAT *f)
{
    if(f->inicio == -1 && f->fim == -1) // lista vazia
    {
        return (0);

    } else { // lista com elem

        int resp, aux;
        resp = 1;
        aux = f->inicio;

        while(aux != f->fim)
        {
            aux = (aux + 1) % MAX;
            resp++;

        }

        return (resp);

    }

}

void exibicao(FILA_ESTAT *f)
{
    int i, tam, aux;
    aux = f->inicio;
    tam = tamanho(f);
    i = 0;

    for(i = 0; i < tam; i++)
    {
        printf("%d ", f->V[aux].chave);
        aux = (aux + 1) % MAX;

    }

}

bool inserir(FILA_ESTAT *f, int ch)
{
    int tam = tamanho(f);

    if(tam == MAX) // lista cheia
    {
        return (false); 

    } else { // lista com espaco

        if(f->inicio == -1) f->inicio = 0;

        f->fim = (f->fim + 1) % MAX;
        f->V[f->fim].chave = ch;

        return (true);

    }    

}

int retirar(FILA_ESTAT *f)
{
    if(f->inicio == -1) // lista vazia
    {
        return (-1); 
     
    } else { // lista com elem

        int resp = f->V[f->inicio].chave;

        if(f->inicio == f->fim) // lista ficou vazia
        {
            f->inicio = -1;
            f->fim = -1;

        } else { // lista nao ficou vazia

            f->inicio = (f->inicio + 1) % MAX;
            
        }

        return (resp);

    }

}

// funcao main

int main()
{

    return 0;

}