#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int arg;
    if (argc == 2) {
        arg = atoi(argv[1]);
    } else {
        arg = 20;
    }
    printf("argc = %i, argv = %i\n", argc, arg);
}
