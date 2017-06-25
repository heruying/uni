#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>

typedef struct struct_jogador {
    char nome[20];
    float pontuacao;
    int niveis;
} jogador;

jogador retornaJogador (char nome[20], float pontuacao, int niveis) {
    struct struct_jogador temp;
    strcpy(temp.nome, nome);
    temp.pontuacao = pontuacao;
    temp.niveis = niveis;
    return temp;
}

int leBin() {
    FILE * highscores = fopen("highscores.bin", "rb");
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin");
        return -1;
    } else {
        int structs;
        fseek(highscores, 0, SEEK_END);
        structs = ftell(highscores) / sizeof(jogador);
        rewind(highscores);
        jogador jogadores[structs];
        fread(jogadores, sizeof(jogador), structs, highscores);
        fclose(highscores);
        for (int i = 0; i < structs; i++) {
            printf("%s, %f, %i\n", jogadores[i].nome, jogadores[i].pontuacao, jogadores[i].niveis);
        }
        return 0;
    }
}

int procuraJogador(char nome[20]) {
    FILE * highscores = fopen("highscores.bin", "rb");
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin\n");
        return 0;
    } else {
        fseek(highscores, 0L, SEEK_END);
        int structs = ftell(highscores) / sizeof(struct struct_jogador);
        if (structs) {
            rewind(highscores);
            jogador jogadores[structs];
            fread(jogadores, sizeof(jogador), structs, highscores);
            fclose(highscores);
            for (int i = 0; i < structs; i++) {
                if (!strncmp(nome, jogadores[i].nome, strlen(nome))) {
                    printf("%s, %f, %i", jogadores[i].nome, jogadores[i].pontuacao, jogadores[i].niveis);
                    return 1;
                }
            }
        }
    }
    fclose(highscores);
    printf("Jogador %s não tem scores registrados.\n", nome);
    return 0;
}

int appendBin(jogador registro) {
    FILE * highscores = fopen("highscores.bin", "a+b");
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin");
        fclose(highscores);
        return -1;
    }
    fwrite(&registro, sizeof(jogador), 1, highscores);
    fclose(highscores);
    return 0;
}

int atualizaBin(jogador registro, float score) {
    FILE * highscores = fopen("highscores.bin", "wb");
    fclose(highscores);
    return 0;
    if (highscores == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO highscores.bin");
        fclose(highscores);
        return -1;
    } else {
        fseek(highscores, 0, SEEK_END);
        int structs = ftell(highscores) / sizeof(struct struct_jogador);
        rewind(highscores);
        jogador jogadores[structs];
        fread(jogadores, sizeof(struct struct_jogador), structs, highscores);
        for (int i = 0; i < structs; i++) {
            if (registro.nome == jogadores[i].nome) {
                if (score > jogadores[i].pontuacao) {
                    rewind(highscores);
                    fwrite(&registro, sizeof(struct struct_jogador), structs, highscores);
                    fclose(highscores);
                    return 0;
                } else {
                    rewind(highscores);
                    fwrite(&registro, sizeof(struct struct_jogador), structs, highscores);
                    fclose(highscores);
                    return 0;
                }
            }
        }
    }
    fclose(highscores);
    return 0;
}

int main () {
    int opcao, niveis;
    char nome[20];
    float pontuacao;
    jogador temporario;
    printf("1. Procurar score jogador\n2. Adicionar dados jogador\n3. Imprimir scores.\n4. para sair.\n");
    do {
        printf("Digite sua opção: ");
        do {
            scanf("%d", &opcao);
        } while (opcao < 1 && opcao > 4);
        switch (opcao) {
            case 1:
                printf("Digite o nome do jogador: ");
                __fpurge(stdin);
                scanf("%s", nome);
                procuraJogador(nome);
                break;
            case 2:
                printf("Digite os dados do jogador: ");
                __fpurge(stdin);
                scanf("%s %f %i", nome, &pontuacao, &niveis);
                temporario = retornaJogador(nome, pontuacao, niveis);
                if (procuraJogador(temporario.nome)) {
                    atualizaBin(temporario, temporario.pontuacao);
                } else {
                    appendBin(temporario);
                }
                break;
            case 3:
                leBin();
                break;
        }
    } while (opcao != 4);
    return 0;
}
