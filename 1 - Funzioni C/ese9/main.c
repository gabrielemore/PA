/*  TE 01/2021
    ES.1 FUNZIONE IN C
*/
#include <stdlib.h>
#include <stdio.h>

int trovaDimChar(int *a, int dimV)
{
    int d = 0;
    for (int i = 0; i < dimV; i++)
    {
        if (a[i] > 0 && ((a[i] + 1) % 2) == 0)
            d++;
    }
    return d;
}
//-----------------------------------------------
char *dispStringa_it(int *a, int dimV, int dimChar)
{
    char *res = (char *)malloc((dimChar + 1) * sizeof(char));
    int i_char = 0;
    for (int i = 0; i < dimV; i++)
    {
        if (a[i] > 0 && ((a[i] + 1) % 2) == 0)
        {
            res[i_char] = a[i] + '0';
            i_char++;
        }
    }
    res[i_char] = '\0';
    return res;
}

char *dispStringa_rec(int *a, int dimV, int dimChar, int i)
{
    if (i == dimV)
    {
        char *res = (char *)malloc((dimChar + 1) * sizeof(char));
        res[dimChar] = '\0';
        return res;
    }
    else
    {
        if (a[i] > 0 && ((a[i] + 1) % 2) == 0)
            dimChar++;
        char *r = dispStringa_rec(a, dimV, dimChar, i + 1);
        if (a[i] > 0 && ((a[i] + 1) % 2) == 0)
            r[dimChar-1] = a[i] + '0';
        return r;
    }
}
char * dispStringa_tail(int *a, char *r, int dimV, int dimChar, int i)
{
    if(i==dimV)
    {
        r[dimChar]='\0';
        return r;
    } 
    if(a[i] > 0 && ((a[i] + 1) % 2) == 0)
    {
         r[dimChar] = a[i] + '0';
         return dispStringa_tail(a,r,dimV,dimChar+1,i+1);
    }else
    {
        return dispStringa_tail(a,r,dimV,dimChar,i+1);
    }
}

int main()
{
    int a[5] = {-6, 1, 3, 2, 9};
    //int a[4] = {0, 0, 0, 10};
    //int a[2] = {1,3};

    int dimV = sizeof(a) / sizeof(a[0]);
    int dimChar = trovaDimChar(a, dimV);
    char *res_it;
    char *res_rec;
    char *res_tail=(char *)malloc((dimChar+1)*sizeof(char));

    //---iterativo
    res_it = dispStringa_it(a, dimV, dimChar);
    printf("%s\n", res_it);
    //---ricorsivo
    res_rec = dispStringa_rec(a, dimV,0, 0);
    printf("%s\n", res_rec);
    //---tail-rec
    res_tail = dispStringa_tail(a,res_tail,dimV,0, 0);
    printf("%s\n", res_tail);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}