#include "StringBuffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct StringBuffer
{
    char *str;
    int dim;
};

SB *costruttore(char *s)
{
    SB *ogg = (SB *)malloc(sizeof(struct StringBuffer));
    // strcpy copia la stringa (compreso il fine stringa)
    //  i suoi campi sono due puntatori.
    //  ATTENZIONE!!: Non fa da solo la malloc quindi
    //  ogg->str è da allocare manualmente
    // ATTENZIONE: strlen NON considera il carattere terminatore!
    ogg->str = (char *)malloc(sizeof(char) * strlen(s) + 1);
    strcpy(ogg->str, s);
    ogg->dim = strlen(ogg->str);
    return ogg;
}
void accoda(SB *ogg1, SB *ogg2)
{
    ogg1->str = realloc(ogg1->str, ogg1->dim + ogg2->dim + 1);
    int j = 0;
    for (int i = ogg1->dim; i < ogg1->dim + ogg2->dim; i++)
    {
        ogg1->str[i] = ogg2->str[j];
        j++;
    }
    ogg1->str[ogg1->dim + ogg2->dim] = '\0';
    ogg1->dim = strlen(ogg1->str);
}
char *toString(SB *ogg)
{
    int indice = 0;
    char *str_ret = (char *)malloc(sizeof(char) * (ogg->dim + 3));
    indice += sprintf(indice + str_ret, "\"");
    for (int i = 0; i < ogg->dim; i++)
    {
        indice += sprintf(indice + str_ret, "%c", ogg->str[i]);
    }
    indice += sprintf(indice + str_ret, "\"");
    return str_ret;
}
void cancella(SB *ogg)
{
    free(ogg->str);
    ogg->str = NULL;
    free(ogg);
}