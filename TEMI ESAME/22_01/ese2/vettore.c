// qui avviene l'implementazione dei metodi e la definizione della struttura dichiarta nel file .h

// per prima cosa includiamo il file .h generato
// NB: per i file .h ,ettiamo "" e non <>
#include "vettore.h"
#include <stdlib.h>
#include <stdio.h>

struct Vettore
{
    float *v;
    int dim;
};

vet *Costruttore(int dim, float *v_float)
{
    // per prima cosa dobbiamo allocare la memoria per l'oggetto Vettore
    vet *v_ret = (vet *)malloc(sizeof(vet));
    // per accedere ai campi dell'oggetto (essendo un puntatore) usiamo le frecce
    v_ret->dim = dim;
    // per il vettore v alloco spazio in memoria per dim(n) floats. Moltiplico quindi per dim
    v_ret->v = (float *)malloc(sizeof(v_float) * dim);
    for (int i = 0; i < dim; i++)
    {
        v_ret->v[i] = v_float[i];
    }
    return v_ret;
}

char *toString(vet *vet)
{
    // ipotizzando una dimensione massima (in stringa) di
    // ogni float in 5 caratteri es. 23.45 = 5 caratteri. Stiamo eventualmente allocando
    // più spazio di quanto non ne avremo bisogno

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
        indice += sprintf(s_ret + indice, "%.2f", vet->v[i]);
        if (i < vet->dim - 1)
            indice += sprintf(s_ret + indice, ",");
    }
    // srpintf si occupo da solo di spostare e gestire il fine stringa
    indice += sprintf(s_ret + indice, ")");
    return s_ret;
}

vet *somma(vet *v1, vet *v2)
{
    // la dimensione del vettore ritornato sarà la dim max tra v1 e v2
    int dim = v1->dim > v2->dim ? v1->dim : v2->dim;
    // allochiamo ora lo spazio per vet ritornato
    vet *v_ret = (vet *)malloc(sizeof(vet));
    v_ret->v = (float *)malloc(sizeof(float) * dim);
    v_ret->dim = dim;
    for (int i = 0; i < dim; i++)
    {
        if (i < v1->dim && i < v2->dim)
        {
            // caso in cui ho valori in entrambi i vettori
            v_ret->v[i] = v1->v[i] + v2->v[i]; // normale somma
        }
        else if (i >= v1->dim && i < v2->dim)
        {
            // caso in cui v1 non ha piu elementi mentre v2 si
            v_ret->v[i] = v2->v[i]; // "sommo" 0 + elemento v2
        }
        else if (i < v1->dim && i >= v2->dim)
        {
            // caso in cui v2 non ha piu elementi mentre v1 sis
            v_ret->v[i] = v1->v[i];
        }
    }

    return v_ret;
}

void cancella(vet *v)
{
    v->dim = 0;
    free(v->v);
    free(v);
}