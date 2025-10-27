#include <stdio.h>
#include <stdlib.h>
#include <string.h> // para strcspn()

// Constates globais
#define MAX_LIVROS 50
#define TAM_STRING 100

// Definição da estrutura (struct)

typedef struct
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
} Livro;

// Limpa buffer de entrada

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função principal

int main()
{
    Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // Menu da biblioteca

    do
    {
        // exibe menu ao usuario
        printf("************************************");
        printf("     BIBLIOTECA - PARTE 1\n");
        printf("************************************");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao: ");

        // Lê a opção escolhida
        scanf("%d", &opcao);
        limparBufferEntrada();

        // processamento das opções:
        switch (opcao)
        {
        case 1: // cadastro novo livro
            printf("*** Cadastro de Novo Livro ***\n\n");

            if (totalLivros < MAX_LIVROS)
            {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")];
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")];
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")];

                printf("Digite a edicao: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada();

                totalLivros++;

                printf("\n Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Biblioteca cheia! Nao e possivel cadastrar mais livros!\n");
            }

            break;

        default:
            break;
        }
    }
}
