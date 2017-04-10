#include <stdio.h>

void main() {
    int value, counter = 0, bills[] = {100, 50, 20, 10, 5, 2, 1};

    printf("Insira o valor a ser calculado: ");
    scanf("%i", &value);
    while (value > 0) {
        if (value / bills[counter] > 0) {
                printf("%i nota(s) de R$%i \n", (value / bills[counter]), bills[counter]);
                value = (value % bills[counter]);
        }
        counter++;
    }
}
