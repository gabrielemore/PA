/*  TE 5/07/2019
    ES.1 FUNZIONE IN C  
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void PrintRev(char *s, char *r)
{
    //qui dentro se fai sizeof(s) ti da la dimensione del puntatore (e non della stringa!!!)
    int i=0;
    //ATTENZIONE: il carattere terminatore deve essere tra i singoli apici per il confronto
    while(s[i]!='\0')
    {
        //se vuoi la dimensione della stringa a cui punta il puntatore s devi usare la strlen(s)
        r[i]=s[strlen(s)-i-1];
        i++;
    }
    r[strlen(s)]='\0';
    //RIORDA: il vettore parte con indice 0. strlen(s) da la dimensione. L'ultimo carattere (non nullo)
    //della stringa s è strlen(s)-1. Alla posizione strlen(s) c'è il terminatore!!
}

char * PrintRev_rec(char *s, int i)
{
    if(i==strlen(s))
    {
        char *res = (char *)malloc(sizeof(s));
        res[i]='\0';
        return res;
    }else
    {
        char * r = PrintRev_rec(s,i+1);
        r[i]=s[strlen(s)-i-1];
        return r;
    }
}

void PrintRev_tail(char *s, char *r, int i)
{
    if(s[i]!='\0')
    {
        r[i]=s[strlen(s)-i-1];
        PrintRev_tail(s,r,i+1);
    }else
    {
        r[strlen(s)]='\0';
        return;
    }
    

}

//ATTENZIONE: se fai la sizeof di un puntatore ti restituisce la dimensione del puntatore!! Se vuoi sapere
//quanto è grande la stringa puntata da quel puntatore devi usare la strlen!!!

int main()
{
    char str[] = "ciaoooooo";
    char *res = (char *)malloc(sizeof(str));

    //----iterativo-----
    PrintRev(str,res);
    printf("Iterativo:\n");
    printf("stringa originale: %s\n", str);
    printf("stringa invertita: %s\n", res);
    free(res);
    //----ricorsivo-----
    char *resRec;
    resRec=PrintRev_rec(str,0);
    printf("Ricorsivo:\n");
    printf("stringa originale: %s\n", str);
    printf("stringa invertita: %s\n", resRec);
    free(resRec);
    //----tail recursive-----
    char *resTail = (char *)malloc(sizeof(str));
    PrintRev_tail(str,resTail,0);
    printf("Tail rec:\n");
    printf("stringa originale: %s\n", str);
    printf("stringa invertita: %s\n", resTail);
    free(resTail);


    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}