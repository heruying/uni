#include <stdio.h>

int main() {
    int distancia[5][5], maisDistante[2], maiorDistancia, analisada = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 4; j++) {
            if (j == i) {
                distancia[i][j] = 0;
            } else if (i > j) {
                distancia[i][j] = distancia[j][i];
            } else {
                do {
                    printf("Entre com a distancia entre as cidades [%d,%d]: ", i, j);
                    scanf(" %d", &distancia[i][j]);
                } while (distancia[i][j] <= 0);
            }
            if (maiorDistancia < distancia[i][j]) {
                maiorDistancia = distancia[i][j];
                maisDistante[0] = i;
                maisDistante[1] = j;
            }
        }
    }
    printf("\nMatriz de distâncias:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%3d ", distancia[i][j]);
        }
        printf("\n");
    }
    printf("\nAs duas cidades mais distantes entre si são %d e %d.\n", maisDistante[0], maisDistante[1]);
    do {
        printf("Qual o indice da cidade que quer analisar? ");
        scanf("%d", &analisada);
    } while (analisada < 0 || analisada > 5);
    maiorDistancia = 0;
    for (int i = 0; i < 5; i++) {
        if (distancia[i][analisada] > maiorDistancia) {
            maisDistante[0] = i;
        }
    }
    printf("A cidade mais distante da cidade com índice %d é a cidade com índice %d.\n", analisada, maisDistante[0]);
    return 0;
}
