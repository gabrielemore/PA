#include "vettore.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    float a[] = {2.4, 4.5};

    int dim_a = sizeof(a) / sizeof(a[0]);

    vet *v = Costruttore(dim_a, a);

    printf("vet 0: %s\n", toString(v));

    cancella(v);

    // NB: per accedere ai metodi dell'oggetto li scrivo semplicemente (non uso notazione "dot" o altre coses)

    float v1[] = {8, 12};
    float v2[] = {13, 7, 9};
    float v3[] = {0, -1.5};

    int dim1 = sizeof(v1) / sizeof(v1[0]);
    int dim2 = sizeof(v2) / sizeof(v2[0]);
    int dim3 = sizeof(v3) / sizeof(v3[0]);

    vet *vet1 = Costruttore(dim1, v1);
    vet *vet2 = Costruttore(dim2, v2);
    vet *vet3 = Costruttore(dim3, v3);

    printf("vet 1: %s\n", toString(vet1));
    printf("vet 2: %s\n", toString(vet2));
    printf("vet 3: %s\n", toString(vet3));

    vet *vet4 = somma(vet1, vet2);
    printf("vet 4 (somma 1+2): %s\n", toString(vet4));

    vet *vet5 = somma(vet1, vet3);
    printf("vet 5 (somma 1+3): %s\n", toString(vet5));

    vet *vet6 = somma(vet2, vet3);
    printf("vet 6 (somma 2+3): %s\n", toString(vet6));

    cancella(vet1);
    cancella(vet2);
    cancella(vet3);
    cancella(vet4);
    cancella(vet5);
    cancella(vet6);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}