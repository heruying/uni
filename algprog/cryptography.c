#include <stdio.h>

int main() {
  int n = 0;
  char string[40];
  do {
    printf("Informe o número de strings na entrada: \n");
    scanf("%d", &n);
  } while (n < 1 || n > 20);
  for (int i = 0; i < n; i++) {
    printf("Informe a string %d: \n", (i+1));
    __fpurge(stdin);
    fgets(string, 40, stdin);
    for (int j = 0; string[j] != '\0'; j++) {
      if ((string[j] >= 65 && string[j] <= 90)) {
        if ((string[j] + 13) > 90) {
          string[j] -= 13;
        } else {
          string[j] += 13;
        }
      } else if ((string[j] >= 97) && (string[j] <= 122)) {
        if ((string[j] + 13) > 122) {
          string[j] -= 13;
        } else {
          string[j] += 13;
        }
      }
    }
    printf("%s", string);
  }

}
