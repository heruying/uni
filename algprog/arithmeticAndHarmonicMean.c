#include <stdio.h>
#include <math.h>

void main() {
    float x1, x2, x3;
    printf("Insira os valores, pressionando enter entre cada um deles: ");
    scanf("%f %f %f", &x1, &x2, &x3);
    printf("Média aritmética: %3.2f \nMédia harmônica: %3.2f \n", ((x1 + x2 + x3)/ 3), (3 / ((1 / x1) + (1 / x2) + (1 / x3))));

}