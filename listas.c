#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado;
    struct No *proximo;
};

void inserirNoInicio(struct No **inicio, int valor)
{
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->dado = valor;
    novo->proximo = *inicio;
    *inicio = novo;
};

void removerDoInicio(struct No **inicio)
{
    if (*inicio != NULL)
    {
        struct No *temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
    };
};

void listar(struct No *inicio)
{
    struct No *atual = inicio;
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    };
};

int buscaLinear(int lista[], int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (lista[i] == valor)
        {
            return i; // Retorna o índice onde encontrou o valor
        }
    }
    return -1; // Retorna -1 se não encontrou
}

int buscaLinearLista(struct No *inicio, int valor)
{
    int pos = 0;
    struct No *atual = inicio;
    while (atual != NULL)
    {
        if (atual->dado == valor)
        {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1;
}

int main()
{
    struct No *primeiro = (struct No *)malloc(sizeof(struct No));
    struct No *segundo = (struct No *)malloc(sizeof(struct No));
    struct No *terceiro = (struct No *)malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado = 30;
    terceiro->proximo = NULL;

    // Percorrendo a lista
    struct No *atual = primeiro;
    while (atual != NULL)
    {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    };

    return 0;
}