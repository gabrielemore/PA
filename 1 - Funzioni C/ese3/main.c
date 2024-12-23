/*  TE 08/01/2024
    ES.1 FUNZIONE IN C
*/

#include <stdlib.h>
#include <stdio.h>

void printArray(int *a, int size)
{
    printf("Vet: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void mix_array_it(int *a, int *b, int *result, int sizeMin)
{
    for (int i = 0; i < sizeMin; i++)
    {
        if (i % 2 == 0)
            result[i] = a[i];
        if (i % 2 != 0)
            result[i] = 2 * b[i];
    }
}

int *mix_array_ric(int *a, int *b, int sizeMin, int i)
{
    if (i == sizeMin)
    {
        int *result = (int *)malloc(sizeMin * sizeof(int));
        return result;
    }
    if (i < sizeMin)
    {
        int *result = mix_array_ric(a, b, sizeMin, i + 1);
        if (i % 2 == 0)
            result[i] = a[i];
        if (i % 2 != 0)
            result[i] = 2 * b[i];
        return result;
    }
}

void mix_array_tail(int *a, int *b, int *result, int sizeMin, int i)
{
    if (i == sizeMin)
        return;
    if (i % 2 == 0)
        result[i] = a[i];
    if (i % 2 != 0)
        result[i] = 2 * b[i];
    mix_array_tail(a, b, result, sizeMin, i + 1);
}

int main()
{
    // int a[5]={0,5,9,6,7};
    // int b[8]={9,5,7,6,2,5,8,7};
    int a[8] = {8, 5, 1, 2, 9, 6, 5, 3};
    int b[7] = {8, 4, 6, 3, 2, 5, 1};

    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeB = sizeof(b) / sizeof(b[0]);
    int sizeMin = sizeA < sizeB ? sizeA : sizeB;
    // ATTENZIONE: utilizzo di malloc per dimensione "dinamica" dell'array di result. Ricorda la free
    int *result = (int *)malloc(sizeMin * sizeof(int)); // NB: la dimensione di result sarà la dimensione minima dei veottri a e b

    //-------------------------------
    //-----iterativa--------
    printf("Iterativo:\n");
    mix_array_it(a, b, result, sizeMin);
    printArray(result, sizeMin);
    free(result);
    //-----ricorsiva--------
    printf("Ricorsivo:\n");
    int *ris = mix_array_ric(a, b, sizeMin, 0);
    printArray(ris, sizeMin);
    //-----ricorsiva tail rec--------
    printf("Tail rec.:\n");
    result = (int *)malloc(sizeMin * sizeof(int));
    mix_array_tail(a, b, result, sizeMin, 0);
    printArray(result, sizeMin);
    free(result);
    //---------------------

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar(); // Aspetta che l'utente prema INVIO

    return 0;
}