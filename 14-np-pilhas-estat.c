// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definindo tamanho do vetor e qtd de pilhas

#define MAX 50
#define NP 5

// criando estruturas

typedef struct
{
    int chave;

} REGISTRO;

typedef struct
{
    REGISTRO V[MAX];
    int base[NP + 1];
    int topo[NP + 1];

} NP_PILHAS;

// declarando funcoes

void inicializacao(NP_PILHAS *p); 
void exibicaoDaPilhaK(NP_PILHAS *p, int k); 

int tamDaPilhaK(NP_PILHAS *p, int k);
int popPilhaK(NP_PILHAS *p, int k); 

bool pilhaKestaCheia(NP_PILHAS *p, int k);
bool deslocaPilhaKparaDir(NP_PILHAS *p, int k); 
bool deslocaPilhaKparaEsq(NP_PILHAS *p, int k);
bool pushPilhaK(NP_PILHAS *p, int k, int ch); 

// implementando funcoes

void inicializacao(NP_PILHAS *p)
{
    int i;
    for(i = 0; i <= NP; i++)
    {
        p->base[i] = ((MAX / NP) * i) - 1;
        p->topo[i] = p->base[i];

    }


}

void exibicaoDaPilhaK(NP_PILHAS *p, int k)
{
    int i;
    for(i = p->base[k] + 1; i <= p->topo[k]; i++) printf("%d ", p->V[i].chave);
    printf("\n");

}

int tamDaPilhaK(NP_PILHAS *p, int k)
{
    return (p->topo[k] - p->base[k]);

}

int popPilhaK(NP_PILHAS *p, int k)
{
    if(k < 0 || k >= NP || p->topo[k] == p->base[k]) return (-1); // lista vazia ou indice invalido

    int resp = p->V[p->topo[k]].chave;
    p->topo[k]--;

    return (resp);

}

bool pilhaKestaCheia(NP_PILHAS *p, int k)
{
    if(p->topo[k] == p->base[k + 1]) return (true);
    else return (false);

}

bool deslocaPilhaKparaDir(NP_PILHAS *p, int k)
{
    if(k < 1 || k >= NP || pilhaKestaCheia(p, k) == true) return (false); // sem espaco ou indice invalido

    int i;
    for(i = p->topo[k] + 1; i > p->base[k]; i--) p->V[i].chave = p->V[i - 1].chave;

    p->topo[k]++;
    p->base[k]++;

    return (true);

}

bool deslocaPilhaKparaEsq(NP_PILHAS *p, int k)
{
    if(k < 1 || k >= NP || pilhaKestaCheia(&p, k - 1) == true) return (false); // sem espaco ou indice invalido

    int i;
    for(i = p->base[k]; i >= p->topo[k] ; i++) p->V[i].chave = p->V[i + 1].chave;

    p->topo[k]--;
    p->base[k]--;

    return (true);

}

bool pushPilhaK(NP_PILHAS *p, int k, int ch)
{
    int i;

    if(pilhaKestaCheia(p, k) == true && k < NP - 1)
    {
        for(i = NP - 1; i > k; i--) deslocaPilhaKparaDir(p, i);

    } else if(pilhaKestaCheia(p, k) == true && k > 0)
    {
        for(i = 1; i < k + 1; i++) deslocaPilhaKparaEsq(p, i);

    }

    if(pilhaKestaCheia(p, k) == false)
    {
        p->topo[k]++;
        p->V[p->topo[k]].chave = ch;

        return (true);

    } else return (false);

}

// funcao main

int main()
{

    return 0;
}