// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definindo tamanho padrao do vetor

#define MAX 50

// criando estruturas

typedef struct
{
    int chave;

} REGISTRO;

typedef struct
{
    REGISTRO V[MAX];
    int topo;

} PILHA_ESTAT;

// declarando funcoes

void inicializacao(PILHA_ESTAT *p);
void exibicao(PILHA_ESTAT *p); // imprimindo do ultimo ao primeiro inserido

int tamanho(PILHA_ESTAT *p);
int pop(PILHA_ESTAT *p); // saida de dados

bool estaCheia(PILHA_ESTAT *p);
bool push(PILHA_ESTAT *p, int ch); // entrada de dados

// implementando funcoes

void inicializacao(PILHA_ESTAT *p)
{
    p->topo = -1;

}

void exibicao(PILHA_ESTAT *p)
{
    int i;

    for(i = p->topo; i > -1; i--) printf("%d ", p->V[i].chave);

}

bool push(PILHA_ESTAT *p, int ch) 
{
    if(estaCheia(p) == true) // pilha cheia
    {
        return (false);
    
    } else { // pilha com espaco

        p->V[p->topo + 1].chave = ch;
        p->topo++;
        
        return (true);

    }

}

int tamanho(PILHA_ESTAT *p)
{
    int tam, i;
    tam = 0;
    
    for(i = 0; i <= p->topo; i++) tam = i + 1;

    return (tam);

}

int pop(PILHA_ESTAT *p)
{
    if(p->topo == -1) // pilha vazia
    {
        return (-1);

    } else { // pilha com elem

        int resp = p->V[p->topo].chave;
        p->topo--;

        return (resp);

    }

}

bool estaCheia(PILHA_ESTAT *p)
{
    if(p->topo >= MAX - 1) return (true);
    else return (false);

}

// funcao main

int main()
{

    return 0;
}