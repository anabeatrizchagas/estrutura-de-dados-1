// ==== OBS: ARVORE BINARIA COMUM (NAO POSSUI ORDENACAO COMO SERIA EM UMA ABB) ==== //

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

void inicializacao(NO** raiz);
void imprimirPreOrdem(NO* raiz);
void imprimirPosOrdem(NO* raiz);
void imprimirEmOrdem(NO* raiz);
void retornaPai(NO* raiz, int ch, NO** pai); // para ch garantidamente existente
void qtdNosFolhas(NO* raiz, int* qtd);
void qtdNos(NO* raiz, int* qtd);
void qtdNosComUmFilho(NO* raiz, int* qtd);
void somaChDosNos(NO* raiz, int* soma);
void qtdNosChavesPares(NO* raiz, int* qtd);
void qtdNosMaioresQueCh(NO* raiz, int ch, int* qtd); // com chave maior que ch
void medirAltura(NO* raiz, int* alturaEsq, int* alturaDir, int* alturaFinal);
void buscaChave(NO* raiz, int ch, NO** resp);
void menorNo(NO* raiz, NO** menor); // no com menor chave
void nivelCh(NO* raiz, int ch, NO** donoDeCh, int* nivel);
void imprimirPararentisado(NO* raiz);
void imprimirIdentado(NO* raiz, int n); // n e o nivel

int alturaArvore(NO* raiz);

bool destruirArvore(NO** raiz);
bool arvoreVazia(NO* raiz);
bool inserirNo(NO** raiz, int pos, int ch, NO* pai); // pos == 1 para esq, pos == 2 para dir

// implementando funcoes

void inicializacao(NO** raiz)
{
    *raiz = NULL;

}

void imprimirPreOrdem(NO* raiz) // raiz, esquerda, direita
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->chave);
        if(raiz->esq != NULL) imprimirPreOrdem(raiz->esq);
        if(raiz->dir != NULL) imprimirPreOrdem(raiz->dir);

    }
    
}

void imprimirPosOrdem(NO* raiz) // esquerda, direita, raiz
{
    if(raiz != NULL)
    {
        if(raiz->esq != NULL) imprimirPosOrdem(raiz->esq);
        if(raiz->dir != NULL) imprimirPosOrdem(raiz->dir);
        printf("%d ", raiz->chave);

    }

}

void imprimirEmOrdem(NO* raiz) // esquerda, raiz, direita
{
    if(raiz != NULL)
    {
        if(raiz->esq != NULL) imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        if(raiz->dir != NULL) imprimirEmOrdem(raiz->dir);

    }

}

bool inserirNo(NO** raiz, int pos, int ch, NO* pai) 
{
    NO* novo;

    if(pai != NULL) 
    {
        if(((pos==1) && (pai->esq != NULL)) || ((pos == 2) && (pai->dir != NULL))) return(false);

    }

    novo = (NO *) malloc(sizeof(NO)); 
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if(pai == NULL)
    {
        *raiz = novo;
    
    } else {

        if(pos==1) pai->esq = novo; // esquerda
        else pai->dir = novo; // direita
    }

}


void retornaPai(NO* raiz, int ch, NO** pai) 
{
    if(raiz != NULL && raiz->chave == ch) return;

    *pai = NULL;

    if(raiz != NULL)
    {
        if(raiz->esq != NULL && *pai == NULL) 
        {
            *pai = raiz;
            retornaPai(raiz->esq, ch, pai);
        
        } 
        
        if(raiz->dir != NULL && *pai == NULL) 
        {  
            *pai = raiz;
            retornaPai(raiz->dir, ch, pai);
        
        }

    }

}

void buscaChave(NO* raiz, int ch, NO** resp)
{
    if(raiz != NULL)
    {
        if(raiz->chave == ch) *resp = raiz;
        if(raiz->esq != NULL && *resp == NULL) buscaChave(raiz->esq, ch, resp);
        if(raiz->dir != NULL && *resp == NULL) buscaChave(raiz->dir, ch, resp);

    }

}

void menorNo(NO* raiz, NO** menor) // no com menor chave
{
    if(raiz != NULL)
    {

        if(raiz->esq != NULL) menorNo(raiz->esq, menor);
        if(raiz->dir != NULL) menorNo(raiz->dir, menor);
        if(raiz->chave < (*menor)->chave) *menor = raiz;

    }

}

bool destruirArvore(NO** raiz)
{   
    if(*raiz != NULL)
    {
        if(&(*raiz)->esq != NULL) destruirArvore(&((*raiz)->esq));
        if(&(*raiz)->dir != NULL) destruirArvore(&((*raiz)->dir));
        free(*raiz);

        return (true);

    } else return (false);

}

bool arvoreVazia(NO* raiz)
{
    if(raiz == NULL) return (true);
    else return (false);

}

void qtdNosFolhas(NO* raiz, int* qtd)
{
    if(raiz != NULL)
    {
        if(raiz->esq == NULL && raiz->dir == NULL) *qtd = *qtd + 1;
        if(raiz->esq != NULL) qtdNosFolhas(raiz->esq, qtd);
        if(raiz->dir != NULL) qtdNosFolhas(raiz->dir, qtd);

    }

}

void medirAltura(NO* raiz, int* alturaEsq, int* alturaDir, int* alturaFinal)
{
    if(raiz != NULL)
    {

        if(raiz->esq != NULL)
        {
            *alturaEsq = *alturaEsq + 1;
            medirAltura(raiz->esq, alturaEsq, alturaDir, alturaFinal);

        }

        if(raiz->dir != NULL)
        {
            *alturaDir = *alturaDir + 1;
            medirAltura(raiz->dir, alturaEsq, alturaDir, alturaFinal);
        
        }

        if(*alturaEsq >= *alturaDir) *alturaFinal = *alturaEsq;
        else *alturaFinal = *alturaDir;

    }

}

int alturaArvore(NO* raiz)
{
    if(raiz != NULL && raiz->esq == NULL && raiz->dir == NULL) 
    {
        return 1;
    
    } else {

        int hEsq, hDir, hFinal;
        hEsq = 0;
        hDir = 0;
        hFinal = 0;

        medirAltura(raiz, &hEsq, &hDir, &hFinal);
        return (hFinal);

    }
    
}

void qtdNos(NO* raiz, int* qtd)
{
    if(raiz != NULL)
    {
        *qtd = *qtd + 1;
        if(raiz->esq != NULL) qtdNos(raiz->esq, qtd);
        if(raiz->dir != NULL) qtdNos(raiz->dir, qtd);

    }

}

void qtdNosComUmFilho(NO* raiz, int* qtd)
{
    if(raiz != NULL)
    {
        if((raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL)) *qtd = *qtd + 1;
        
        if(raiz->esq != NULL) qtdNosComUmFilho(raiz->esq, qtd);
        if(raiz->dir != NULL) qtdNosComUmFilho(raiz->dir, qtd);

    }

}

void somaChDosNos(NO* raiz, int* soma)
{
    if(raiz != NULL)
    {
        if(raiz->esq != NULL) somaChDosNos(raiz->esq, soma);
        if(raiz->dir != NULL) somaChDosNos(raiz->dir, soma);
        *soma = *soma + raiz->chave;

    }

}

void qtdNosChavesPares(NO* raiz, int* qtd)
{
    if(raiz != NULL)
    {
        if(raiz->chave % 2 == 0) *qtd = *qtd + 1;
        if(raiz->esq != NULL) qtdNosChavesPares(raiz->esq, qtd);
        if(raiz->dir != NULL) qtdNosChavesPares(raiz->dir, qtd);

    }

}

void qtdNosMaioresQueCh(NO* raiz, int ch, int* qtd) // com chave maior que ch
{
    if(raiz != NULL)
    {
        if(raiz->chave > ch) *qtd = *qtd + 1;
        if(raiz->esq != NULL) qtdNosMaioresQueCh(raiz->esq, ch, qtd);
        if(raiz->dir != NULL) qtdNosMaioresQueCh(raiz->dir, ch, qtd);

    }
    
}

void nivelCh(NO* raiz, int ch, NO** donoDeCh, int* nivel)
{
    if(raiz != NULL)
    {
        *nivel  = *nivel + 1;

        if(raiz->chave == ch)
        {
            *donoDeCh = raiz;

        } else {

            if(raiz->esq != NULL && *donoDeCh == NULL) nivelCh(raiz->esq, ch, donoDeCh, nivel);
            if(raiz->dir != NULL && *donoDeCh == NULL) nivelCh(raiz->dir, ch, donoDeCh, nivel);
            if(*donoDeCh == NULL) *nivel = *nivel - 1;

        }

    }

}

void imprimirPararentisado(NO* raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->chave);
        if(raiz->esq != NULL || raiz->dir != NULL) 
        { 
            printf("(");
            if(raiz->esq != NULL) imprimirPararentisado(raiz->esq);
            printf(",");
            if(raiz->dir != NULL) imprimirPararentisado(raiz->dir);
            printf(")");

        }

    }

}

void imprimirIdentado(NO* raiz, int n) { // n e o numero de niveis

	if(raiz != NULL)
    {
		if(raiz->dir) imprimirIdentado(raiz->dir, n+1);
		int i;
		for(i= 0; i < n; i++) printf ("         "); // espaco
		printf("%d \n", raiz->chave);
		if(raiz->esq) imprimirIdentado(raiz->esq, n+1);

	}

} 

// funcao main

int main()
{

    return 0;

}
