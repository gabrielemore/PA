/*  TE 11/2023
    ES.1 FUNZIONE IN C  
*/
#include <stdlib.h>
#include <stdio.h>

int count_gt_it(int *a, int *b, int s_a, int s_b)
{
    int count =0;
    for(int i=0;i<s_a;i++)
    {
        if(i<s_b)
        {
            if(a[i]>b[i]) count++;
        }   
        else
        {
            if(a[i]>0) count++;
        }     
    }
    return count;
}
int count_gt_ric(int *a, int *b, int i,int s_a, int s_b)
{
    int count=0;
    if(i<s_a)
    {
        if(i<s_b)
        {
            if(a[i]>b[i]) count++;
        }   
        else
        {
            if(a[i]>0) count++;
        } 
    }else
    {
        return 0;
    }
    //ATTENTO: se fai i++ l'incremento viene effettuato DOPO la chiamata della funzione. Devi fare ++i.
    return count + count_gt_ric(a,b,++i,s_a,s_b);
}

int count_gt_tail(int *a, int *b, int i, int s_a, int s_b, int tot)
{
    if(i<s_a)
    {
        if(i<s_b)
        {
            if(a[i]>b[i]) tot++;
        }   
        else
        {
            if(a[i]>0) tot++;
        } 
        return count_gt_tail(a,b,++i,s_a,s_b,tot);
    }else
    {
        return tot;
    }
}

int main()
{
    int a[5]={2,3,4,5,-2};
    int b[2]={3,1};
    //ricavare la dimensione di un array
    int s_a = sizeof(a)/sizeof(a[0]);
    int s_b = sizeof(b)/sizeof(b[0]);

    //--------------iterativo---------------
    printf("Ris (iter): %d\n",count_gt_it(a,b,s_a,s_b) );
    //--------------ricorsivo---------------
    printf("Ris (ric): %d\n",count_gt_ric(a,b,0,s_a,s_b));
    //---------ricorsivo tail recursion--------
    printf("Ris (tail): %d\n",count_gt_tail(a,b,0,s_a,s_b,0));
    
    
    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar(); // Aspetta che l'utente prema INVIO
    return 0;

}