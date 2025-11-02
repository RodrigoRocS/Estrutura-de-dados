#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30], tipo[20];
    int quantidade;
} Item;

struct No
{
    Item item;
    struct No *proximo;
};

//--- Protótipo das funções ---
void cadastroItem(Item *it, struct No **mochila);
void limpaBuffer();
void listarItens(struct No *inicio);
void buscarItem(struct No *inicio, char *nome);
void removerPorNome(struct No **inicio, char *nome);

main()
{
    char nomeBusca[30];

    return 0;
}

void limpaBuffer() // Limpa buffer de entrada
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void cadastroItem(Item *it, struct No **mochila)
{ // Cadastra os itens
    int numItens = 0;

    struct No *novo = (struct No *)malloc(sizeof(struct No));

    printf("Vamos cadastrar os 10 itens: \n");

    do
    {
        printf("\n=== Cadastrando Item %d ===\n", numItens + 1);
        printf("Nome do Item: ");
        fgets(it[numItens].nome, 30, stdin);
        it[numItens].nome[strcspn(it[numItens].nome, "\n")] = 0;

        printf("Tipo do Item: ");
        fgets(it[numItens].tipo, 30, stdin);
        it[numItens].tipo[strcspn(it[numItens].tipo, "\n")] = 0;

        printf("Quantidade: ");
        scanf("%d", &it[numItens].quantidade);
        limpaBuffer();
        // Insere no início da lista
        novo->item = it[numItens];
        novo->proximo = *mochila;
        *mochila = novo;
        numItens++;

    } while (numItens < 10);
};

void listarItens(struct No *inicio) // lista todos os itens cadastrados
{
    if (inicio == NULL)
    {
        printf("Nenhum item cadastrado!\n");
        return;
    }

    int i = 1;
    printf("Itens Atualizados :\n");
    struct No *atual = inicio;
    while (atual != NULL)
    {
        printf("%d - %s (Tipo: %s, Quantidade: %d)\n", i, atual->item.nome, atual->item.tipo, atual->item.quantidade);
        atual = atual->proximo;
        i++;
    };
};

void buscaItem(struct No *inicio, char *nome) // busca item por nome
{
    if (inicio == NULL)
    {
        printf("Nenhum item cadastrado!\n");
        return;
    }

    printf("\n=== RESULTADO DA BUSCA ===\n");
    int i = 0;
    struct No *atual = inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->item.nome, nome) == 0)
        {
            return printf("%s (Tipo: %s, Quantidade: %d)\n", atual->item.nome, atual->item.tipo, atual->item.quantidade);
            i = 1;
        }
        atual = atual->proximo;
        if (!i)
        {
            printf("Item '%s' não encontrado!\n", nome);
        }
    }
};

void removerPorNome(struct No **inicio, char *nome) // remove item por nome
{
    if (*inicio == NULL)
    {
        printf("Lista vazia! Nenhum item para remover.\n");
        return;
    }

    struct No *atual = *inicio;
    struct No *anterior = NULL;

    // Percorre a lista procurando pelo nome
    while (atual != NULL)
    {
        if (strcmp(atual->item.nome, nome) == 0)
        {
            // Item encontrado!
            if (anterior == NULL)
            {
                // Remove do início
                *inicio = atual->proximo;
            }
            else
            {
                // Remove do meio/fim
                anterior->proximo = atual->proximo;
            }

            printf("Item '%s' removido com sucesso!\n", nome);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item '%s' não encontrado!\n", nome);
}
