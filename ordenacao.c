#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) // função auxiliar para executar a troca.
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1 - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void insertionSort(int vetor[], int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        int chave = vetor[i];
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

void selectionSort(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (vetor[j] < vetor[indiceMenor])
            {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i)
        {
            trocar(&vetor[i], &vetor[indiceMenor]);
        }
    }
}