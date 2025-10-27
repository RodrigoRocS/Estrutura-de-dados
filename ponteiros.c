#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x; // a variavel 'p' do tipo ponteiro (*) recebe o endereço de 'x'

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteudo de p (o endereço): %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    // saida:
    // Valor de x: 10
    // Endereço de x: 0x7fffee5070bc
    // Conteudo de p (o endereço): 0x7fffee5070bc
    // Valor apontado por p: 10

    return 0;
}
