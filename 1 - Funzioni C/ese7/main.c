/*  TE 02/2021
    ES.1 FUNZIONE IN C  
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printArray(int *a, int dim)
{
    for(int i=0;i<dim;i++)
    {
        printf("%d ",a[i]);
    }
}

int stoipos_it(char *s, int *a)
{
    int dim=0;
    for(int i=0;i<strlen(s);i++)
    {
        //non so fare il cast da stringa ad intero quindi ragiono con il valore
        //ASCII. Nemmeno questo lo ricordo a memoria ma basta fare una prova print per 
        //vedere in che range si trovano i caratteri da 0 a 9 (48-57). In realtà non serve 
        //nemmeno saperlo, vedi la soluzione "in alternativa"
        if((int)s[i]>48 && (int)s[i]<58)
        {
            //il cast esplicito non è necessario
            a[dim] = ((int)s[i])-48;
            //in alternativa :
            //a[dim] = s[i] - '0';
            dim++;
        }
    }
    return dim;
}
int stoipos_rec(char *s, int *a, int i, int dim)
{
    if(i==strlen(s))
    {
        return 0;
    }
    else
    {
        if((int)s[i]>48 && (int)s[i]<58)
        {
            a[dim] = ((int)s[i])-48;
            return 1 + stoipos_rec(s,a,i+1,dim+1);
        }
        return 0 + stoipos_rec(s,a,i+1,dim);
    }
}
int stoipos_tail(char *s, int *a, int i, int dim)
{
    if(i==strlen(s)) return dim;
    if((int)s[i]>48 && (int)s[i]<58)
    {
        a[dim] = ((int)s[i])-48;
        return stoipos_tail(s,a,i+1, dim+1);
    }
    return stoipos_tail(s,a,i+1,dim); 
}
//NB: le funzioni sopra ritornano tutte la dimenisone reale dell'array di interi, ovvero il numero di
//interi presenti nella stringa di input. Questa dimensione servirà alla funzione di stampa
int main()
{
    char s[]="a0m19io07";
    //char s[]="anna";
    //char s[]="1200";

    //alloco almeno un numero lungo quanto la stringa s (worst case: in s sono tutti numeri >0) 
    //di celle contenenti degli interi 
    int *a = (int *)malloc((sizeof(s)-1)*sizeof(int));
    int dim=0;

    //--iterativa
    printf("iterativa:\n");
    dim=stoipos_it(s,a);
    printArray(a,dim);
    printf("\n");
    free(a);

    //--ricorsiva
    int *b = (int *)malloc((sizeof(s)-1)*sizeof(int));
    dim=0;
    
    printf("ricorsiva:\n");
    dim=stoipos_rec(s,b,0,0);
    printArray(b,dim);
    printf("\n");
    free(b);

    //--tail-rec
    int *c = (int *)malloc((sizeof(s)-1)*sizeof(int));
    dim=0;

    printf("tail-recursive:\n");
    dim=stoipos_tail(s,c,0,0);
    printArray(c,dim);
    printf("\n");
    free(c);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}