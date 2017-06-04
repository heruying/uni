#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void criaMatriz ();

int main () {
    srand(time(NULL));
    for (int i = 0; i < 3; i++){
        printf("%dª matriz: \n", (i +1));
        criaMatriz();
        printf("\n");
    }
    return 0;
}

void criaMatriz() {
    int array[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
                array[i][j] = 5 + (rand() % 11);
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%3d", array[i][j]);
        }
        printf(" ]");
        printf("\n");
    }
}
