#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arraySize 15
#define alunosArraySize 10

/*
    typedef struct minEMax {
        float menor, maior;
    } minEMax;
}
    minEMax procuraMaiorEMenor(aluno_t *alunos, int tamanho);
*/

typedef struct aluno_t {
    char nome[30];
    int idade;
    float notaFinal;
}aluno_t;

void procuraMaiorEMenor(aluno_t *alunos, int tamanho, float *menor, float *maior) {
    *maior = *menor = alunos[0].notaFinal;
    for (int i = 0; i < tamanho; i ++) {
        if (alunos[i].notaFinal < *menor) {
            *menor = alunos[i].notaFinal;
        } else if (alunos[i].notaFinal > *maior) {
            *maior = alunos[i].notaFinal;
        }
    }
};

void imprimeAlunosAcima(aluno_t *alunos, int tamanho, float media) {
    for (int i = 0; i < tamanho; i++) {
        if (alunos[i].notaFinal > media)
            printf("Nome do aluno: %s\nIdade do aluno: %i\nNota final do aluno: %f\n", alunos[i].nome, alunos[i].idade, alunos[i].notaFinal);
    }
}

int geradorDeAleatorios(int min, int max) {
    int random;
    random = (rand() % (max - min)) + min + 1;
    return random;
}

void inicializadorDeVetor(int *array, int sizeOfArray) {
    for (int j = 0; j < sizeOfArray; j++)
        array[j] = geradorDeAleatorios(10, 100);
}

aluno_t criaAluno_t() {
    aluno_t aluno;
    printf("Nome do aluno: ");
    __fpurge(stdin);
    scanf("%s", aluno.nome);
    printf("Idade do aluno: ");
    scanf("%i", &aluno.idade);
    printf("Nota final do aluno: ");
    scanf("%f", &aluno.notaFinal);
    return aluno;
}

void criaAluno_tReferencia(aluno_t *aluno) {
    printf("Nome do aluno: ");
    __fpurge(stdin);
    scanf("%s", aluno->nome);
    printf("Idade do aluno: ");
    scanf("%i", &aluno->idade);
    printf("Nota final do aluno: ");
    scanf("%f", &aluno->notaFinal);
}

int main() {
    int array[arraySize];
    float menor, maior;
    aluno_t alunos[alunosArraySize];
    srand(time(NULL));
    printf("\nPrimeiro exercício\n\n");
    for (int i = 0; i < arraySize; i++)
        array[i] = geradorDeAleatorios(10, 100);
    for (int i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n");
    inicializadorDeVetor(array, arraySize);
    for (int i = 0; i < arraySize; i++)
        printf("%d ", array[i]);
    printf("\n\nTerceiro exercício\n\n");
    for (int i = 0; i < alunosArraySize / 2; i++)
        alunos[i] = criaAluno_t();
    for (int i = 0; i < alunosArraySize / 2; i++)
        printf("Nome do aluno: %s\nIdade do aluno: %i\nNota final do aluno: %f\n", alunos[i].nome, alunos[i].idade, alunos[i].notaFinal);
    for (int i = alunosArraySize / 2; i < alunosArraySize; i++)
        criaAluno_tReferencia(&alunos[i]);
    for (int i = alunosArraySize / 2; i < alunosArraySize; i++)
        printf("Nome do aluno: %s\nIdade do aluno: %i\nNota final do aluno: %f\n", alunos[i].nome, alunos[i].idade, alunos[i].notaFinal);
    printf("\n\nQuarto exercício\n\n");
    procuraMaiorEMenor(alunos, alunosArraySize, &menor, &maior);
    printf("Menor nota: %f\nMaior nota: %f", menor, maior);
    printf("\n\nQuinto exercício\n\n");
    imprimeAlunosAcima(alunos, alunosArraySize, 6);
    return 0;
}
