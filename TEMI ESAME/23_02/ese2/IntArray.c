#include "IntArray.h"
#include <stdlib.h>
#include <stdio.h>

struct IntArray
{
    int *v;
    int numEle;
};

int_a *costruttore(int *a, int dim)
{
    int_a *ogg = (int_a *)malloc(sizeof(struct IntArray));
    ogg->v = (int *)malloc(sizeof(int) * dim);
    ogg->numEle = dim;

    for (int i = 0; i < dim; i++)
    {
        ogg->v[i] = a[i];
    }

    return ogg;
}

void accoda(int_a *ogg1, int *v2, int dim)
{
    // La realloc funziona in questo modo:

    // realloc(puntatore alla memoria, nuova dimensione in memoria da riservare)

    // Restituisce un nuovo puntatore (dato che non è detto riesca ad aggiungere nuove celle
    // alla zona di memoria di ogg1, potrebbe spostarsi da un altra parte se non le trova libere)

    // NB: la dimensione della memoria è in Byte quindi devi fare sizeof()*n
    // NB2: la dimensione non viene sommata a quella precedente! Devi inserire quella
    // che vuoi in totale senza considerare la memoria che avevi precedentemente allocato
    // NB3: si occupa in automatico di spostare (eventualmente) il contenuto delle celle di memoria riservate
    // dal puntatore ogg1
    int *v1 = realloc(ogg1->v, sizeof(int) * (ogg1->numEle + dim));
    ogg1->v = v1;
    // Copio solo il contenuto del secondo vettore nel nuovo oggetto
    // (per il primo ci ha pensato la realloc)
    // ho bisogno di un secondo indice
    int j = ogg1->numEle;
    for (int i = 0; i < dim; i++)
    {
        ogg1->v[j] = v2[i];
        j++;
    }
    ogg1->numEle = ogg1->numEle + dim;
}

char *toString(int_a *ogg)
{
    int indice = 0;
    int len = ogg->numEle * 11 + 2;
    char *str = (char *)malloc(sizeof(char) * len);
    indice += sprintf(indice + str, "{");
    for (int i = 0; i < ogg->numEle; i++)
    {
        indice += sprintf(indice + str, "%d", ogg->v[i]);
        if (i < ogg->numEle - 1)
            indice += sprintf(indice + str, ",");
    }
    indice += sprintf(indice + str, "}");
    return str;
}

void cancella(int_a *ogg)
{
    free(ogg->v);
    ogg->v = NULL;
    free(ogg);
}