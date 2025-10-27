#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct do territorio

typedef struct
{
    char nome[30], cor[10];
    int tropas;
} Territorio;

Territorio territorios[5]; // vetor com todos os territorios
int numTerritorio = 0;     // contador de territorios

// Limpa buffer de entrada

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo: \n");
    do
    {
        printf("\n--- Cadastrando Territorio %d ---\n", numTerritorio + 1);

        printf("Nome do territorio: ");
        fgets(territorios[numTerritorio].nome, 30, stdin);

        printf("Cor do territorio: ");
        fgets(territorios[numTerritorio].cor, 10, stdin);

        printf("Numero de tropas: ");
        scanf("%d", &territorios[numTerritorio].tropas);

        limparBufferEntrada();

        numTerritorio++;

    } while (numTerritorio < 5);

    printf("\n=== Territorios cadastrados ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n--- Territorio %d ---\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}