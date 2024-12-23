#include "IntArray.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int vet[] = {1, 2, 3};
    int vet2[] = {4, 5, 6};
    int_a *ese = costruttore(vet, 3);

    char *s = NULL;

    s = toString(ese);
    printf("stampa: %s\n", s);

    accoda(ese, vet2, 3);
    s = toString(ese);
    printf("stampa: %s\n", s);

    free(s);
    cancella(ese);
    s = NULL;
    ese = NULL;

    printf("Premi un carattere..");
    getchar();
    return 0;
}