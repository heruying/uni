#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>

typedef struct struct_jogador {
    char nome[20];
    float pontuacao;
    int niveis;
} jogador;

int erroAbertura(char opcao) {
    FILE * highscores;
    switch (opcao) {
        case 'a':
            highscores = fopen("highscores.bin", "ab");
            break;
        case 'r':
            highscores = fopen("highscores.bin", "rb");
            break;
        case 'w':
            highscores = fopen("highscores.bin", "wb");
            break;
    } if (highscores == NULL) {
        fclose(highscores);
        return -1;
    } else {
        fclose(highscores);
        return 0;
    }
}

jogador retornaJogador (char nome[20], float pontuacao, int niveis) {
    struct struct_jogador temp;
    strcpy(temp.nome, nome);
    temp.pontuacao = pontuacao;
    temp.niveis = niveis;
    return temp;
}

int leBin() {
    if (erroAbertura('r')) {
        return -1;
    } else {
        FILE * highscores = fopen("highscores.bin", "rb");
        int structs;
        fseek(highscores, 0, SEEK_END);
        structs = ftell(highscores) / sizeof(jogador);
        rewind(highscores);
        jogador jogadores[structs];
        fread(jogadores, sizeof(jogador), structs, highscores);
        fclose(highscores);
        for (int i = 0; i < structs; i++) {
            printf("%s, %f, %i", jogadores[i].nome, jogadores[i].pontuacao, jogadores[i].niveis);
        }
        return 0;
    }
}

jogador procuraBin(char nome[20]) {
    FILE * highscores = fopen("highscores.bin", "rb");
    int structs;
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin");
        exit(EXIT_FAILURE);
    }
    fseek(highscores, 0, SEEK_END);
    structs = ftell(highscores) / sizeof(jogador);
    rewind(highscores);
    jogador jogadores[structs];
    fread(jogadores, sizeof(jogador), structs, highscores);
    fclose(highscores);
    for (int i = 0; i < structs; i++) {
        if (nome == jogadores[i].nome) {
}

int procuraJogador(char nome[20]) {
    FILE * highscores = fopen("highscores.bin", "rb");
    int structs;
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin");
        return -1;
    }
    fseek(highscores, 0, SEEK_END);
    structs = ftell(highscores) / sizeof(jogador);
    rewind(highscores);
    jogador jogadores[structs];
    fread(jogadores, sizeof(jogador), structs, highscores);
    fclose(highscores);
    for (int i = 0; i < structs; i++) {
        if (nome == jogadores[i].nome) {
            printf("%s, %f, %i", jogadores[i].nome, jogadores[i].pontuacao, jogadores[i].niveis);
            return 0;
        }
    }
    printf("Jogador %s não tem scores registrados.", nome);
    return -2;
}

int appendBin(jogador registro) {
    FILE * highscores = fopen("highscores.bin", "ab");
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin");
        return -1;
    }
    fwrite(&registro, sizeof(jogador), 1, highscores);
    fclose(highscores);
    return 0;
}

int atualizaBin(jogador registro, float score) {
    FILE
}
int main () {
    char nome[20];

    return 0;
}
