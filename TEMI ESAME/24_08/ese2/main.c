#include <stdlib.h>
#include <stdio.h>

int f(int a, int e)
{
    if (e == 0)
        return 0;
    return a + (f(a, e - 1));
}

int main()
{

    //---ITERATIVA
    printf("RIS:\t %d\n", f(5, 3));

    return EXIT_SUCCESS;
}