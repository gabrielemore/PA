//NB: l'inserimento e rimozione era da fare in testa! non ho voglia di rifarlo.

#include "LinkedIntStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    link *ogg = costruttore();

    char *s = toString(ogg);
    printf("Stack iniziale:\t %s\n", s);
    free(s);

    push(ogg, 10);
    s = toString(ogg);
    printf("Stack:\t %s\n", toString(ogg));
    free(s);

    push(ogg, 5);
    s = toString(ogg);
    printf("Stack:\t %s\n", toString(ogg));
    free(s);

    int numPop = pop(ogg);
    printf("Num pop:\t %d\n", numPop);
    s = toString(ogg);
    printf("Stack:\t %s\n", toString(ogg));
    free(s);

    numPop = pop(ogg);
    printf("Num pop:\t %d\n", numPop);
    s = toString(ogg);
    printf("Stack:\t %s\n", toString(ogg));
    free(s);

    numPop = pop(ogg);
    printf("Num pop:\t %d\n", numPop);
    s = toString(ogg);
    printf("Stack:\t %s\n", toString(ogg));
    free(s);

    cancella(ogg);
    ogg = NULL;
    s = NULL;

    printf("Premi un pulsante\n");
    getchar();
    return 0;
}