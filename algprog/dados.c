#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lancarDado();
int calcularPontos(int d1, int d2);

int main() {
  srand(time(NULL));
  int d1, d2, continuar, alvo, total;
  do {
    do {
      printf("Informe o alvo do jogo: ");
      scanf("%i", &alvo);
    } while (alvo > 22 || alvo <= 0);
    d1 = lancarDado();
    d2 = lancarDado();
    total = calcularPontos(d1, d2);
    printf("Os valores dos dados foram: %i e %i\n", d1, d2);
    printf("O total de pontos foi: %i\n", total);
    if (total <= alvo) {
      printf("O jogador perdeu.\n");
    } else {
      printf("O jogador ganhou!\n");
    }
    do {
      printf("Deseja continuar? 1 para sim e 0 para não;\n");
      scanf("%i", &continuar);
    } while (continuar != 1 && continuar != 0);
  } while (continuar);
}

int lancarDado() {
  return rand() % 6 + 1;
}

int calcularPontos(int d1, int d2) {
  if (!(d1 % 2)) {
    d1 = d1 * 2;
  }
  if (d2 % 2) {
    d2 = d2 * 2;
  }
  return d1 + d2;
}
