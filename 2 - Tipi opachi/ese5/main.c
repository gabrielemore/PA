/*  TE 07/02/2023
    ES.3 Tipi opachi
*/
#include "IntArray.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{ 
    //assuemendo interi da 0 a 9
    int vet[] = {1, 2, 3};
    int vet2[] = {4, 5, 6};
    int dim_v = sizeof(vet) / sizeof(vet[0]);
    int dim_v2 = sizeof(vet2) / sizeof(vet2[0]);

    ia *i = costruttore(vet, dim_v);
    printf("toString: %s\n", toString(i));

    accoda(i, vet2, dim_v2);

    printf("toString: %s\n", toString(i));

    cancella(i);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}