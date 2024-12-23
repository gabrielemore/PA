#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int distanza_it(char *s1, char *s2, int dim1, int dim2)
{
    int sum = 0;
    // aggiungo subito i 100 per ogni eventuale carattere mancante
    sum += abs(dim1 - dim2) * 100;
    int dimMin = dim1 > dim2 ? dim2 : dim1;
    for (int i = 0; i < dimMin; i++)
    {
        if (s1[i] < 'a')
            s1[i] = s1[i] + ('a' - 'A');
        if (s2[i] < 'a')
            s2[i] = s2[i] + ('a' - 'A');
        sum += abs(s1[i] - s2[i]);
    }
    return sum;
}

int distanza_ric(char *s1, char *s2, int dim1, int dim2, int i)
{
    if (dim1 == dim2)
    {
        if (i == dim1)
            return 0;
        else if (i < dim1)
        {
            if (s1[i] < 'a')
                s1[i] = s1[i] + ('a' - 'A');
            if (s2[i] < 'a')
                s2[i] = s2[i] + ('a' - 'A');
            return distanza_ric(s1, s2, dim1, dim2, i + 1) + abs(s1[i] - s2[i]);
        }
    }
    else if (dim1 < dim2)
    {
        if (i == dim1)
            return abs(dim1 - dim2) * 100;
        else if (i < dim1)
        {
            if (s1[i] < 'a')
                s1[i] = s1[i] + ('a' - 'A');
            if (s2[i] < 'a')
                s2[i] = s2[i] + ('a' - 'A');
            return distanza_ric(s1, s2, dim1, dim2, i + 1) + abs(s1[i] - s2[i]);
        }
    }
    else
    {
        if (i == dim2)
            return abs(dim1 - dim2) * 100;
        else if (i < dim2)
        {
            if (s1[i] < 'a')
                s1[i] = s1[i] + ('a' - 'A');
            if (s2[i] < 'a')
                s2[i] = s2[i] + ('a' - 'A');
            return distanza_ric(s1, s2, dim1, dim2, i + 1) + abs(s1[i] - s2[i]);
        }
    }
}

int distanza_ric_tail(char *s1, char *s2, int dim1, int dim2, int i, int sum)
{
    if (dim1 == dim2)
    {
        if (i == dim1)
            return sum;
        else if (i < dim1)
        {
            if (s1[i] < 'a')
                s1[i] = s1[i] + ('a' - 'A');
            if (s2[i] < 'a')
                s2[i] = s2[i] + ('a' - 'A');
            return distanza_ric_tail(s1, s2, dim1, dim2, i + 1, sum + abs(s1[i] - s2[i]));
        }
    }
    else if (dim1 < dim2)
    {
        if (i == dim1)
            return sum + abs(dim1 - dim2) * 100;
        else if (i < dim1)
        {
            if (s1[i] < 'a')
                s1[i] = s1[i] + ('a' - 'A');
            if (s2[i] < 'a')
                s2[i] = s2[i] + ('a' - 'A');
            return distanza_ric_tail(s1, s2, dim1, dim2, i + 1, sum + abs(s1[i] - s2[i]));
        }
    }
    else
    {
        if (i == dim2)
            return sum + abs(dim1 - dim2) * 100;
        else if (i < dim2)
        {
            if (s1[i] < 'a')
                s1[i] = s1[i] + ('a' - 'A');
            if (s2[i] < 'a')
                s2[i] = s2[i] + ('a' - 'A');
            return distanza_ric_tail(s1, s2, dim1, dim2, i + 1, sum + abs(s1[i] - s2[i]));
        }
    }
}

int main()
{
    // char s1[] = {'a','b','c'};
    // char s2[] = {'a'};
    // oppure più velocemente posso dichiararle così
    // cosi vengono memorizzate nello stack e gestite in automatico dal compilatore
    // quando le var escono dallo scope vengono deallocate
    char s1[] = "aA";
    char s2[] = "";
    // o anche così con allocazione dinamica nello heap
    // char *ss1 = malloc(4 * sizeof(char)); // Allocazione dinamica per 4 caratteri (3 per "abc" + 1 per '\0')
    // strcpy(ss1, "abc");

    // NB:questo dim considera anche il carattere terminatore
    int dim1 = sizeof(s1) / sizeof(s1[0]);
    int dim2 = sizeof(s2) / sizeof(s2[0]);

    // ITERATIVA
    printf("IT:\t%d\n", distanza_it(s1, s2, dim1 - 1, dim2 - 1));

    // RICORSIVA
    printf("RIC:\t%d\n", distanza_ric(s1, s2, dim1 - 1, dim2 - 1, 0));

    // TAIL-REC
    printf("TAIL:\t%d\n", distanza_ric_tail(s1, s2, dim1 - 1, dim2 - 1, 0, 0));

    // non si deve fare la free se dichiarate come vettori
    // free(s1);
    // lo avrei dovuto usare per ss1 avendo usato la malloc
    // free(ss1);

    getchar();
    printf("Premi un carattere per terminare\n");
    return 0;
}