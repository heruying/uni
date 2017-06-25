#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void geraAleatorios(char *txt) {
    int randx, randy, aleatorios = 0;
    for (int i = 0; i < 250; i++) {
        if (txt[i] == '2') {
            aleatorios++;
        }
    }
    printf("Devem ser geradas %i posições finais.\n", aleatorios);
    for (int i = 0; i < aleatorios; i++) {
        do {
            randx = rand() % 10;
            randy = rand() % 25;
        } while (txt[randx*randy] != '0');
        txt[randx*randy] = '*';
        printf("Posição final %i: %i %i.\n", i, randx, randy);
    }
}

int main() {
        srand(time(NULL));
        char arquivo[100], txt[250];
        FILE *stream, *output;
        printf("Informe nome do arquivo: ");
        __fpurge(stdin);
        scanf("%s", arquivo);
        stream = fopen(arquivo, "r");
        if (stream == NULL) {
            printf("ERRO NA ABERTURA DO ARQUIVO");
            getchar();
            return 0;
        }
        for (int i = 0; i < 10; i++) {
            fscanf(stream, "%s", &txt[i*25]);
        }
        geraAleatorios(txt);
        fclose(stream);
        output = fopen("saida.txt", "w");
        if (output == NULL) {
            printf("ERRO NA ABERTURA DO ARQUIVO");
            getchar();
            return 0;
        }
        for (int i = 0; i < 250; i++) {
            putc(txt[i], output);
            if (!((i + 1) % 25) && i > 0)
                putc('\n', output);
        }
}
