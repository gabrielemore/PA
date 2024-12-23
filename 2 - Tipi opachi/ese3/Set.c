/*  TE 08/01/2024
    ES.3 Tipi opachi
*/
#include "Set.h"
#include <stdlib.h>
#include <stdio.h>
// per utilizzare il tipo bool devi includere
#include <stdbool.h>

struct insieme
{
    int *v;
    int dim;
};

in *costruttore(int *a, int dim_a)
{
    in *i = (in *)malloc(sizeof(in));

    i->v = (int *)malloc(sizeof(int) * dim_a);
    i->dim = dim_a;

    for (int j = 0; j < i->dim; j++)
    {
        i->v[j] = a[j];
    }
    return i;
}
in *unione(in *i1, in *i2)
{
    int *i3 = (int *)malloc(sizeof(int) * (i1->dim + i2->dim));
    int dim = 0;
    for (int i = 0; i < i1->dim; i++)
    {
        i3[i] = i1->v[i];
        dim++;
    }
    for (int i = 0; i < i2->dim; i++)
    {
        if (!presente(i3, dim, i2->v[i]))
        {
            i3[dim] = i2->v[i];
            dim++;
        }
    }
    in *i_ret = costruttore(i3, dim);
    free(i3);

    return i_ret;
}
void print(in *i1)
{
    for (int i = 0; i < i1->dim; i++)
    {
        printf("%d ", i1->v[i]);
    }
    printf("\n");
}
void cancella(in *i)
{
    free(i->v);
    free(i);
}
bool presente(int *v, int dim_v, int n)
{
    bool p = false;
    int i = 0;
    while (!p && i < dim_v)
    {
        if (v[i] == n)
        {
            p = true;
        }
        i++;
    }
    return p;
}