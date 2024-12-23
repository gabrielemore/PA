#include <stdlib.h>
#include <stdio.h>

void printArray(int *a, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int *mix_array_it(int *a1, int *a2, int dim)
{
    int *a_ret = (int *)malloc(sizeof(int) * dim);
    for (int i = 0; i < dim; i += 2)
    {
        a_ret[i] = a1[i];
        a_ret[i + 1] = 2 * a2[i + 1];
    }
    return a_ret;
}
int *mix_array_ric(int *a1, int *a2, int dim, int i)
{
    if (!(i < dim))
    {
        int *a_ret = (int *)malloc(sizeof(int) * dim);
        return a_ret;
    }
    else
    {
        int *a_ret = mix_array_ric(a1, a2, dim, i + 2);
        a_ret[i] = a1[i];
        a_ret[i + 1] = 2 * a2[i + 1];
        return a_ret;
    }
}

int *mix_array_tail(int *a1, int *a2, int dim, int i, int *ret)
{
    if (!(i < dim))
    {
        return ret;
    }
    else
    {
        ret[i] = a1[i];
        ret[i + 1] = 2 * a2[i + 1];
        return mix_array_tail(a1, a2, dim, i + 2, ret);
    }
}

int *mix_array_tail_base(int *a1, int *a2, int dim, int i)
{
    int *a_ret = (int *)malloc(sizeof(int) * dim);
    return mix_array_tail(a1, a2, dim, i, a_ret);
}

int main()
{
    // int a1[] = {0, 5, 9, 6, 7};
    // int a2[] = {9, 5, 7, 6, 2, 5, 8, 7};

    int a1[] = {8, 5, 1, 2, 9, 6, 5, 3};
    int a2[] = {8, 4, 6, 3, 2, 5, 1};

    // int a1[] = {1, 2, 3, 6, 8, 9};
    // int a2[] = {5, 6};

    int *a;

    int dim1 = sizeof(a1) / sizeof(a1[0]);
    int dim2 = sizeof(a2) / sizeof(a2[0]);

    int dimMin = dim1 < dim2 ? dim1 : dim2;

    //---ITERATIVA
    a = mix_array_it(a1, a2, dimMin);
    printf("IT:\t");
    printArray(a, dimMin);
    free(a);

    //---RICORSIVA
    a = mix_array_ric(a1, a2, dimMin, 0);
    printf("RIC:\t");
    printArray(a, dimMin);
    free(a);

    // //---TAIL
    a = mix_array_tail_base(a1, a2, dimMin, 0);
    printf("TAIL:\t");
    printArray(a, dimMin);
    free(a);

    return EXIT_SUCCESS;
}