#include <stdio.h>
#include <math.h>

int main() {
  float n = 0, t = 0.00001, x, e;
  while (n <= 0) {
  printf("Insira o número ao qual será aplicado o método babilônico: ");
  scanf("%f", &n);
  }
  x = n/2;
  e = (x * x - n);
  if (e < 0) {
    e *= -1;
  }
  while (e > t) {
    printf("Aproximação: %.04f e erro: %0.04f.\n", x, e);
    x = (x + n/x) / 2;
    e = (x * x - n) * (-1);
    if (e < 0) {
      e *= -1;
    }
  }
  printf("%.04f\n", x);
  return 0;
}
