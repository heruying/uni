#include <stdio.h>

int main() {
    int numero = 0, i, contador, h = 1;
    char j = '9';

    while (numero < 1) {
        printf("Insira o valor a ser calculado: ");
        scanf(" %d", &numero);
        if (numero < 1) {
            printf("Numero invalido\n");
        }
    }
    while (j != 'f' && j != 'F' && j != 'd' && j != 'D') {
        printf("Qual cálculo deve ser aplicado sobre o valor? Fatorial (f/F) ou divisores (d/D): ");
        scanf(" %c", &j);
        if (j != 'f' && j != 'F' && j != 'd' && j != 'D') {
            printf("Opcao invalida\n");
        }
    }
    if (j == 'f' || j == 'f') {
        for (i = numero; i > 1; i--) {
            h *= i;
        }
        printf("%i", h);
    }
    else {
        printf("Divisores de %i: ", numero);
        for (i = 1; i < numero; i++) {
            if (!(numero % i)) {
                printf("%i, ", i);
            }
        }
        printf("%i\n", i);
    }
}
