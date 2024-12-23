#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *mixString_it(char *s1, char *s2, int dimMin)
{
    int newLen = (dimMin - 1) * 2 + 1;
    char *s_ret = (char *)malloc(sizeof(char) * newLen);
    int j = 0;
    for (int i = 0; i < dimMin; i++)
    {
        s_ret[j] = s1[i];
        s_ret[j + 1] = s2[i];
        j += 2;
    }
    s_ret[newLen - 1] = '\0';
    return s_ret;
}

char *mixString_rec(char *s1, char *s2, int dimMin, int i, int j)
{
    if (i == dimMin - 1)
    {
        int newLen = (dimMin - 1) * 2 + 1;
        char *s_ret = (char *)malloc(sizeof(char) * newLen);
        s_ret[newLen - 1] = '\0';
        return s_ret;
    }
    else if (i < dimMin)
    {
        char *s_ret = mixString_rec(s1, s2, dimMin, i + 1, j + 2);
        s_ret[j] = s1[i];
        s_ret[j + 1] = s2[i];
        return s_ret;
    }
}

char *mixString_rec_tail(char *s1, char *s2, int dimMin, int i, int j, char *s_ret)
{
    if (i == dimMin - 1)
    {
        return s_ret;
    }
    else if (i < dimMin)
    {
        s_ret[j] = s1[i];
        s_ret[j + 1] = s2[i];
        return mixString_rec_tail(s1, s2, dimMin, i + 1, j + 2, s_ret);
    }
}

char *mixString_rec_tail_base(char *s1, char *s2, int dimMin, int i, int j)
{
    int newLen = (dimMin - 1) * 2 + 1;
    char *s_ret = (char *)malloc(sizeof(char) * newLen);
    s_ret[newLen - 1] = '\0';
    return mixString_rec_tail(s1, s2, dimMin, 0, 0, s_ret);
}

int main()
{
    // char s1[] = "cane";
    // char s2[] = "nero";

    char s1[] = "ciao";
    char s2[] = "marianna";

    int dim1 = sizeof(s1) / sizeof(s1[0]);
    int dim2 = sizeof(s2) / sizeof(s2[0]);

    int dimMin = dim1 < dim2 ? dim1 : dim2;

    //---ITERATIVA
    printf("IT:\t %s\n", mixString_it(s1, s2, dimMin));

    //---RICORSIVA
    printf("RIC:\t %s\n", mixString_rec(s1, s2, dimMin, 0, 0));
    //---TAIL
    printf("TAIL:\t %s\n", mixString_rec_tail_base(s1, s2, dimMin, 0, 0));

    return EXIT_SUCCESS;
}