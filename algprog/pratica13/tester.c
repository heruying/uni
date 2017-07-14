#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct pass {
    char pass[21];
    int userNumber;
} pass;

pass parseData(char line[100]) {
    pass local;
    local.userNumber = atof(strtok(line, ","));
    sscanf(strtok(NULL, ","), "%s", local.pass);
    return local;
}

int checkStructs(char fileName[100]) {
    FILE *textFile = fopen(fileName, "r");
    int i = 0;
    char line[100];
    if (textFile == NULL) {
        printf("Erro na abertura do arquivo");
    } else {
        while (fgets(line, sizeof(line), textFile) != NULL) {
            i++;
        }
    }
    fclose(textFile);
    return i;
}
void readPass (pass *passwords, char fileName[100], int i) {
    FILE *textFile = fopen(fileName, "r");
    char line[100];
    if (textFile == NULL) {
        printf("Erro na abertura do arquivo");
    } else {
        for (int j = 0; j < i; j++) {
                fgets(line, sizeof(line), textFile);
                passwords[j] = parseData(line);
        }
    }
    fclose(textFile);
}

int checkPass (pass password) {
    int vogal = 0, vogaisConsecutivas = 0, consoantesConsecutivas = 0, mesmaLetra = 0, aceitavel = 0;
    char ultimaLetra = 0;
    for (int i = 0; i < (int)strlen(password.pass); i++) {
        if (password.pass[i] == 'a' || password.pass[i] == 'e' || password.pass[i] == 'i' || password.pass[i] == 'o' || password.pass[i] == 'u') {
            vogal++;
            consoantesConsecutivas = 0;
            vogaisConsecutivas++;
        } else {
            vogaisConsecutivas = 0;
            consoantesConsecutivas++;
        }
        if (ultimaLetra == password.pass[i]) {
            mesmaLetra = 1;
        } else {
            ultimaLetra = password.pass[i];
        }
        if (consoantesConsecutivas == 3 || vogaisConsecutivas == 3) {
            aceitavel = 1;
        }
        printf("letra %i, aceitavel %i\n", i, aceitavel);
    }
    if (mesmaLetra == 1 || vogal == 0) {
        aceitavel = 1;
    }
    return aceitavel;
}
int main() {
    int i, aceitavel = 0;
    i = checkStructs("data.txt");
    pass passwords[i];
    readPass(passwords, "data.txt", i);
    for (int j = 0; j < i; j++) {
        aceitavel = checkPass(passwords[j]);
        if (aceitavel == 1)
            printf("%d isn't acceptable\n", passwords[j].userNumber);
    }
    return 0;
}
