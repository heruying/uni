#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int buscaBinaria (int *vetor, int tamVetor, int valor, int limInf, int limSup) {
    int pivot = (limInf + limSup) / 2;
    if (vetor[pivot] == valor) {
        return pivot;
    } else if (limSup - limInf == 0) {
        return -1;
    } else if (vetor[pivot] < valor) {
        buscaBinaria(vetor, tamVetor, valor, ++pivot, limSup);
    } else {
        buscaBinaria(vetor, tamVetor, valor, limInf, --pivot);
    }
}

/*
    Essa função também poderia ser usada para facilitar a chamada.
*/

int chamaBuscaBinaria (int *vetor, int valor) {
    buscaBinaria(vetor, sizeof(vetor) / sizeof(vetor[0]), valor, 0, sizeof(vetor) / sizeof(vetor[0]) - 1);
}

int main() {
   int valor;
   int vetor[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
   int i;
   int posicao;
   printf("Digite um numero: ");
   scanf("%d", &valor);

   //chamar a funcao de busca binaria, armazenando seu retorno em 'posicao'
   posicao = buscaBinaria(vetor, sizeof(vetor) / sizeof(vetor[0]), valor, 0, sizeof(vetor) / sizeof(vetor[0]) - 1);
   printf("Vetor: ");
   for (i=0; i<MAX; i++)
       printf("%d  ",vetor[i]);
   printf("\n\n");
   if (posicao == -1) {
       printf("O numero nao foi encontrado no vetor\n");
   }
   else {
       printf("Numero encontrado na posicao : %d\n",posicao+1);
   }
   return 0;
}
