#include <stdio.h>
#include <stdlib.h>

int le_valor();
char le_indicador();
int busca_maior(int x, int y, int z);
int busca_menor(int x, int y, int z);

int main() {
    int x, y, z;
    char j;
    x = le_valor();
    y = le_valor();
    z = le_valor();
    j = le_indicador();
    if (j == 'M') {
        printf("%d\n", busca_maior(x, y, z));
    } else {
        printf("%d\n", busca_menor(x, y, z));
    }
}

int le_valor() {
    int x;
    do {
        scanf("%d", &x);
    } while (x < 1);
    return x;
}

char le_indicador() {
    char x;
    do {
        __fpurge(stdin);
        scanf("%c", &x);
    } while (x != 'M' && x != 'm');
    return x;
}

int busca_maior(int x, int y, int z) {
    if (x > y) {
        if (x > z) {
            return x;
        }
        else {
            return z;
        }
    } else if (y > z) {
        return y;
    } else {
        return z;
    }
}

int busca_menor (int x, int y, int z) {
    if (x < y) {
        if (x < z) {
            return x;
        }
        else {
            return z;
        }
    } else if (y < z) {
        return y;
    } else {
        return z;
    }
}
