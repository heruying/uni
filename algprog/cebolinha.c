#include <stdio.h>
#include <string.h>

int main() {
  char phrase[250];
  int c = 0;
  printf("Insira a frase a ser CEBOLADA: ");
  scanf("%s", phrase);
  printf("%s", phrase);
  for (int i = (strlen(phrase) - 1); i <= 0; i--) {
    if (phrase[i] == 82 || phrase[i] == 114) {
      phrase[i] -= 76;
      c++;
    }
  }
  printf("%s!\n Foram trocados %d R/r.", phrase, c);
  return 0;
}
