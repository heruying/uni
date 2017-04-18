#include <stdio.h>

void main() {
    int n = 0, i = 1, underAge = 0, totalAge = 0, actualAge = 0;
    printf("Insira o número de pessoas: ");
    scanf("%i", &n);
    while (i <= n) {
        printf("Insira a idade da pessoa número %i: ", i);
        scanf("%i", &actualAge);
        totalAge += actualAge;
        if (actualAge < 18) {
            underAge++;
        }
        i++;
    }
    printf("São %i pessoas, sendo a média das idades delas, %.2f, e a quantidade de menores de idade é %i. \n", n, ((float)actualAge/n), underAge);
}