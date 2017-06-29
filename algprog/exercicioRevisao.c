#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct aluno {
    int codigo;
    char nome[100];
    float notas[4];
};

struct codigoenota {
    int codigo;
    float nota;
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

struct aluno parsearCSV(char line[1024]) {
    struct aluno doArquivo;
    doArquivo.codigo = atoi(strtok(line, ","));
    sscanf(strtok(NULL, ","), "%s", doArquivo.nome);
    doArquivo.notas[0] = atof(strtok(NULL, ","));
    doArquivo.notas[1] = atof(strtok(NULL, ","));
    doArquivo.notas[2] = atof(strtok(NULL, ","));
    doArquivo.notas[3] = atof(strtok(NULL, ","));
    return doArquivo;
}

void appendBinario (struct codigoenota aluno) {
    FILE *stream = fopen ("notas.bin", "a+b");
    if (stream == NULL) {
        printf("Erro ao abrir arquivo binário");
    } else {
        fwrite(&aluno, sizeof(struct codigoenota), 1, stream);
        printf("%06d: %.02f\n", aluno.codigo, aluno.nota);
    }
    fclose(stream);
}

void exibeCodigo() {
    FILE *stream = fopen ("notas.bin", "rb");
    int i;
    if (stream == NULL) {
        printf("Erro ao abrir arquivo binário");
    } else {
        fseek(stream, 0L, SEEK_END);
        i = ftell(stream) / sizeof(struct codigoenota);
        if (!i) {
            printf("there aren't any highscores stored");
        } else {
            rewind(stream);
            struct codigoenota alunos[i];
            fread(alunos, sizeof(struct codigoenota), i, stream);
            fclose(stream);
            printf("%5s | NF\n", "COD");
            for (int j = 0; j < i; j++) {
                printf("%06d %.02f\n", alunos[j].codigo, alunos[j].nota);
            }
        }
    }
}

void calculaExibe (int arg, struct aluno alunos[]) {
    float notasFinais[arg], mediaTurma;
    struct codigoenota temp;
    for (int i = 0; i < arg; i++) {
        temp.nota = notasFinais[i] = notaFinal(alunos[i]);
        temp.codigo = alunos[i].codigo;
        appendBinario(temp);
    }
    mediaTurma = calculaMedia(notasFinais, arg);
    printf("COD   | %-100s | %-4s | %-4s | %-4s | %-4s | %-4s\n", "NOME", "P1", "P2", "AP", "TF", "NF");
    for (int i = 0; i < 141; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < arg; i++){
        printf("%03i | %-100s | %4.02f | %4.02f | %4.02f | %4.02f | %4.02f\n", alunos[i].codigo, alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].notas[3], notasFinais[i]);
    }
    printf("\nMedia das notas = %.02f\n", mediaTurma);
}

int main() {
    int arg = 0, txt;
    char nomeTexto[100], linha[1024];
    do {
        printf("[0] Ler de arquivo texto;\n[1] Ler do teclado; \n[2] Imprimir notas;\n");
        scanf("%i", &txt);
    } while (txt < 0 || txt > 2 );
    if (txt == 1) {
        do {
            printf("Quantos alunos serão calculados? \n");
            scanf("%i", &arg);
        } while (arg <= 0);
        struct aluno alunos[arg];
        for (int i = 0; i < arg; i++) {
            printf("Insira os dados do aluno (nome/código/notas): \n");
            leAluno(&alunos[i]);
        }
        calculaExibe(arg, alunos);
    } else if (txt == 2){
        exibeCodigo();
    } else {
        printf("Qual o nome do arquivo a ser lido?\n");
        __fpurge(stdin);
        scanf("%s", nomeTexto);
        FILE *stream = fopen(nomeTexto, "r");
        if (stream == NULL) {
            printf("ERRO NA ABERTURA DO ARQUIVO");
            return -1;
        }
        while (fgets(linha, sizeof(linha), stream)) {
            arg++;
        }
        rewind(stream);
        struct aluno alunos[arg];
        for (int i = 0; i < arg; i++) {
            fgets(linha, sizeof(linha), stream);
            alunos[i] = parsearCSV(linha);
        }
        fclose(stream);
        calculaExibe(arg, alunos);
    }
}
