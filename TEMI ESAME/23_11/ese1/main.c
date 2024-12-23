#include <stdlib.h>
#include <stdio.h>

int count_gt_it(int *a1, int *a2, int dim1, int dim2)
{
    int count = 0;
    int dimMax = dim1 > dim2 ? dim1 : dim2;
    for (int i = 0; i < dimMax; i++)
    {
        if (i < dim1 && i < dim2)
        {
            if (a1[i] > a2[i])
                count++;
        }
        else if (i < dim2)
        {
            if (0 > a2[i])
                count++;
        }
        else if (i < dim1)
        {
            if (a1[i] > 0)
                count++;
        }
    }
    return count;
}

int count_gt_rec(int *a1, int *a2, int dim1, int dim2, int i)
{
    // int dimMax = dim1 > dim2 ? dim1 : dim2;
    if (dim1 == dim2)
    {
        // dim1=dim2=dimMax
        if (i == dim1)
        {
            return 0;
        }
        else
        {
            if (a1[i] > a2[i])
                return 1 + count_gt_rec(a1, a2, dim1, dim2, i + 1);
            else
                return count_gt_rec(a1, a2, dim1, dim2, i + 1);
        }
    }
    else if (dim1 < dim2)
    {
        // dim2=dimMax
        if (i == dim2)
        {
            return 0;
        }
        else
        {
            if (i < dim1)
            {
                if (a1[i] > a2[i])
                    return 1 + count_gt_rec(a1, a2, dim1, dim2, i + 1);
                else
                    return count_gt_rec(a1, a2, dim1, dim2, i + 1);
            }
            else
            {
                if (0 > a2[i])
                    return 1 + count_gt_rec(a1, a2, dim1, dim2, i + 1);
                else
                    return count_gt_rec(a1, a2, dim1, dim2, i + 1);
            }
        }
    }
    else if (dim2 < dim1)
    {
        // dim1 = dimMax
        if (i == dim1)
        {
            return 0;
        }
        else
        {
            if (i < dim2)
            {
                if (a1[i] > a2[i])
                    return 1 + count_gt_rec(a1, a2, dim1, dim2, i + 1);
                else
                    return count_gt_rec(a1, a2, dim1, dim2, i + 1);
            }
            else
            {
                if (a1[i] > 0)
                    return 1 + count_gt_rec(a1, a2, dim1, dim2, i + 1);
                else
                    return count_gt_rec(a1, a2, dim1, dim2, i + 1);
            }
        }
    }
}

int count_gt_tail(int *a1, int *a2, int dim1, int dim2, int i, int count)
{
    // int dimMax = dim1 > dim2 ? dim1 : dim2;
    if (dim1 == dim2)
    {
        // dim1=dim2=dimMax
        if (i == dim1)
        {
            return count;
        }
        else
        {
            if (a1[i] > a2[i])
                return count_gt_tail(a1, a2, dim1, dim2, i + 1, count + 1);
            else
                return count_gt_tail(a1, a2, dim1, dim2, i + 1, count);
        }
    }
    else if (dim1 < dim2)
    {
        // dim2=dimMax
        if (i == dim2)
        {
            return count;
        }
        else
        {
            if (i < dim1)
            {
                if (a1[i] > a2[i])
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count + 1);
                else
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count);
            }
            else
            {
                if (0 > a2[i])
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count + 1);
                else
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count);
            }
        }
    }
    else if (dim2 < dim1)
    {
        // dim1 = dimMax
        if (i == dim1)
        {
            return count;
        }
        else
        {
            if (i < dim2)
            {
                if (a1[i] > a2[i])
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count + 1);
                else
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count);
            }
            else
            {
                if (a1[i] > 0)
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count + 1);
                else
                    return count_gt_tail(a1, a2, dim1, dim2, i + 1, count);
            }
        }
    }
}

int main()
{
    // int a1[] = {2, 3};
    // int a2[] = {3, 1};

    // int a1[] = {2, 3, 4};
    // int a2[] = {3, 1};

    // int a1[] = {2};
    // int a2[] = {3, 1};

    int a1[] = {2};
    int a2[] = {3, -1};

    int dim1 = sizeof(a1) / sizeof(a1[0]);
    int dim2 = sizeof(a2) / sizeof(a2[0]);

    //---ITERATIVA
    printf("IT:\t %d\n", count_gt_it(a1, a2, dim1, dim2));
    //---RICORSIVA
    printf("RIC:\t %d\n", count_gt_rec(a1, a2, dim1, dim2, 0));
    //---TAIL-REC
    printf("TAIL:\t %d\n", count_gt_tail(a1, a2, dim1, dim2, 0, 0));

    return EXIT_SUCCESS;
}