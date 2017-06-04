#include <stdio.h>

int main() {
  int n[10][2], n1, n2, c = 1, aceitos = 0, rejeitados = 0, i = 0;
  while (i < 10) {
    n[i][0] = i;
    n[i][1] = 0;
    i++;
  }
  while (c == 1) {
    scanf(" %d %d", &n1, &n2);
    i++;
    if ((n1 + n2) % 2 && n1 < 3) {
      n[n1][1]++;
      n[n2][1]++;
      aceitos++;
    }
    else {
      rejeitados++;
    }
    do {
      printf("Novo convite? (1-sim, 2-nao)\n");
      scanf("%d", &c);
    } while (c != 1 && c != 2);
  }
  printf("Foram aceitos %d convites.\nForam rejeitados %d convites.\n", aceitos, rejeitados);
  for (i = 0, c = 0; i++ < 10; i++) {
    if (n[i][1] > c) {
      n1 = n[i][0];
    }
  }
  printf("Dígito %d foi quem teve mais convites aceitos.\n", n1);
}
