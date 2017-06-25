#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct aluno {
    char nome[100];
    int codigo;
    float notas[4];
};

float leValor() {
    float f;
    do {
        __fpurge(stdin);
        scanf("%f", &f);
        if (f <= 0 || f >= 10) {
            printf("Nota inválida!\n");
        }
    } while (!((f >= 0) && (f <= 10)));
    return f;
}

float calculaMedia(float *notas, int n) {
    float media = 0;
    for (int i = 0; i < n; i++) {
        media += notas[i];
    }
    media /= n;
    return media;
}

void leAluno(struct aluno *aluno) {
    __fpurge(stdin);
    fgets(aluno->nome, 100, stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = 0;
    scanf("%i", &aluno->codigo);
    for (int i = 0; i < 4; i++) {
        aluno->notas[i] = leValor();
        printf("notas: %0.2f\n", aluno->notas[i]);
    }
}

float notaFinal(struct aluno aluno) {
    float f = 0;
    f += aluno.notas[0] * 0.3;
    f += aluno.notas[1] * 0.45;
    f += aluno.notas[2] * 0.15;
    f += aluno.notas[3] * 0.1;
    return f;
}

int main (int argc, char *argv[]) {
    int arg;
    if (argc == 2) {
        arg = atoi(argv[1]);
    } else {
        arg = 20;
    }
    struct aluno alunos[arg];
    float notasFinais[arg], mediaTurma;
    for (int i = 0; i < arg; i++) {
        printf("Insira os dados do aluno (nome/código/notas): \n");
        leAluno(&alunos[i]);
    }
    for (int i = 0; i < arg; i++) {
        notasFinais[i] = notaFinal(alunos[i]);
    }
    mediaTurma = calculaMedia(notasFinais, arg);
    printf("COD | %-100s | %-4s | %-4s | %-4s | %-4s | %-4s\n", "NOME", "P1", "P2", "AP", "TF", "NF");
    for (int i = 0; i < 141; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < arg; i++){
        printf("%03i | %-100s | %4.02f | %4.02f | %4.02f | %4.02f | %4.02f\n", alunos[i].codigo, alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].notas[3], notasFinais[i]);
    }
    printf("\nMedia das notas = %.02f\n", mediaTurma);
}
