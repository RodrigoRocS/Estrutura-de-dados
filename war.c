#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct // Define struct do territorio
{
    char nome[30], cor[10];
    int tropas;
} Territorio;

// ---- Protótipo das funções ----
void limpaBuffer();
void cadastraMapas(Territorio *t);
void exibeMapa(Territorio *t);
int rolarDado();
void faseDeAtaque(Territorio *t);
void atribuirMissao(char *destino, char *missoes[], int totalMissoes);

int main()

{
    char (*missoes)[50] = malloc(6 * sizeof(char[50]));
    strcpy(missoes[0], "Conquistar 1 territorio");
    strcpy(missoes[1], "Conquistar 2 territorios.");
    strcpy(missoes[2], "Conquistar todos os territorios.");
    strcpy(missoes[3], "Eliminar o exercito VERMELHO");
    strcpy(missoes[4], "Eliminar o exercito VERDE e AZUL");
    strcpy(missoes[5], "Conquistar 3 territorios.");

    Territorio *t = (Territorio *)calloc(5, sizeof(Territorio)); // alocação dinamica.
    if (t == NULL || missoes == NULL)                            // verifica se a alocação deu certo
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    cadastraMapas(t); // inicia cadastro de mapas

    exibeMapa(t); // exibe territorios

    faseDeAtaque(t); // inicia fase de ataque

    free(t); // libera memoria alocada

    return 0;
}

void atribuirMissao(char *destino, char (*missoes)[50], int totalMissoes)
{
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

void limpaBuffer() // Limpa buffer de entrada
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void cadastraMapas(Territorio *t) // cadastra 5 mapas para o jogo
{
    int numTerritorio = 0; // contador de territorios
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo: \n");
    do // inicia cadastro dos territorios
    {
        printf("\n=== Cadastrando Territorio %d ===\n", numTerritorio + 1);

        printf("Nome do territorio: ");
        fgets(t[numTerritorio].nome, 30, stdin);
        t[numTerritorio].nome[strcspn(t[numTerritorio].nome, "\n")] = 0;

        printf("Cor do territorio: ");
        fgets(t[numTerritorio].cor, 10, stdin);
        t[numTerritorio].cor[strcspn(t[numTerritorio].cor, "\n")] = 0;

        printf("Numero de tropas: ");
        scanf("%d", &t[numTerritorio].tropas);

        limpaBuffer();

        numTerritorio++; // incrementa o loop

    } while (numTerritorio < 5);
}

void exibeMapa(Territorio *t) // exibe mapa atualizado
{
    printf("\n=== MAPA DO MUNDO ===\n");
    for (int i = 0; i < 5; i++)
    {
        // printf("\n--- Territorio %d ---\n", i + 1);
        printf("%d - %s (Exercito %s, Tropas: %d)\n", i + 1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

int rolarDado() // gera um numero aleatorio entre 1 e 6
{
    static int inicializado = 0;
    if (!inicializado)
    {
        srand(time(NULL));
        inicializado = 1;
    }
    return (rand() % 6) + 1;
}

void faseDeAtaque(Territorio *t)
{

    int atacante;
    int defensor;
    int dadoAta;
    int dadoDef;
    char continuar;

    do
    {

        printf("\n*** FASE DE ATAQUE ***\n");
        printf("Escolha o territorio atacante (1 a 5, ou 0 para sair): \n");
        scanf("%d", &atacante);

        if (atacante == 0)
        {
            printf("Jogo encerrado e memoria liberada. até a proxima!");
            limpaBuffer();
            return;
        }

        printf("Escolha o territorio defensor (1 a 5): \n");
        scanf("%d", &defensor);
        atacante--; // corrige para acessar os indices corretos
        defensor--;

        limpaBuffer();

        printf("\n*** RESULTADO DA BATALHA ***\n");
        dadoAta = rolarDado();
        printf("o atacante %s rolou um dado e tirou: %d\n", t[atacante].nome, dadoAta);
        dadoDef = rolarDado();
        printf("o defensor %s rolou um dado e tirou: %d\n", t[defensor].nome, dadoDef);

        if (dadoAta > dadoDef)
        {
            printf("VITORIA DO ATAQUE! O defensor perdeu 1 tropa\n");
            t[defensor].tropas--;
            if (t[defensor].tropas == 0)
            {
                strcpy(t[defensor].cor, t[atacante].cor);
                printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s!\n", t[defensor].nome, t[atacante].cor);
                t[defensor].tropas = 1;
            }
        }
        else
        {
            printf("VITORIA DA DEFESA! O atacante perdeu 1 tropa\n");
            t[atacante].tropas--;
            if (t[atacante].tropas == 0)
            {
                strcpy(t[atacante].cor, t[defensor].cor);
                printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s!\n", t[atacante].nome, t[defensor].cor);
                t[atacante].tropas = 1;
            }
        }

        printf("\nPressione enter para continuar ao proximo turno...");
        continuar = getchar();
        exibeMapa(t);
    } while (continuar == '\n');
}