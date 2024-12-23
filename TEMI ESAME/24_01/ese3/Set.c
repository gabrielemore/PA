#include "Set.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct SET
{
    int *v;
    int dim;
};

bool isPresente(int *v, int dim, int ele)
{
    for (int i = 0; i < dim; i++)
    {
        if (v[i] == ele)
            return true;
    }
    return false;
}

set *costruttore(int *v, int dim)
{
    set *ogg = (set *)malloc(sizeof(struct SET));
    ogg->v = (int *)malloc(sizeof(int) * dim);
    int j = 0;
    for (int i = 0; i < dim; i++)
    {
        if (!isPresente(ogg->v, j, v[i]))
        {
            ogg->v[j] = v[i];
            j++;
        }
    }
    ogg->v = realloc(ogg->v, j);
    ogg->dim = j;
}

set *unione(set *ogg1, set *ogg2)
{
    set *ogg_ret = (set *)malloc(sizeof(struct SET));
    ogg_ret->v = (int *)malloc(sizeof(int) * (ogg1->dim + ogg2->dim));
    int j = 0;
    for (int i = 0; i < ogg1->dim; i++)
    {
        ogg_ret->v[j] = ogg1->v[i];
        j++;
    }
    for (int i = 0; i < ogg2->dim; i++)
    {
        if (!isPresente(ogg_ret->v, j, ogg2->v[i]))
        {
            ogg_ret->v[j] = ogg2->v[i];
            j++;
        }
    }
    ogg_ret->v = realloc(ogg_ret->v, j);
    ogg_ret->dim = j;
}
void print(set *ogg)
{
    for (int i = 0; i < ogg->dim; i++)
    {
        printf("%d ", ogg->v[i]);
    }
    printf("\n");
}
void cancella(set *ogg)
{
    free(ogg->v);
    ogg->v = NULL;
    free(ogg);
}