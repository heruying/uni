#include <stdio.h>

void main() {
    float x, y, c;
    printf("Insira as coordernadas X e Y do ponto espaçadas pela tecla enter: \n");
    scanf("%f %f", &x, &y);
    c = x * y;
    if (x > 0) {
        if (c < 0) {
            printf("Quadrante 4\n");
        }
        else if (c > 0) {
            printf("Quadrante 1\n");
        }
        else {
            printf("Eixo X\n");
        }
    }
    else if (x < 0) {
        if (c < 0) {
            printf("Quadrante 2\n");
        }
        else if (c > 0) {
            printf("Quadrante 3\n");
        }
        else {
            printf("Eixo X\n");
        }
    }
    else {
        if (y != 0) {
            printf("Eixo Y\n");
        }
        else {
            printf("Origem\n");
        }
    }
}