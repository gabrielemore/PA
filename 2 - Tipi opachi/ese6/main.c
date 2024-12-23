/*  TE 02/2022
    ES.3 Tipi opachi
*/
#include "Matrice.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    m *mat1 = costruttore(2);
    m *mat2 = costruttore(2);
    printf("matrice: %s\n", toString(mat1));
    printf("matrice: %s\n", toString(mat2));

    set(mat1, 1, 1, 2);
    set(mat1, 1, 2, 2);

    set(mat2, 1, 1, 1);
    set(mat2, 1, 2, 1);

    printf("matrice: %s\n", toString(mat1));
    printf("matrice: %s\n", toString(mat2));

    m *mat3 = somma(mat1, mat2);
    printf("matrice: %s\n", toString(mat3));

    cancella(mat1);
    cancella(mat2);
    cancella(mat3);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}