#include <stdlib.h>
#include <stdio.h>

int F(int N);

int main()
{
    printf("%d", F(3));
    return EXIT_SUCCESS;
}

int F(int N)
{
    if (N <= 0)
        return 5;
    else
        return F(N - 1) + F(N - 3);
}