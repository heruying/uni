#include "bibFuncionarios.h"

int main() {
    char opcao;
    struct tipo_funcionario funcionario;
    int codigo, achou;
    printf("[N]ovo funcionário\n[P]rocurar funcionário\n[A]tualizar funcionário\n");
    do {
        __fpurge(stdin);
        scanf("%c", &opcao);
    } while (opcao != 'N' && opcao != 'n' && opcao != 'P' && opcao != 'p' && opcao != 'A' && opcao != 'a');
    switch (opcao) {
        case 'N':
        case 'n':
            appendFuncionario(leFuncionario());
        break;
        case 'P':
        case 'p':
            codigo = leCodigo();
            achou = achaFuncionario(codigo, &funcionario);
            if (achou == 0) {
                imprimeFuncionario(funcionario);
            } else {
                printf("Funcionário não encontrado;\n");
            }
        break;
        case 'A':
        case 'a':
            codigo = leCodigo();
            achou = achaFuncionario(codigo, &funcionario);
            if (achou == 0) {
                atualizaFuncionario(&funcionario);
                atualizaBinario(funcionario);
            } else {
                printf("Funcionário não encontrado;\n");
            }
        break;
    }
}
