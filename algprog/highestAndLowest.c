#include <stdio.h>

int main() {
  float array[200], media = 0, maior, menor;
  int alturas;
  printf("Quantas alturas serão usadas? ");
  scanf("%d", &alturas);
  printf("Digite as alturas: ");
  for (int i = 0; i < alturas; i++) {
    scanf("%f", &array[i]);
  }
  maior = array[0];
  menor = array[0];
  for (int i = 0; i < alturas; i++) {
    media += array[i];
    if (array[i] < menor) {
      menor = array[i];
    } else if (array[i] > maior) {
      maior = array[i];
    }
  }
  media = media / alturas;
  printf("A media das alturas é %.02f, a maior altura é %.02f e a menor altura é %.02f.\n", media, maior, menor);
  return 0;
}
