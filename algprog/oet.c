#include <stdio.h>

void main() {
    int p, j1, j2, r, a;
    printf("Insira a jogada: ");
    scanf("%i %i %i %i %i", &p, &j1, &j2, &r, &a);
        if (r && a) {
            printf("Jogador 2 ganha!\n");
        }
        else if (r || a) {
            printf("Jogador 1 ganha!\n");
        }
        else {
            if (((j1 + j2) % 2) != p) {
                printf("Jogador 1 ganha!\n");
            }
            else {
                printf("Jogador 2 ganha!\n");
            }
    }
}