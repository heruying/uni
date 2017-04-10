#include <stdio.h>
#include <math.h>

void main() {
    double dollarPrice = 0, value = 0;
    printf("Digite o valor do produto em reais: ");
    scanf("%lf", &value);
    printf("Digite o valor do dólar: ");
    scanf("%lf", &dollarPrice);
    printf("O valor do produto em dólar é: U$%2.2f\n", (value * dollarPrice));
}