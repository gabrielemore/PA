#include "circularString.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char s[] = "pippo";
    int dim = sizeof(s) / sizeof(s[0]);
    CF *ogg = costruttore(s, dim);
    char *s_print;

    s_print = toString(ogg);
    printf("#Giri: %d\t Stringa: %s\n", n_gira(ogg), s_print);
    free(s_print);

    gira(ogg);
    s_print = toString(ogg);
    printf("#Giri: %d\t Stringa: %s\n", n_gira(ogg), s_print);
    free(s_print);

    gira(ogg);
    s_print = toString(ogg);
    printf("#Giri: %d\t Stringa: %s\n", n_gira(ogg), s_print);
    free(s_print);

    cancella(ogg);
    ogg = NULL;
    s_print = NULL;

    getchar();
    return EXIT_SUCCESS;
}