#include "DescSet.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct DecsSet
{
    int *vet;
    int dim;
};

void scambio(int *v, int i, int j)
{
    int app;
    app = v[i];
    v[i] = v[j];
    v[j] = app;
}

bool isPresente(int *v, int dim, int e)
{
    for (int i = 0; i < dim; i++)
    {
        if (v[i] == e)
            return true;
    }
    return false;
}

void ordinaDec(int *v, int dim)
{
    int i = 0;
    while (i < dim)
    {
        while (i < dim - 1)
        {
            if (v[i] < v[i + 1])
                scambio(v, i, i + 1);
            i++;
        }
        i = 0;
        dim--;
    }
}

DS costruttore(int *v, int dim)
{
    DS ogg = (DS)malloc(sizeof(struct DecsSet));
    ogg->vet = (int *)malloc(sizeof(int) * dim);
    ogg->dim = 0;
    // qui elimino i doppioni
    for (int i = 0; i < dim; i++)
    {
        if (!(isPresente(ogg->vet, ogg->dim, v[i])))
        {
            ogg->vet[ogg->dim] = v[i];
            ogg->dim++;
        }
    }
    // rialloco la memoria per ogg->vet per evitare sprechi nel caso ci fossero elementi doppi
    ogg->vet = realloc(ogg->vet, sizeof(int) * ogg->dim);
    // qui riordino l'array in modo decrescente
    ordinaDec(ogg->vet, ogg->dim);
    return ogg;
}
DS unione(DS ogg1, DS ogg2)
{
    DS ogg_ret = (DS)malloc(sizeof(struct DecsSet));
    ogg_ret->vet = (int *)malloc(sizeof(int) * (ogg1->dim + ogg2->dim));
    ogg_ret->dim = 0;
    // copio primo vettore senza nessun controllo
    for (int i = 0; i < ogg1->dim; i++)
    {
        ogg_ret->vet[i] = ogg1->vet[i];
        ogg_ret->dim++;
    }
    // con il secondo vettore devo controllare doppioni e infine ordinarlo completamente
    for (int i = 0; i < ogg2->dim; i++)
    {
        if (!(isPresente(ogg_ret->vet, ogg_ret->dim, ogg2->vet[i])))
        {
            ogg_ret->vet[ogg_ret->dim] = ogg2->vet[i];
            ogg_ret->dim++;
        }
    }
    // rialloco la memoria per ogg->vet per evitare sprechi nel caso ci fossero elementi doppi
    ogg_ret->vet = realloc(ogg_ret->vet, sizeof(int) * ogg_ret->dim);
    // qui riordino l'array in modo decrescente
    ordinaDec(ogg_ret->vet, ogg_ret->dim);
    return ogg_ret;
}
void stampa(DS ogg)
{
    for (int i = 0; i < ogg->dim; i++)
    {
        printf("%d\t", ogg->vet[i]);
    }
    printf("\n");
}
void cancella(DS ogg)
{
    free(ogg->vet);
    ogg->vet = NULL;
    free(ogg);
}
