#include <stdio.h>
#include <math.h>

void main() {
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double distancia;
    printf("Digite, de forma ordenada e dando enter entre cada entrada, x1, y1, x2, y2: \n");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    printf("%.02f", distancia);
}
