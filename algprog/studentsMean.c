#include <stdio.h>

int main() {
    float p1, p2, ap, tf, media, mediageral, melhormediafinal = 0;
    int matricula, matriculamelhormedia, alunos, i;
    printf("Quantos alunos terao suas notas calculadas?" );
    scanf(" %d", &alunos);
    for (i = 0; i < alunos; i++) {
        printf("Insira os dados: ");
        scanf("%d %f %f %f %f", &matricula, &p1, &p2, &ap, &tf);
        media = (p1 + p2 + ap + tf) / 4;
        mediageral += media;
        if (media > melhormediafinal) {
            melhormediafinal = media;
            matriculamelhormedia = matricula;
        }
    }
    printf("Media geral da turma: %f\n", (mediageral / alunos));
    printf("Melhor media final de todos os alunos: %f, matrícula: %i\n", melhormediafinal, matriculamelhormedia);


}
