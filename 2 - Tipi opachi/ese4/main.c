/*  TE 5/07/2019
    ES.3 Tipi opachi
*/
#include "CharQueque.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    cq *c = makeCharQueque(5);

    printf("get() : %c\n", get(c));

    insert(c, 'g');
    insert(c, 'p');
    printf("gp : %s\n", toString(c));

    printf("get() g : %c\n", get(c));

    printf("p : %s\n", toString(c));

    insert(c, 'a');
    insert(c, 'o');
    insert(c, 'l');
    insert(c, 'o');

    printf("paolo : %s\n", toString(c));

    printf("get() p : %c\n", get(c));
    printf("get() a : %c\n", get(c));

    printf("olo : %s\n", toString(c));

    insert(c, 'g');
    insert(c, 'a');
    insert(c, 'b');
    insert(c, 'r');

    printf("ologa : %s\n", toString(c));

    elimina(c);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}