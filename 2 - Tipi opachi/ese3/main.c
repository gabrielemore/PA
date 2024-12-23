/*  TE 08/01/2024
    ES.3 Tipi opachi
*/
#include "Set.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[] = {1, 2, 3};
    int dim = sizeof(vet) / sizeof(vet[0]);

    in *ins = costruttore(vet, dim);
    print(ins);

    int vet1[] = {1, 4, 5, 7};
    int dim1 = sizeof(vet1) / sizeof(vet1[0]);

    int vet2[] = {8, 4, 3, 1};
    int dim2 = sizeof(vet2) / sizeof(vet2[0]);

    in *ins1 = costruttore(vet1, dim1);
    in *ins2 = costruttore(vet2, dim2);

    print(ins1);
    print(ins2);
    in *ins3 = unione(ins2, ins);
    print(ins3);

    cancella(ins);
    cancella(ins1);
    cancella(ins2);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}
