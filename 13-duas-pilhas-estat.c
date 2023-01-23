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
    int topo1;
    int topo2;

} DUAS_PILHAS_EST;

// declarando funcoes

void inicializacao(DUAS_PILHAS_EST *p);
void exibicaoPilhaK(DUAS_PILHAS_EST *p, int k);

int tamanhoPilhaK(DUAS_PILHAS_EST *p, int k);
int popPilhaK(DUAS_PILHAS_EST *p, int k);

bool vetorEstaCheio(DUAS_PILHAS_EST *p);
bool pushPilhaK(DUAS_PILHAS_EST *p, int k, int ch);

// implementando funcoes

void inicializacao(DUAS_PILHAS_EST *p)
{
    p->topo1 = -1;
    p->topo2 = MAX;

}

void exibicaoPilhaK(DUAS_PILHAS_EST *p, int k)
{
    if(k == 1)
    {
        int i;
        for(i = p->topo1; i >= 0; i--) printf("%d ", p->V[i].chave);

    } else if (k == 2) {

        int j;
        for(j = p->topo2; j < MAX; j++) printf("%d ", p->V[j].chave);

    }

}

int tamanhoPilhaK(DUAS_PILHAS_EST *p, int k)
{
    if(k == 1)
    {
        return (p->topo1 + 1);

    } else if (k == 2) {

        return (MAX - p->topo2);
    }

}

int popPilhaK(DUAS_PILHAS_EST *p, int k)
{
    int resp = -1; // se a pilha estiver vazia 

    if(k == 1 && p->topo1 != -1)
    {
        resp = p->V[p->topo1].chave; //  se for a pilha 1 com elemente
        p->topo1--;      

    } else if (k == 2 && p->topo2 < MAX) {

        resp = p->V[p->topo2].chave; // se for a pilha 2 com elementos
        p->topo2++;
        
    }

    return(resp);

}

bool vetorEstaCheio(DUAS_PILHAS_EST *p)
{
    if(p->topo2 - p->topo1 == 1) return (true);
    else return (false);

}

bool pushPilhaK(DUAS_PILHAS_EST *p, int k, int ch)
{
    if(vetorEstaCheio(p) == true) 
    {
        return (false);

    } else {

        if(k == 1)
        {
            p->topo1++;
            p->V[p->topo1].chave = ch;

        } else if (k == 2) {
            
            p->topo2--;
            p->V[p->topo2].chave = ch;

        }

        return (true);

    }

}

// funcao main

int main()
{

    return 0;
}