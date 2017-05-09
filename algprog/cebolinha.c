#include <stdio.h>
#include <string.h>

int main() {
  char phrase[250];
  int c = 0;
  printf("Insira a frase a ser CEBOLADA: ");
  fgets(phrase, 250, stdin);
  for (int i = (strlen(phrase) - 1); i >= 0; i--) {
    if (phrase[i] == 82 || phrase[i] == 114) {
      if (!(phrase[(i + 1)] == 32)) {
          phrase[i] -= 6;
          c++;
      }
    }
  }
  printf("%s\n Foram trocados %d R/r's.\n", phrase, c);
  return 0;
}
