/*  TE 07/02/2023
    ES.1 FUNZIONE IN C  
*/
#include <stdlib.h>
#include <stdio.h>

int sum_product_it(int *a, int *b, int size)
{
    int sum =0;
    for(int i=0;i<size;i++)
    {
        sum=sum+(a[i]*b[i]);
    }
    return sum;
}
int sum_product_ric(int *a, int *b, int size, int i)
{
    if(i==size) return 0;
    return a[i]*b[i] + sum_product_ric(a,b,size,i+1);
}
int sum_product_tail(int *a, int *b, int size, int i, int sum)
{
    if (i==size) return sum;
    sum=sum+(a[i]*b[i]);
    return sum_product_tail(a,b,size,i+1,sum);
}

int main()
{
    int a[2]={2,3};
    int b[2]={3,4};
    int size = sizeof(a)/sizeof(a[0]);
    //iterativa
    printf("sum (iterativa): %d\n", sum_product_it(a,b,size));
    //ricorsiva
    printf("sum (ricorsiva): %d\n", sum_product_ric(a,b,size,0));
    //tail recursive
    printf("sum (tail-rec): %d\n", sum_product_tail(a,b,size,0,0));
    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar(); // Aspetta che l'utente prema INVIO

    return 0;
}