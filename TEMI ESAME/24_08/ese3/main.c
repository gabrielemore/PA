#include "DescSet.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a[] = {1, 2, 3};
    int dim = sizeof(a) / sizeof(a[0]);
    DS o = costruttore(a, dim);
    stampa(o);

    int a1[] = {1, 7, 5, 7};
    int a2[] = {8, 3, 3, 1};
    int dim1 = sizeof(a1) / sizeof(a1[0]);
    int dim2 = sizeof(a2) / sizeof(a2[0]);
    DS o1 = costruttore(a1, dim1);
    DS o2 = costruttore(a2, dim2);
    DS o3 = unione(o1, o2);
    stampa(o1);
    stampa(o2);
    stampa(o3);

    cancella(o);
    cancella(o1);
    cancella(o2);
    cancella(o3);

    o = NULL;
    o1 = NULL;
    o2 = NULL;
    o3 = NULL;

    return EXIT_SUCCESS;
}