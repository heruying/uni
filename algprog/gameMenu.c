#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
char leOpcao();

int main() {
  char op;
  char filename[100];
  do{
    menu();
    op = leOpcao();
    switch(op) {
      case 'n':
      case 'N':
        printf("Iniciando um novo jogo!!\n");
      break;
      case 's':
      case 'S':
        printf("Digite o nome do arquivo com o jogo a carregar: ");
        scanf("%s",filename);
        printf("Carregando o jogo salvo no arquivo %s!\n", strcat(filename,".txt"));
      break;
      case 'p':
      case 'P':
        printf("Pausando jogo. Progresso salvo em arquivo pausa.bin.\n");
      break;
      case 'e':
      case 'E':
        printf("Buscando os recordes registrados...\n");
      break;
      case 'q':
      case 'Q':
        printf("Ateh mais!!\n");
      break;
      default:
        printf("Ops! Opcao invalida! \n");
    }
  } while(op!= 'q' && op!='Q');
  return 0;
}

void menu() {
  printf(" ~~ Random Crazy Sokoban ~~\n\n\n\nSelecione:\n[N] Novo Jogo;\n[S] Salvar jogo;\n[P] Pausar jogo;\n[E] Escores (top 10);\n[Q] Quit/Sair\n\n");
}

char leOpcao() {
  char opcao;
  do {
    __fpurge(stdin);
    scanf("%c", &opcao);
  } while (opcao != 'N' && opcao != 'n' && opcao != 'S' && opcao != 's' && opcao != 'P' && opcao != 'p' && opcao != 'E' && opcao != 'e' && opcao != 'Q' && opcao != 'q');
  return opcao;
}
