#include <stdio.h>

void main() {
    int p1, p2, c1, c2, a, b;
    printf("Insira as entradas: \n");
    scanf("%i %i %i %i", &p1, &c1, &p2, &c2);
    a = p1 * c1;
    b = p2 * c2;
    if (a == b) {
        printf("0\n");
    }
    else if (a > b) {
        printf("-1\n");
    }
    else {
        printf("1\n");
    }
}