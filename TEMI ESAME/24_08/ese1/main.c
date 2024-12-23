#include <stdlib.h>
#include <stdio.h>

// *a = riferimento locazione vettore
// dim = dimensione del vettore passata come parametro
int count_mul_3_it(int *a, int dim)
{
    int count = 0;
    for (int i = 0; i < dim; i++)
    {
        if (a[i] % 3 == 0)
            count++;
    }
    return count;
}
// *a = riferimento locazione vettore
// dim = dimensione del vettore passata come parametro
// i = indice scorrimento vettore. Nel main deve partire da 0 per scorrere l'array dal primo elemento
int count_mult_3_ric(int *a, int dim, int i)
{
    if (i == dim)
        return 0;
    if (a[i] % 3 == 0)
        return 1 + count_mult_3_ric(a, dim, i + 1);
    else
        return count_mult_3_ric(a, dim, i + 1);
}
// *a = riferimento locazione vettore
// dim = dimensione del vettore passata come parametro
// i = indice scorrimento vettore. Nel main deve partire da 0 per scorrere l'array dal primo elemento
// count = variabile contenente il numero di elementi trovati che soddisfa la condizione. Nel main deve essere inizializzata a 0
int count_mult_3_tail(int *a, int dim, int i, int count)
{
    if (i == dim)
        return count;
    if (a[i] % 3 == 0)
        return count_mult_3_tail(a, dim, i + 1, count + 1);
    else
        return count_mult_3_tail(a, dim, i + 1, count);
}

//tutte le variabili vengono passate per valore. Il vettore decade a puntatore

int main()
{
    int a[] = {99, 2, 3, 18, 5, 6, 7, 8, 9, 10};
    int dim = sizeof(a) / sizeof(a[0]);

    //---ITERATIVA
    printf("IT:\t %d\n", count_mul_3_it(a, dim));
    //---RICORSIVA
    printf("RIC:\t %d\n", count_mult_3_ric(a, dim, 0));
    //---TAIL-REC
    printf("TAIL:\t %d\n", count_mult_3_tail(a, dim, 0, 0));

    return EXIT_SUCCESS;
}