// importando pacotes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

// criando estruturas

typedef struct str
{
    int chave;
    struct str* esq;
    struct str* dir;

} NO;

// declarando funcoes

void inicialização(NO** raiz);
void listaOrdComElemsDaArvore(NO* raiz, NO** lista);
void destruirArvore(NO** raiz);
void paiDaChave(NO* raiz, int ch, NO** pai);
void menorElem(NO* raiz, NO** menor);
void maiorElem(NO* raiz, NO** maior);
void qtdMaioresqueX(NO* raiz, int x, int* qtdMaiores);
void qtdMenoresqueX(NO* raiz, int x, int* qtdMenores);
void insercao(NO** raiz, int ch);
void exclusao(NO** raiz, NO* p);

NO* procuraChave(NO* raiz, int chave, NO** resp);
bool arvoreVazia(NO* raiz);

// implementando funcoes

void inicialização(NO** raiz)
{
    *raiz = NULL;
}

void listaOrdComElemsDaArvore(NO* raiz, NO** lista)
{
    if(raiz != NULL)
    {
        if(raiz->esq != NULL) listaOrdComElemsDaArvore(raiz, lista);

        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = raiz->chave;
        novo->dir = NULL;

        if(*lista == NULL) 
        {
            *lista = novo;

        } else {

            NO* aux = *lista;
            while(aux->dir != NULL) aux = aux->dir;
            aux->dir = novo;

        }

        if(raiz->dir != NULL) listaOrdComElemsDaArvore(raiz->dir, lista);

    }

}

void destruirArvore(NO** raiz)
{
    NO* aux = *raiz;

    if(aux != NULL)
    {
        if(aux->esq != NULL) destruirArvore(aux->esq);
        if(aux->dir != NULL) destruirArvore(aux->dir);
        free(aux);
        *raiz = NULL;

    }

}

void paiDaChave(NO* raiz, int ch, NO** pai)
{
    if(raiz != NULL)
    {
        if(raiz->chave == ch) return;
        else {

            *pai = raiz;
            if(ch < raiz->chave) paiDaChave(raiz->esq, ch, pai);
            else if(ch > raiz->chave) paiDaChave(raiz->dir, ch, pai);

        }

    }

}

void menorElem(NO* raiz, NO** menor)
{
    if(raiz != NULL)
    {
        if(raiz->esq != NULL) menorElem(raiz, menor);
        else *menor = raiz;

    }

}

void maiorElem(NO* raiz, NO** maior)
{
    if(raiz != NULL)
    {
        if(raiz->dir != NULL) maiorElem(raiz, maior);
        else *maior = raiz;

    }

}

void qtdMaioresqueX(NO* raiz, int x, int* qtdMaiores)
{
    if(raiz != NULL)
    {
        if(x < raiz->chave) 
        {
            *qtdMaiores++;
            contarNos(raiz->dir, qtdMaiores);
            qtdMaioresqueX(raiz->esq, x, qtdMaiores);

        } else if(x == raiz->chave) {

            contarNos(raiz->dir, qtdMaiores);

        } else if(x > raiz->chave) qtdMaioresqueX(raiz->dir, x, qtdMaiores);

    }

}

void contarNos(NO* raiz, int* qtd)
{
    if(raiz != NULL)
    {
        if(raiz->esq != NULL) contarNos(raiz->esq, qtd);
        if(raiz->dir != NULL) contarNos(raiz->dir, qtd);
        *qtd++;

    }

}

void qtdMenoresqueX(NO* raiz, int x, int* qtdMenores)
{
    if(raiz != NULL)
    {
        if(x < raiz->chave)
        {
            qtdMenoresqueX(raiz->esq, x, qtdMenores);

        } else if(x == raiz->chave) {

            contarNos(raiz->esq, qtdMenores);

        } else if(x > raiz->chave) {

            *qtdMenores++;
            contarNos(raiz->esq, qtdMenores);
            qtdMenoresqueX(raiz->dir, x, qtdMenores);

        }

    }

}

void insercao(NO** raiz, int ch) // DAR UMA OLHADA
{
    
    if(*raiz != NULL)
    {
        NO* aux = *raiz;
        if(ch < aux->chave) insercao(aux->esq, ch);
        else if(ch > aux->chave) insercao(aux->dir, ch);

    }

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    *raiz = novo;

}

void exclusao(NO** raiz, NO* p)
{
    if(*raiz != NULL && p != NULL) // dar uma olhada nessa condicao
    {
        NO* existe = NULL;
        procuraChave(raiz, p->chave, &existe);
        if(existe == NULL) return; // chave nao existe nessa arvore

        NO* pai = NULL;
        paiDaChave(raiz, p->chave, &pai);

        if(p->esq == NULL && p->dir == NULL) // no folha
        {         
            if(pai->esq == p) pai->esq = NULL;
            else pai->dir = NULL;
            free(p);

        } else if((p->esq == NULL && p->dir != NULL) || (p->esq != NULL && p->dir == NULL)) { // no com um filho 

            pai->chave = p->chave;
            if(pai->esq == p) pai->esq = NULL;
            else pai->dir = NULL;
            free(p);
            
        } else { // no com dois filhos

            NO* aux, *herdeiro;

            if(p->esq != NULL)
            {
                maiorElem(p->esq, &herdeiro);              
                aux = herdeiro;
                herdeiro = p;
                p = aux;
                exclusao(raiz, p);

            } else if(p->dir != NULL) {

                menorElem(p->dir, &herdeiro);
                aux = herdeiro;
                herdeiro = p;
                p = aux;
                exclusao(raiz, p);
               
            }

        }

    }

}

NO* procuraChave(NO* raiz, int ch, NO** resp)
{
    if(raiz != NULL)
    {
        if(raiz->chave == ch) *resp = raiz;
        if(raiz->esq != NULL && ch < raiz->chave && *resp == NULL) procuraChave(raiz->esq, ch, resp);
        if(raiz->dir != NULL && ch > raiz->chave && *resp == NULL) procuraChave(raiz->dir, ch, resp);
        
    }

}

bool arvoreVazia(NO* raiz)
{
    if(raiz == NULL) return (true);
    else return (false);

}

// funcao main

int main()
{

    return 0;
    
}