#include "Set.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a1[] = {1, 2, 3, 3};
    int a2[] = {1, 4, 5, 7, 7};
    int a3[] = {8, 4, 3, 1};

    int dim1 = sizeof(a1) / sizeof(a1[0]);
    int dim2 = sizeof(a2) / sizeof(a2[0]);
    int dim3 = sizeof(a3) / sizeof(a3[0]);

    set *ogg1 = costruttore(a1, dim1);
    set *ogg2 = costruttore(a2, dim2);
    set *ogg3 = costruttore(a3, dim3);

    print(ogg1);

    set *ogg4 = unione(ogg2, ogg3);
    print(ogg4);

    cancella(ogg1);
    cancella(ogg2);
    cancella(ogg3);
    cancella(ogg4);

    return EXIT_SUCCESS;
}