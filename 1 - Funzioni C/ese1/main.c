/*  TE 05/04/2023
    ES.1 FUNZIONE IN C  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mix_strings(const char *A, const char *B, char *result) {
    // Determina la lunghezza minima tra A e B
    int min_length = strlen(A) < strlen(B) ? strlen(A) : strlen(B);
    
    // Itera fino alla lunghezza minima
    for (int i = 0; i < min_length; ++i) {
        // Aggiungi un carattere da A e uno da B alternati
        result[2 * i] = A[i];
        result[2 * i + 1] = B[i];
    }
    
    // Aggiungi il terminatore di stringa
    result[2 * min_length] = '\0';
}
char *mixStringRecursive(char *A, char *B, int i, int len){       
    if(i==len)
    {
        char *res=(char *)malloc(2*len*sizeof(char));
        res[2*len]='\0';
        return res;
    }else
    {
        char *r= mixStringRecursive(A,B,i+1,len);
        r[2*i]=A[i];
        r[2*i+1]=B[i];
        return r;
    }
}
void mixStringTailRecursive(char *A, char *B, char *result, int i, int len) {
    if (i < len) {
        result[2*i] = A[i];
        result[2*i + 1] = B[i];
        mixStringTailRecursive(A, B, result, i + 1, len); // Chiamata ricorsiva
    } else {
        // Aggiungi il terminatore di stringa
        result[2 * len] = '\0';
    }
}

int main() {
    char A[] = "cane";
    char B[] = "nero";
    char result[100];
    char result_tail[100];
    char *result_rec;

    int min_length = strlen(A) < strlen(B) ? strlen(A):strlen(B);
    
    //------------iterativo----------------
    mix_strings(A, B, result);
    printf("Risultato (iterativo): %s\n", result);
    //-------------ricorsivo---------------
    result_rec=mixStringRecursive(A, B,0,min_length);
    printf("Risultato (ricorsivo): %s\n", result_rec);
    //-----------ricorsivo tail recursion--
    mixStringTailRecursive(A, B, result_tail,0,min_length);
    printf("Risultato (tail-rec): %s\n", result_tail);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar(); // Aspetta che l'utente prema INVIO
    
    return 0;
}
