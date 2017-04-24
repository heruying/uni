#include <stdio.h>

int main() {
    int n = 0, i, c, h = 1;
    int r[] = {};
    char j = '9';
    while (n < 1) {
        printf("Insira o valor a ser calculado: ");
        scanf("%i", &n);
        if (n < 1) {
            printf("Numero invalido\n");
        }
    }
    while (j != 'f' && j != 'F' && j != 'd' && j != 'D') {
        printf("Qual cálculo deve ser aplicado sobre o valor? Fatorial (f/F) ou divisores (d/D): ");
        scanf(" %c", &j);
        printf("TESTE");
        if (j != 'f' && j != 'F' && j != 'd' && j != 'D') {
            printf("Opcao invalida\n");
        }
    }
    printf("test");
    if (j == 'f' || j == 'F') {
        for (i = 0; i < n; i++) {
            r[i] = (n - i);
        }
        printf("%i! = ", n);
        for (i = 0; i < n; i++) {
            for (c = -1; c < i; c++) {
                printf("%i x ", r[(c + 1)]);
            }
            if (r[(i + 1)] > 0) {
                printf("%i! = ", r[(i + 1)]);
            }
            else {
                printf("0! = ");
                printf("%i", h);
            }
            }

    }
    printf("test");
    return 0;
}
