#include "bibFuncionarios.h"

struct tipo_funcionario leFuncionario() {
    size_t len;
    struct tipo_funcionario novoFuncionario;
    printf("Código do funcionário: ");
    scanf("%i", &novoFuncionario.codigo);
    printf("Sexo do funcionário (M/F): ");
    __fpurge(stdin);
    scanf("%c", &novoFuncionario.sexo);
    printf("Nome do funcionário: ");
    __fpurge(stdin);
    fgets(novoFuncionario.nome, 50, stdin);
    len = strlen(novoFuncionario.nome)-1;
    if (novoFuncionario.nome[len] == '\n')
        novoFuncionario.nome[len] = '\0';
    printf("Salário do funcionário: ");
    scanf("%f", &novoFuncionario.salario);
    printf("Cargo do funcionário: ");
    __fpurge(stdin);
    fgets(novoFuncionario.cargo, 50, stdin);
    len = strlen(novoFuncionario.cargo)-1;
    if (novoFuncionario.cargo[len] == '\n')
        novoFuncionario.cargo[len] = '\0';
    printf("Idade do funcionario: ");
    scanf("%i", &novoFuncionario.idade);
    return novoFuncionario;
}

int appendFuncionario (struct tipo_funcionario funcionario) {
    FILE *stream = fopen("funcionarios.bin", "a+b");
    if (stream == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO;\n");
        return -1;
    } else {
        fwrite(&funcionario, sizeof(struct tipo_funcionario), 1, stream);
        fclose(stream);
        printf("Funcionário Cadastrado!\n");
        return 0;
    }
}

int achaFuncionario (int codigo, struct tipo_funcionario *funcionario) {
    int funcionariosSalvos;
    FILE *stream = fopen("funcionarios.bin", "rb");
    if (stream == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO;\n");
        return -2;
    } else {
        fseek(stream, 0L, SEEK_END);
        funcionariosSalvos = ftell(stream) / sizeof(struct tipo_funcionario);
        rewind(stream);
        for (int i = 0; i < funcionariosSalvos && codigo != funcionario->codigo; i++) {
            fread(funcionario, sizeof(struct tipo_funcionario), 1, stream);
        }
        fclose(stream);
        if (codigo == funcionario->codigo) {
            return 0;
        } else {
            return -1;
        }
    }
}

void atualizaFuncionario (struct tipo_funcionario *funcionario) {
    char escolha;
    do {
        printf("Deseja atualizar o cargo ou o salário [C/S]? ");
        __fpurge(stdin);
        scanf("%c", &escolha);
    } while (escolha != 'c' && escolha != 's' && escolha != 'C' && escolha != 'S');
    switch(escolha) {
        case 'c':
        case 'C':
            printf("Qual o novo cargo do funcionário? ");
            __fpurge(stdin);
            scanf("%s", funcionario->cargo);
        break;
        case 's':
        case 'S':
            do {
                printf("Qual o novo salário do funcionário? ");
                scanf("%f", &funcionario->salario);
            } while (funcionario->salario < 0);
        break;
    }
}

int atualizaBinario (struct tipo_funcionario funcionario) {
    struct tipo_funcionario funcionarioAntigo;
    FILE *stream = fopen("funcionarios.bin", "r+b");
    if (stream == NULL) {
        printf("ERRO NA ABERTURA DO ARQUIVO;\n");
        return -1;
    } else {
        do {
            fread(&funcionarioAntigo, sizeof(struct tipo_funcionario), 1, stream);
            imprimeFuncionario(funcionarioAntigo);
            imprimeFuncionario(funcionario);
        } while (funcionario.codigo != funcionarioAntigo.codigo);
        fseek(stream, -1*(sizeof(struct tipo_funcionario)), SEEK_CUR);
        fwrite(&funcionario, sizeof(struct tipo_funcionario), 1, stream);
        fclose(stream);
        return 0;
    }
}

void imprimeFuncionario(struct tipo_funcionario funcionario) {
    printf("\n Código: %d\n Nome: %s\n Sexo: %c\n Salario: %.02f\n Cargo: %s\n Idade: %i\n", funcionario.codigo, funcionario.nome, funcionario.sexo, funcionario.salario, funcionario.cargo, funcionario.idade);
    __fpurge(stdin);
    getchar();

}

int leCodigo() {
    int codigo;
    do {
        printf("Qual o código do funcionário? ");
        scanf("%d", &codigo);
    } while (codigo < 0);
    return codigo;
}
