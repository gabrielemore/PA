/*  TE 01/2022
    ES.1 FUNZIONE IN C
*/
#include <stdlib.h>
#include <stdio.h>

void switch_ele(int *a, int i, int j)
{
    int c = a[i];
    a[i] = a[j];
    a[j] = c;
}
void printArray_rec(int *a, int i, int dim)
{
    if (i == dim)
    {
        printf("\n");
        return;
    }
    printf("%d ", a[i]);
    return printArray_rec(a, i + 1, dim);
}
//------------------------------------
void bubble_sort_it(int *a, int dim)
{
    int i = 0;
    while (i < dim)
    {
        while (i < dim - 1)
        {
            if (a[i] > a[i + 1])
                switch_ele(a, i, i + 1);
            i++;
        }
        i = 0;
        dim--;
    }
}
void bubble_sort_tail(int *a, int dim, int i)
{
    if (dim == 0)
        return;
    if (i == dim - 1)
        return bubble_sort_tail(a, dim - 1, 0);
    if (a[i] > a[i + 1])
        switch_ele(a, i, i + 1);
    return bubble_sort_tail(a, dim, i + 1);
}

int main()
{
    int v[5] = {-6, 7, -9, 1, 3};
    int v2[5] = {-6, 7, -9, 1, 3};
    // int v[10] = {6, 2, 4, 7, 5, 1, 9, 3, 15, 22};
    // int v[4] = {0,1,2,3};
    // int v[0];
    int dim = sizeof(v) / sizeof(v[0]);
    int *v_rec;

    //---iterativa
    printf("-----iteraitva-----\n");
    printf("- vet. originale:\n");
    printArray_rec(v, 0, dim);
    printf("- vet. ordinato:\n");
    bubble_sort_it(v, dim);
    printArray_rec(v, 0, dim);
    //---tail-ricorsiva
    printf("-----tail-ric-----\n");
    printf("- vet. originale:\n");
    printArray_rec(v2, 0, dim);
    printf("- vet. ordinato:\n");
    bubble_sort_tail(v2, dim, 0);
    printArray_rec(v2, 0, dim);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}