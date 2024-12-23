/*  TE 02/2022
    ES.1 FUNZIONE IN C
*/
#include <stdlib.h>
#include <stdio.h>

int count_odd_it(int *a, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0 && a[i] > 0)
            sum++;
    }
    return sum;
}
int count_odd_ric(int *a, int size, int i)
{
    if (i == size)
        return 0;
    if (i % 2 == 0 && a[i] > 0)
        return 1 + count_odd_ric(a, size, i + 1);
    else
        return 0 + count_odd_ric(a, size, i + 1);
}
int count_odd_tail(int *a, int size, int i, int sum)
{
    if (i == size)
        return sum;
    if (i % 2 == 0 && a[i] > 0)
        sum++;
    return count_odd_tail(a, size, i + 1, sum);
}

int main()
{
    int a[3] = {0, -1, 2};
    // int a[3]={1,2,-3};
    // puoi definire un array vuoto come di seguito.
    // In compilazione non da problemi nonostante visual studio ti sottolinei l'errore
    // int a[0];
    int size = sizeof(a) / sizeof(a[0]);

    //---- iterativo -----
    printf("iteraitivo: %d \n", count_odd_it(a, size));
    //---- ricorsivo -----
    printf("ricorsivo: %d \n", count_odd_ric(a, size, 0));
    //---- tail-recursive -----
    printf("tail-recursive: %d \n", count_odd_tail(a, size, 0, 0));

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}