#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_jogador {
    char name[21];
    float points;
    int totalTime;
};

struct struct_jogador readData(void);
void meanDisplay(struct struct_jogador players[5]);
void inList(struct struct_jogador players[5]);

int main() {
    struct struct_jogador highscore[5];
    for (int i = 0; i < 5; i++) {
        printf("Informe os dados do jogador %d: \n", (i + 1));
        highscore[i] = readData();
    }
    meanDisplay(highscore);
    inList(highscore);
}


struct struct_jogador readData(void) {
    struct struct_jogador temporary;
    scanf("%s %f %i", temporary.name, &temporary.points, &temporary.totalTime);
    return temporary;
}

void meanDisplay(struct struct_jogador players[5]) {
    float mean = 0;
    for (int i = 0; i < 5; i++) {
        mean += players[i].totalTime;
    }
    mean = mean / 5;
    printf("A média do tempo do jogo foi: %0.1f\nJogadores com tempo abaixo da média:\nNome              Pontuação            Tempo\n", mean);
    for (int i = 0; i < 5; i++) {
        if (players[i].totalTime < mean) {
        printf("%s %*.1f %19.i\n", players[i].name, (int)(21 - strlen(players[i].name)), players[i].points, players[i].totalTime);
        }
    }
}

void inList(struct struct_jogador players[5]) {
    char nameToCheck[21];
    int check = 1;
    printf("Informe o nome do jogador:\n");
    scanf("%s", nameToCheck);
    for (int i = 0; i < 5; i++) {
        if (!(strcmp(players[i].name, nameToCheck))) {
            printf("Nome              Pontuação            Tempo\n%s %*.1f %19.i\n", players[i].name, (int)(21 - strlen(players[i].name)), players[i].points, players[i].totalTime);
            check = 0;
        }
    }
    if (check) {
            printf("Jogador %s nao esta no ranking top 5.\n", nameToCheck);
    }
}
