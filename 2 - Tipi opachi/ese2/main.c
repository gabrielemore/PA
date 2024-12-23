/*  TE 11/2023
    ES.3 Tipi opachi
*/
#include "StringBuffer.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char s[] = "pippo";

    sb *ogg = costruttore(s);

    sb *ogg2 = costruttore("gabriele");
    sb *ogg3 = costruttore("paolo");

    printf("originale: %s\n", toString(ogg));

    accoda(ogg, ogg2);

    cancella(ogg2);

    printf("accoda: %s\n", toString(ogg));

    accoda(ogg, ogg3);

    cancella(ogg3);

    printf("accoda: %s\n", toString(ogg));

    cancella(ogg);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}