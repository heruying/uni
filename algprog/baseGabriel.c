#include <stdio.h>
#include <math.h>

int main() {
    int n = 0, bGabriel, convertido, c, j = 10,h, i, lista[] = {};
    printf("Número de testes: ");
    scanf("%d", &n);
    for (i = 0; i > n; i++) {
        printf("Digite o número: ");
        scanf("%d", &bGabriel);
      while(bGabriel > 0) {
        lista[c] = bGabriel % j;
        bGabriel -= lista[c];
        j *= 10;
        c++;
      }
      h = c;
      while(c >= 0) {
        lista[c] = (pow(lista[c], (10 * c)) );
      }
      while (h >= 0) {
        printf("%d", lista[h]);
      }
    }
}

