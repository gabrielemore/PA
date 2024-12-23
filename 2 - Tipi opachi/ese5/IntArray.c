/*  TE 07/02/2023
    ES.3 Tipi opachi
*/
#include "IntArray.h"
#include <stdlib.h>
#include <stdio.h>

struct IntArray
{
    int *a;
    int dim;
};

ia *costruttore(int *v, int dim)
{
    ia *r = (ia *)malloc(sizeof(ia));
    r->dim = dim;
    r->a = (int *)malloc(sizeof(int) * dim);
    for (int i = 0; i < dim; i++)
    {
        r->a[i] = v[i];
    }

    return r;
}
void accoda(ia *x, int *y, int dim_y)
{
    int k=0;
    int n_dim = x->dim + dim_y;
    int *n_vet = (int *)malloc(sizeof(int) * n_dim);
    for (int i = 0; i < x->dim; i++)
        n_vet[i] = x->a[i];
    for (int j = x->dim; j < n_dim; j++)
    {
        n_vet[j] = y[k];
        k++;
    }     
    //libero l'array a
    free(x->a);
    //assegno al puntatore appena liberato l'indirizzo del nuovo array
    x->a = n_vet;
    x->dim=n_dim;
}
char *toString(ia *x)
{
    int j=0;
    char *ret = (char *)malloc(sizeof(char) * (2 * x->dim + 2));
    ret[0] = '{';
    for (int i = 1; i < 2 * x->dim; i += 2)
    {
        // conversione intero-->carattere assumendo caratteri da 0 a 9
        ret[i] = (char)(x->a[j] + '0');
        ret[i + 1] = ',';
        j++;
    }
    ret[2 * x->dim] = '}';
    ret[2 * x->dim + 1] = '\0';
    return ret;
}
void cancella(ia *x)
{
    free(x->a);
    free(x);
}