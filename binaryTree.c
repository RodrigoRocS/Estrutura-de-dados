#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char valor[50];
    No *esquerda;
    No *direita;
} No;

int altura(No *raiz)
{
    if (raiz == NULL)
        return 0;
    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);
    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

int profundidade(No *raiz, No *alvo, int nivel)
{
    if (raiz == NULL)
        return -1;
    if (raiz == alvo)
        return nivel;

    int esq = profundidade(raiz->esquerda, alvo, nivel + 1);
    if (esq != -1)
        return esq;

    return profundidade(raiz->direita, alvo, nivel + 1);
}

void preOrdem(No *raiz) // raiz, esquerda, direita
{
    if (raiz != NULL)
    {
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No *raiz) // esquerda, raiz, direita
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(No *raiz) // esquerda, direita, raiz
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}

No *criarNo(char *valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) // verifica se a alocação deu certo
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void liberar(No *raiz) // libera filho esquerdo , direito , raiz memmoria alocada para arvore
{
    if (raiz != NULL)
    {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
};

No *inserir(No *raiz, const char *valor) // insere os nós da arvore
{
    if (raiz == NULL) // cria primeiro nó
    {
        return criarNo(valor);
    }
    if (strcmp(valor, raiz->valor) < 0) // se o valor for menos vai para esquerda
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else
    { // valor maior vai para a direita
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
};

int main()
{
    No *raiz = criarNo("Hall de Entrada");
    raiz->esquerda = criarNo("Sala de Estar");
    raiz->direita = criarNo("Biblioteca");
    raiz->esquerda->esquerda = criarNo("Quarto");

    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    liberar(raiz);
    return 0;
}