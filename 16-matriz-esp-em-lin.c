// importando pacotes

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

// criando estruturas

typedef struct str
{
    int lin, col, chave;
    struct str* prox;
    
} NO;

typedef struct
{
    NO* inicio;
    int maxlin, maxcol;

} MATRIZ;

// declarando funcoes

void inicializacao(MATRIZ* m);
void exibirLinha(MATRIZ* m, int lin); // exibe validos dessa linha
void exibirColuna(MATRIZ* m, int col); // exibe validos dessa coluna
void exibirTodos(MATRIZ* m); // exibe validos da matriz
void zerarDiagonal(MATRIZ* m);
void atribuir(MATRIZ* m, int lin, int col, int ch);

int somaChsDaColuna(MATRIZ* m, int col);
int somaChsDaLinha(MATRIZ* m, int lin);
int qtdElem(MATRIZ* m);

NO* busca(MATRIZ* m, int lin, int col, NO** ant);

// implementando funcoes

void inicializacao(MATRIZ* m)
{
    m->inicio = NULL;
    m->maxcol = 20;
    m->maxlin = 20;

}

void exibirLinha(MATRIZ* m, int lin)
{
    NO* aux = m->inicio;

    while(aux != NULL && aux->lin <= lin)
    {
        if(aux->lin == lin) printf("(lin: %d, col: %d, ch: %d) \n", aux->lin, aux->col, aux->chave);
        aux = aux->prox;

    }

    printf("\n");

}

void exibirColuna(MATRIZ* m, int col)
{
    NO* aux = m->inicio;

    while(aux != NULL)
    {
        if(aux->col == col) printf("(lin: %d, col: %d, ch: %d) \n", aux->lin, aux->col, aux->chave);
        aux = aux->prox;

    }

    printf("\n");

}

void exibirTodos(MATRIZ* m)
{
    NO* aux = m->inicio;

    while(aux != NULL)
    {
        printf("(lin: %d, col: %d, ch: %d) \n", aux->lin, aux->col, aux->chave);
        aux = aux->prox;

    }

    printf("\n");

}

void zerarDiagonal(MATRIZ* m)
{
    NO* aux = m->inicio;
    NO* ant = NULL;

    while(aux != NULL)
    {
        if(aux->col == aux->lin)
        {
            NO* apaga = aux;

            if(ant == NULL) m->inicio = aux->prox;
            else ant->prox = aux->prox;

            free(apaga);

            ant = aux;
            aux = aux->prox;


        } else {

            ant = aux;
            aux = aux->prox;

        }

    }

}

int somaChsDaColuna(MATRIZ* m, int col)
{
    int soma = 0;
     NO* aux = m->inicio;

     while(aux != NULL)
     {
        if(aux->col == col) soma = soma + aux->chave;
        aux = aux->prox;
    
    }

    return (soma);

}

int somaChsDaLinha(MATRIZ* m, int lin)
{
    int soma = 0;
    NO* aux = m->inicio;

    while(aux != NULL && aux->lin <= lin)
    {
        if(aux->lin == lin) soma = soma + aux->chave;
        aux = aux->prox;

    }

    return (soma);

}

int qtdElem(MATRIZ* m)
{
    int tam = 0;
    NO* aux = m->inicio;

    while(aux != NULL)
    {
        aux= aux->prox;
        tam++;

    }

    return (tam);

}

NO* busca(MATRIZ* m, int lin, int col, NO** ant)
{
    *ant = NULL;
    NO* aux = m->inicio;

    while(aux != NULL && aux->lin <= lin)
    {
        if(aux->lin >= lin && aux->col == col) break;

        *ant = aux;
        aux = aux->prox;

    }

    if(aux != NULL && aux->lin == lin && aux->col == col) return (aux);
    else return (NULL);

}

void atribuir(MATRIZ* m, int lin, int col, int ch)
{
    NO* ant;
    NO* existe = busca(m, lin, col, &ant);

    if(existe != NULL && ch != 0) // elem valido, chave valido
    {
        existe->chave = ch;

    } else if(existe != NULL && ch == 0) // elem valido, chave invalida
    {
        if(ant == NULL) m->inicio = existe->prox;
        else ant->prox = existe->prox;

        free(existe);

    } else if(existe == NULL && ch != 0) // elem invalido, chave valida
    {
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = ch;
        novo->lin = lin;
        novo->col = col;

        if(m->inicio == NULL)
        {
            novo->prox = NULL;
            m->inicio = novo;

        } else {

            if(ant == NULL) 
            {
                novo->prox = m->inicio;
                m->inicio = novo;

            } else {

                novo->prox = ant->prox;
                ant->prox = novo;

            } 
            
        }
        

    } else if(existe == NULL && ch == 0) // elem invalido, chave invalida
    {
        return;

    }

}

// funcao main

int main()
{

    return 0;

}