#include <stdio.h>

/** non-elegant way **/

/** void main () {
    int segundosEntrada = 0, horas = 0, minutos = 0;
    scanf("%i", &segundosEntrada);
    if (segundosEntrada > 3600) {
        horas = segundosEntrada / 3600;
        segundosEntrada -= horas * 3600;
    }
    if (segundosEntrada > 60) {
        minutos = segundosEntrada / 60;
        segundosEntrada -= minutos * 60;
    }
    printf("%i horas, %i minutos e %i segundos\n", horas, minutos, segundosEntrada);
} **/

/** elegant way **/

void main () {
    int segundos = 0;
    scanf("%i", &segundos);
    printf("%i horas, %i minutos e %i segundos\n", (segundos / 3600), ((segundos % 3600) / 60), (segundos % 60));
}