#include <stdio.h>
#include <stdlib.h>

// malloc() = memory Allocation não limpa o endereço
// calloc() = Clear Allocation inicializa com todos os bytes no 0
// free() = Liberação de memoria

/*
1. int *vetor
int - Tipo de dados que o ponteiro vai apontar

* - Indica que é um ponteiro

vetor - Nome da variável ponteiro

Significado: Declara um ponteiro que aponta para inteiros

2. malloc(5 * sizeof(int))
malloc() - Função que aloca memória

5 - Quantidade de elementos que queremos

* - Operador de multiplicação

sizeof(int) - Retorna o tamanho em bytes de um int

Cálculo: 5 × 4 bytes (se int = 4 bytes) = 20 bytes alocados

3. (int*) - Cast (conversão de tipo)
Converte o retorno do malloc() para "ponteiro para int"

malloc() retorna void* (ponteiro genérico)

(int*) transforma em int* (ponteiro específico para int)
*/

void saudacao()
{
    printf("Olá, mundo!");
}

int main()
{

    int tamanho;
    printf("Quantos números você quer? ");
    scanf("%d", &tamanho); // Usuário define o tamanho

    int *vetor = (int *)malloc(tamanho * sizeof(int)); // Tamanho VARIÁVEL
    int *numeros = (int *)calloc(tamanho, sizeof(int));

    printf("Conteudo de vetor (o endereço): %p\n", vetor);
    printf("Conteudo de numeros (o endereço): %p\n", numeros);
    printf("Conteudo de *vetor (o endereço): %d\n", *vetor);
    printf("Conteudo de *numeros (o endereço): %d\n", *numeros);
    free(vetor);
    free(numeros);

    typedef struct
    {
        char nome[50];
        int idade;
    } Pessoa;

    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    printf("Digite o nome: ");
    scanf("%s", p->nome); // para atribuir um ponteiro para struct usa-se '->'

    printf("Digite a idade: ");
    scanf("%d", &p->idade); // para atribuir um ponteiro para struct usa-se '->'

    printf("%s tem %d anos.\n", p->nome, p->idade); // para atribuir um ponteiro para struct usa-se '->'

    free(p);

    void (*ptr)() = saudacao; // ponteiro para função
    ptr();                    // chamada indireta

    // float (*func_ptr)(int, int); exemplo de função que recebe 2 int como parametro e retorna um float
    return 0;
}