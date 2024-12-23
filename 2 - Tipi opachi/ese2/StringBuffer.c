/*  TE 11/2023
    ES.3 Tipi opachi
*/
#include "StringBuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// questo lo devi chiamare per intero, non con il typedef definito in .h
struct StringBuffer
{
    char *str;
};

sb *costruttore(char *s)
{
    sb *ogg = (sb *)malloc(sizeof(sb));
    ogg->str = strdup(s);
    return ogg;
}
void accoda(sb *x, sb *y)
{
    char *n_s = (char *)malloc(strlen(x->str) + strlen(y->str) + 1);
    // al posto di questo ciclo si poteva fare uno strcpy(n_s,x->str) e successivamente una concatenzaizone strcat(n_s,y->str)
    for (int i = 0; i < strlen(x->str) + strlen(y->str); i++)
    {
        if (i < strlen((x->str)))
            n_s[i] = x->str[i];
        else
            n_s[i] = y->str[i - strlen((x->str))];
    }
    n_s[strlen(x->str) + strlen(y->str)] = '\0';
    // libero la memoria relativa alla vecchia stinga e ne assegno una nuova uguale alla stringa costruita
    free(x->str);
    // ricorda che strdup oltre a copiare la stringa alloca in modo dinamico la memoria
    x->str = strdup(n_s);
}
char *toString(sb *ogg)
{
    char *res = (char *)malloc(strlen(ogg->str) + 3);
    res[0] = '\'';
    for (int i = 0; i < strlen(ogg->str); i++)
    {
        res[i + 1] = ogg->str[i];
    }
    res[strlen(ogg->str) + 1] = '\'';
    res[strlen(ogg->str) + 2] = '\0';
    /* non sono sicuro di come queste funzioni sotto gestiscano il terminatore
    strcpy(res, "'");
    strcat(res, ogg->str);
    strcat(res, "'");
    */
    return res;
}
void cancella(sb *ogg)
{
    free(ogg->str);
    free(ogg);
}