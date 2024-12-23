#include "StringBuffer.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[] = "ciao";
    char s2[] = "mariopatato";

    SB *ogg = costruttore(s);
    SB *ogg2 = costruttore(s2);

    char *s_print;

    s_print = toString(ogg);
    printf("%s\n", s_print);
    free(s_print);

    accoda(ogg, ogg2);

    s_print = toString(ogg);
    printf("%s\n", s_print);
    free(s_print);

    s_print = NULL;

    cancella(ogg);
    cancella(ogg2);

    ogg = NULL;
    ogg2 = NULL;

    return EXIT_SUCCESS;
}