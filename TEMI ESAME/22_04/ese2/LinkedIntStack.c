
#include "LinkedIntStack.h"
#include <stdlib.h>
#include <stdio.h>
// per usare bool!
#include <stdbool.h>

struct LinkedIntStack
{
    int *v;
    int numEle;
};

link *costruttore()
{
    link *ret = (link *)malloc(sizeof(link));
    ret->numEle = 0;
    ret->v = (int *)malloc(sizeof(int));
    return ret;
}

char *toString(link *ogg)
{
    if (!empty(ogg))
    {
        int len = 2 + (ogg->numEle * 11); // 11 è il numero massimo di cifre in un int + la virgola
        // alloco piu di quanto potrebbe servirmi nella pratica (worst case)
        char *s_ret = (char *)malloc(sizeof(char) * len);
        int indice = 0;
        indice += sprintf(s_ret + indice, "[");
        for (int i = 0; i < ogg->numEle; i++)
        {
            indice += sprintf(s_ret + indice, "%d", ogg->v[i]);
            if (i < ogg->numEle - 1)
                indice += sprintf(s_ret + indice, ",");
        }
        indice += sprintf(s_ret + indice, "]");
        return s_ret;
    }
    else
    {
        char *s_ret = (char *)malloc(sizeof(char) * 3);
        s_ret[0] = '[';
        s_ret[1] = ']';
        s_ret[2] = '\0';
        return s_ret;
    }
}

void push(link *ogg, int num)
{
    // uso della realloc per riallocare la memoria
    ogg->v = (int *)realloc(ogg->v, sizeof(int) * (ogg->numEle + 1));
    ogg->v[ogg->numEle] = num;
    ogg->numEle++;
}

// {
//     int *new = (int *)malloc(sizeof(int) * (ogg->numEle + 1)); // (1)
//     for (int i = 0; i < ogg->numEle; i++)                      // (2)
//     {
//         new[i] = ogg->v[i]; // (3)
//     }
//     free(ogg->v);  // (4)
//     ogg->numEle++; // (5)
//     ogg->v = new;
//     ogg->v[ogg->numEle-1] = num; // (6)
// }

int pop(link *ogg)
{
    if (empty(ogg))
    {
        printf("ERRORE: stack vuoto\n");
        return -1;
    }

    int ret = ogg->v[ogg->numEle - 1];
    ogg->numEle--;
    ogg->v = (int *)realloc(ogg->v, sizeof(int) * ogg->numEle);
    return ret;
}

void cancella(link *ogg)
{
    free(ogg->v);
    ogg->v = NULL;
    free(ogg);
}

bool empty(link *ogg)
{
    if (ogg->numEle == 0)
        return true;
    return false;
}
