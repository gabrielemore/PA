#include <stdlib.h>
#include <stdio.h>

int f(int a, int b)
{
    if (b == 0)
        return a;
    else
        return f(b, a % b);
}

int main()
{
    printf("%d", f(15, 10));
    return EXIT_SUCCESS;
}