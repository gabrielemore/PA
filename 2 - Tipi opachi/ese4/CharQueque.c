/*  TE 5/07/2019
    ES.3 Tipi opachi
*/
#include "CharQueque.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct CharQueque
{
    char *s;
    int pos, dim;
};

cq *makeCharQueque(int n)
{
    cq *coda = (cq *)malloc(sizeof(cq));
    coda->dim = n;
    coda->pos = -1;
    coda->s = (char *)malloc(sizeof(char) * n);
    return coda;
}
void insert(cq *coda, char c)
{
    if (coda->dim > coda->pos + 1)
    {
        coda->s[coda->pos + 1] = c;
        coda->pos++;
    }
    else
    {
        printf("Coda piena\n");
    }
}
char get(cq *coda)
{
    if (coda->pos < 0)
    {
        printf("Coda vuota\n");
        return '\0';
    }
    else
    {
        char s_ret = coda->s[0];
        for (int i = 0; i < coda->pos; i++)
        {
            coda->s[i] = coda->s[i + 1];
        }
        coda->pos--;
        return s_ret;
    }
}
char *toString(cq *coda)
{
    char *s_ret = (char *)malloc(sizeof(char) * coda->pos + 2);
    for (int i = 0; i < coda->pos + 1; i++)
    {
        s_ret[i] = coda->s[i];
    }
    s_ret[coda->pos + 1] = '\0';
    return s_ret;
}
void elimina(cq *coda)
{
    free(coda->s);
    free(coda);
}