/*  TE 01/2022
    ES.3 Tipi opachi
*/
#include "vettore.h"
#include <stdlib.h>
#include <stdio.h>

struct Vettore
{
    float *vet;
    int dim;
};

vet *costruttore(int n, float *v)
{
    vet *v_ret = (vet *)malloc(sizeof(vet));
    v_ret->dim = n;
    v_ret->vet = (float *)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++)
    {
        v_ret->vet[i] = v[i];
    }
    return v_ret;
}
char *toString(vet *vet)
{
    // ipotizzando una dimensione massima (in stringa) di
    // ogni float in 5 caratteri es. 23.45 = 5 caratteri. Stiamo eventualmente allocando
    //più spazio di quanto non ne avremo bisogno
    
    // 2 = parentesi
    // (vet->dim - 1) = le virgole
    // (vet->dim * 5) = max cifre di ogni numero (considerando il punto)
    // 1 carattere terminatore stringa
    char *s_ret = (char *)malloc(sizeof(char) * (2 + (vet->dim - 1) + (vet->dim * 5) + 1));
    int indice = 0;
    // sprintf mette in s_ret la srtinga a fianco e restituisce l'indice a cui è arrivata ad inserire la stringa
    // in questo caso è 1 ma se avessimo inserito ve: sarebbe stato 3
    indice += sprintf(s_ret + indice, "(");
    // s_ret + indice indica a sprintf da dove partire ad inserire la stringa
    // in questo modo costruiamo s_ret concatendando più pezzi
    // senza il +indice sovrascriveremmo ogni volta l'inizio della stringa
    for (int i = 0; i < vet->dim; i++)
    {
        indice += sprintf(s_ret + indice, "%.2f", vet->vet[i]);
        if (i < vet->dim - 1)
            indice += sprintf(s_ret + indice, ",");
    }
    //srpintf si occupo da solo di sposare e gestire il fine stringa
    indice += sprintf(s_ret + indice, ")");
    return s_ret;
}
vet *somma(vet *v1, vet *v2)
{
    int dim = v1->dim > v2->dim ? v1->dim : v2->dim;
    vet *v_res = (vet *)malloc(sizeof(vet));
    v_res->vet = (float *)malloc(sizeof(float) * dim);
    v_res->dim = dim;
    for (int i = 0; i < dim; i++)
    {
        if (i < v1->dim && i < v2->dim)
            v_res->vet[i] = v1->vet[i] + v2->vet[i];
        else if (i >= v1->dim && i < v2->dim)
            v_res->vet[i] = v2->vet[i];
        else if (i < v1->dim && i >= v2->dim)
            v_res->vet[i] = v1->vet[i];
    }

    return v_res;
}
void cancella(vet *v)
{
    free(v->vet);
    free(v);
}