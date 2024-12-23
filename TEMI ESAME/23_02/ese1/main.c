#include <stdlib.h>
#include <stdio.h>

int sum_product_it(int *v1, int *v2, int dim)
{
    int prod = 0;
    for (int i = 0; i < dim; i++)
        prod += (v1[i] * v2[i]);
    return prod;
}
int sum_product_ric(int *v1, int *v2, int dim, int i)
{
    if (i == dim)
        return 0;
    else if (i < dim)
        return v1[i] * v2[i] + sum_product_ric(v1, v2, dim, i + 1);
}
int sum_product_tail(int *v1, int *v2, int dim, int i, int sum)
{
    if (i == dim)
        return sum;
    else if (i < dim)
        return sum_product_tail(v1, v2, dim, i + 1, sum + v1[i] * v2[i]);
}
int main()
{
    int a1[] = {2, 3};
    int a2[] = {3, 4};
    // ipotizzando sempre array di ugale dimensione
    int dim = sizeof(a1) / sizeof(a1[0]);

    //---ITERATIVA
    printf("IT:\t %d\n", sum_product_it(a1, a2, dim));

    //---RICORSIVA
    printf("RIC:\t %d\n", sum_product_ric(a1, a2, dim, 0));

    //---TAIL-REC
    printf("TAIL:\t %d\n", sum_product_tail(a1, a2, dim, 0, 0));

    printf("Premi un pulsante...");
    getchar();
    return 0;
}