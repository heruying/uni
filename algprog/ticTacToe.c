#include <stdio.h>

int main() {
  char tabuleiro[3][4];
  int aux = 0, a = 0;
  for (int i = 0; i < 3; i++) {
    fgets(tabuleiro[i], 4, stdin);
    __fpurge(stdin);
  }
  if (tabuleiro[1][1] == tabuleiro[0][0] && tabuleiro[1][1] == tabuleiro[2][2]) {
    a = tabuleiro[1][1];
  } else if (tabuleiro[1][1] == tabuleiro[0][2] && tabuleiro[1][1] == tabuleiro[2][0]) {
    a = tabuleiro[1][1];
  } else {
    for (int i = 0; i < 3; i++) {
      aux = (tabuleiro[i][0] + tabuleiro[i][1] + tabuleiro[i][2]) / 3;
      if (aux == 'X' || aux == 'O') {
        a = aux;
      }
    }
    if (!a) {
      for (int i = 0; i < 3; i++) {
        aux = (tabuleiro[0][i] + tabuleiro[1][i] + tabuleiro[2][i]) / 3;
        if (aux == 'X' || aux == 'O') {
          a = aux;
        }
      }
    }
  }
  if (a) {
    printf("O vencedor foi o jogador: %c\n", a);
  }
  else {
    printf("Houve empate!\n");
  }
  return 0;
}
