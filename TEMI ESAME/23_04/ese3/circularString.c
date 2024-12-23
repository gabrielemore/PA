#include "circularString.h"
#include <stdlib.h>
#include <stdio.h>

struct circularString
{
    char *str;
    int dim;
    int num_giri;
};

CF *costruttore(char *s, int dim)
{
    CF *ogg = (CF *)malloc(sizeof(struct circularString));
    ogg->num_giri = 0;
    ogg->dim = dim;
    ogg->str = (char *)malloc(sizeof(char) * ogg->dim);

    for (int i = 0; i < ogg->dim + 1; i++)
    {
        ogg->str[i] = s[i];
    }
    return ogg;
}

void gira(CF *ogg)
{
    char *new_s = (char *)malloc(sizeof(char) * ogg->dim);
    new_s[0] = ogg->str[ogg->dim - 2];
    int j = 1;
    for (int i = 0; i < ogg->dim - 2; i++)
    {
        new_s[j] = ogg->str[i];
        j++;
    }
    new_s[ogg->dim - 1] = '\0';
    free(ogg->str);
    ogg->str = new_s;
    ogg->num_giri++;
}
char *toString(CF *ogg)
{
    int len = 2 + ogg->dim * 2;
    char *str_ret = (char *)malloc(sizeof(char) * len);
    int indice = 0;
    indice += sprintf(str_ret + indice, "[");
    for (int i = 0; i < ogg->dim - 1; i++)
    {
        indice += sprintf(str_ret + indice, "%c", ogg->str[i]);
        if (i < ogg->dim - 2)
            indice += sprintf(str_ret + indice, " ");
    }
    indice += sprintf(str_ret + indice, "]");
    return str_ret;
}
int n_gira(CF *ogg)
{
    return ogg->num_giri;
}
void cancella(CF *ogg)
{
    free(ogg->str);
    // ogg->str=NULL;
    free(ogg);
}