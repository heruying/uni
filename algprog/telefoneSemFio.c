#include <stdio.h>
#include <string.h>

int main () {
    int t, t1, t2, stringSize;
    char frases[3][101];
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        t1 = 0;
        t2 = 0;
        for (int i = 0; i < 3; i++) {
            __fpurge(stdin);
            fgets(frases[i], 101, stdin);
        }
        stringSize = strlen(frases[0]);
        for (int i = 0; i < stringSize; i++ ) {
            if (frases[0][i] == frases[1][i]) {
                t1++;
            }
            if (frases[0][i] == frases[2][i]) {
                t2++;
            }
        }
        printf("Instância %d\n", k);
        if (t1 < t2) {
            printf("time 2\n\n");
        } else if (t1 > t2) {
            printf("time 1\n\n");
        } else {
            printf ("empate\n\n");
        }

    }


    return 0;
}
