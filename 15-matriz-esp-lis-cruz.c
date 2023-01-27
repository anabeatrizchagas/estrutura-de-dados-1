// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

// definindo maximo de linhas e colunas na matriz

#define MAX 10

// criando estrutura

typedef struct str
{
    int chave; // informacao guardada
    int lin; // linha que esse no esta na matriz
    int col; // coluna que esse no esta na matriz
    struct str* proxLin; // elemento da proxima linha (o que esta abaixo)
    struct str* proxCol; // elemento da proxima coluna (o que esta a direita)

} NO;

typedef struct
{
    NO* vLin[MAX + 1]; // para indexar ate MAX, iniciando na linha 1
    NO* vCol[MAX + 1]; // para indexar ate MAX, iniciando na coluna 1

} MATRIZ;

// declarando funcoes

void inicializacao(MATRIZ *m);
void imprimirValidos(MATRIZ *m);
void destruirMatriz(MATRIZ *m);
void anexar(MATRIZ* m, int iLin, int iCol, int ch); // nao permite anexar de chave invalida (ch == 0)

int somaDosElemsDeLin(MATRIZ *m, int lin);
int somaDosElemsDeCol(MATRIZ *m, int col);
int qtdElemValidos(MATRIZ *m);

// implementando funcoes

void inicializacao(MATRIZ *m)
{
    // inicializando as listas de linhas e colunas

    int i;
    for(i = 1; i <= MAX; i++)
    {
        m->vLin[i] = NULL;
        m->vCol[i] = NULL;
    }

}

void imprimirValidos(MATRIZ *m)
{
    int i;
    for(i = 1; i <= MAX; i++)
    {
        printf("linha %d:", i);

        if(m->vLin[i] != NULL) 
        {
            NO* aux = m->vLin[i];
            while(aux != NULL)
            {
                printf("(ch: %d, col: %d) ", aux->chave, aux->col);
                aux = aux->proxCol;
            }

        }

        printf("\n");

    }

}

void destruirMatriz(MATRIZ *m)
{
    // "zerando" todas as listas de linhas e colunas

    int i;
    for(i = 1; i <= MAX; i++) 
    {
        m->vCol[i] = NULL;
        m->vLin[i] = NULL;
    }

}

int somaDosElemsDeLin(MATRIZ *m, int lin)
{
    int soma = 0;
    NO* aux = m->vLin[lin];

    while(aux != NULL) 
    {
        soma = soma + aux->chave;
        aux = aux->proxCol;
    }

    return (soma);

}

int somaDosElemsDeCol(MATRIZ *m, int col)
{
    int soma = 0;
    NO* aux = m->vCol[col];

    while(aux != NULL)
    {
        soma = soma + aux->chave;
        aux = aux->proxLin;
    }

    return (soma);

}

int qtdElemValidos(MATRIZ *m)
{
    int i, qtd;
    qtd = 0;

    for(i = 1; i <= MAX; i++)
    {
        NO* aux = m->vLin[i];

        while(aux != NULL)
        {
            qtd++;
            aux = aux->proxCol;
        }

    }

    return (qtd);

}

bool excluirElemP(NO** lin, NO** col, NO* esq, NO* aci, NO* p)
{

}

NO* busca(MATRIZ* m, int iLin, int iCol)
{
    if(iLin < 1 || iCol < 1 || iLin > MAX || iCol > MAX) return (NULL); // indices invalidos
    NO* aux;

    aux = m->vLin[iLin];

    while(aux != NULL) 
    {
        if(aux->col == iCol) return (aux);
        aux = aux->proxCol;

    }

    return (NULL);

}

void anexar(MATRIZ* m, int iLin, int iCol, int ch)
{
    if(iLin < 1 || iCol < 1 || iLin > MAX || iCol > MAX || ch == 0) return; // elems invalidos
    
    NO* existe = busca(m, iLin, iCol);
    if(existe != NULL)
    {
        existe->chave = ch;
        return;
        
    }

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch,
    novo->col = iCol;
    novo->lin = iLin;
    novo->proxLin = NULL;
    novo->proxCol = NULL;

    NO* aux;

    // arrumando a lista de linhas

    if(m->vLin[iLin] == NULL)
    {
        m->vLin[iLin] = novo;

    } else {
        
        aux = m->vLin[iLin];
        while(aux->proxCol != NULL) aux = aux->proxCol;
        aux->proxCol = novo;

    }

    // arrumando a lista de colunas

    if(m->vCol[iCol] == NULL)
    { 
        m->vCol[iCol] = novo;

    } else {
        
        aux = m->vCol[iCol];
        while(aux->proxLin != NULL) aux = aux->proxLin;
        aux->proxLin = novo;

    }
    
}

// funcao main

int main()
{

    return 0;
}