#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    char nome[30];
    int idade;
} Pessoa;

typedef struct
{
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaCheia(Fila *f)
{
    return f->total == MAX;
}

int filaVazia(Fila *f)
{
    return f->total == 0;
}

void inserir(Fila *f, Pessoa p)
{ // enqueue
    if (filaCheia(f))
    {
        printf("Fila cheia. Não é possivel inserir.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

void remover(Fila *f, Pessoa *p)
{
    if (filaVazia(f))
    {
        printf("Fila vazia. Não é possivel remover.\n");
        return;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

void mostrarFila(Fila *f)
{
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; // dupla variavel i e idx
         i < f->total;               // enquanto i for menor que o tamanho total da fila
         i++, idx = (idx + 1) % MAX) // incrementa i e idx recebe a logica circular
    {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].idade);
    }
    printf("\n");
}