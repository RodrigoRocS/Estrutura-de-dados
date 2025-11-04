#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 5

typedef struct
{
    char nome[30];
    int id;
} Peca;

typedef struct
{
    Peca pecas[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

int id = 0;

// --- Protótipos ---

void inicializarFila(Fila *f);
void inserir(Fila *f, Peca p);
void remover(Fila *f, Peca *p);
void mostrarFila(Fila *f);
Peca gerarPeca(int *id);
int gera();
int filaCheia(Fila *f);
int filaVazia(Fila *f);
void limpaBuffer();
void exibeMenu(Fila *f);

int main()
{
    Fila f;

    // inicializa e insere 5 peças na fila
    inicializarFila(&f);
    inserir(&f, gerarPeca(&id));
    inserir(&f, gerarPeca(&id));
    inserir(&f, gerarPeca(&id));
    inserir(&f, gerarPeca(&id));
    inserir(&f, gerarPeca(&id));
    exibeMenu(&f);

    return 0;
}

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

void mostrarFila(Fila *f) // exibe fila de peças
{
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; // dupla variavel i e idx
         i < f->total;               // enquanto i for menor que o tamanho total da fila
         i++, idx = (idx + 1) % MAX) // incrementa i e idx recebe a logica circular
    {
        printf("[%s, %d] ", f->pecas[idx].nome, f->pecas[idx].id);
    }
    printf("\n");
}

void inserir(Fila *f, Peca p)
{ // enqueue
    if (filaCheia(f))
    {
        printf("Fila cheia. Não é possivel inserir.\n");
        return;
    }

    f->pecas[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
    printf("Nova peça adicionada: %s (ID: %d)\n", p.nome, p.id);
}

void remover(Fila *f, Peca *p) // dequeue
{
    if (filaVazia(f))
    {
        printf("Fila vazia. Não é possivel remover.\n");
        return;
    }
    *p = f->pecas[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    printf("Peça jogada: %s (ID: %d)\n", p->nome, p->id);
}

int gera() // gera um numero aleatorio entre 0 e 4
{
    static int inicializado = 0;
    if (!inicializado)
    {
        srand(time(NULL));
        inicializado = 1;
    }
    return (rand() % 5);
}

Peca gerarPeca(int *id_ptr) // gera uma peça aleatoria
{
    Peca p;
    int tipo = gera();

    char pecas[5][10] = {"I", "O", "T", "L", "Z"};

    strcpy(p.nome, pecas[tipo]);

    (*id_ptr)++;
    p.id = *id_ptr;

    return p;
}

void limpaBuffer() // Limpa buffer de entrada
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void exibeMenu(Fila *f)
{
    int opcao;
    Peca pecaRemovida;
    printf("*** TETRIS STACK ***\n");

    do
    {
        printf("\n");
        printf("1 - Jogar peça (remover)\n");
        printf("2 - Adicionar nova peça\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("\nEscolha uma opção: ");

        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
        {
        case 1: // Jogar peça (remover)
            remover(f, &pecaRemovida);
            mostrarFila(f);
            break;

        case 2: // Adicionar nova peça (inserir)
        {
            inserir(f, gerarPeca(&id));
            mostrarFila(f);
        }
        break;

        case 3: // Mostrar fila
            mostrarFila(f);
            break;

        case 0: // Sair
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    } while (opcao != 0);
}