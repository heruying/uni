#include <stdio.h>

int main () {
  char nome[40][81];
  float notas[40];
  int frequencia[40], alunos = 0;
  do {
      printf("Quantos alunos serão computados?\n");
      scanf(" %d", &alunos);
  } while (alunos <= 0);
  for (int i = 0; i < alunos; i++) {
      printf("Insira o nome do aluno: ");
      __fpurge(stdin);
      fgets(nome[i], 81, stdin);
      printf("Insira a nota do aluno: ");
      scanf("%f", &notas[i]);
      printf("Insira a frequência total do aluno: ");
      scanf("%d", &frequencia[i]);

  }
  return 0;
}
