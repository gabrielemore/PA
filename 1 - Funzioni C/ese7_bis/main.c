/*  TE 02/2021 BIS
    ES.1 FUNZIONE IN C  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *stoipos_it(char *s)
{
    //calcolo prima il numero di celle di memoria da allocare
    int dim=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>'0' && s[i]<='9') dim++;
    }
    //alloco le celle di memoria + una per il numero 'terminatore'
    int *res = (int *)malloc((dim+1)*sizeof(int));
    res[dim]=-1;
    //estraggo i numeri dalla stringa e li assegno alle celle puntate dal puntatore
    int ind=0;
    for(int i=0;i<strlen(s) && ind<dim;i++)
    {
        if(s[i]>'0' && s[i]<='9')
        {
            res[ind]=s[i] - '0';
            ind++;
        }
    }
    return res;
}

int *stoipos_rec(char *s, int i,int num)
{  
    // !!!ATTENTO: sizeof(s) restituisce la dimensione del puntatore (8 bit). NON DELLA STRINGA. devi usare strlen
    if(i==strlen(s))
    {   
        int *res = (int *)malloc((num+1)*sizeof(int));
        //in ultima posizione metto un carattere 'terminatore' per sapere quando fermarmi con la print senza dover passare la dimensione
        res[num]=-1;
        return res;
    }else
    {
        if(s[i]>'0' && s[i]<='9') num++;
        int *r=stoipos_rec(s,i+1,num);
        if(s[i]>'0' && s[i]<='9') r[num-1]=s[i]-'0';
        return r;
    }
}
int *stoipos_tail(char *s, int*res, int i,int num)
{
    if(i==strlen(s)) 
    {
        res[num]=-1;
        return res;
    }
    if(s[i]>'0' && s[i]<='9')
    {
        res[num] = s[i]-'0';
        return stoipos_tail(s,res,i+1,num+1);
    }
    return stoipos_tail(s,res,i+1,num); 
}

void printArray(int *a)
{
    int i=0;
    while(a[i]>0)
    {
        printf("%d ",a[i]);
        i++;
    }
}
int main()
{
    //char s[]="a0m19io076";
    //char s[]="anna";
    char s[]="1200a4";
    int *result_it;
    int *result_rec;
    int *result_tail;

    //---iterativo
    printf("iterativo:\n");
    result_it=stoipos_it(s);
    printArray(result_it);
    printf("\n");
    free(result_it);

    //---ricorsivo
    printf("ricorsiva:\n");
    result_rec=stoipos_rec(s,0,0);
    printArray(result_rec);
    printf("\n");
    free(result_rec);

    //---tail-rec
    //devo conoscere la dimensione da allocare in memoria: Questa cosa potrebbe essere migliorata.
    int dim=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>'0' && s[i]<='9') dim++;
    }
    int *r = (int *)malloc((dim+1)*sizeof(int));
    //---------------------------------
    printf("tail-rec:\n");
    result_tail=stoipos_tail(s,r,0,0);
    printArray(result_tail);
    printf("\n");
    free(result_tail);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0; 
}