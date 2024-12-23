/*  TE 05/04/2023
    ES.3 Tipi opachi
*/
#include "CircularString.h" //NB: se il file .h è nella stessa directory del file .c devi usare le "virgolette" e non <>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CircularString
{
    char *str;
    int n_gira;
};

struct CircularString *costruttore(char *s)
{
    if (s == NULL)
        return NULL;
    //Ricordati di allocare la memoria della struttura
    struct CircularString *res = (struct CircularString *)malloc(sizeof(struct CircularString));
    if (res == NULL)
        return NULL;

    // Alloca memoria per la stringa e copia il contenuto di s
    //strdup fa una malloc + copia del contenuto di s (strcpy)
    res->str = strdup(s); //piuttosto che copiare solo il puntatore alloca la memoria e il contenuto di s!!
    if (res->str == NULL)
    {
        free(res);
        return NULL;
    }

    res->n_gira = 0;

    return res;
}

void gira(struct CircularString *a)
{
    if (a == NULL || a->str == NULL)
        return;

    int len = strlen(a->str);
    char temp = a->str[len - 1];
    for (int i = len - 1; i > 0; i--)
    {
        a->str[i] = a->str[i - 1];
    }
    a->str[0] = temp;
    a->n_gira++;
}

char *toString(struct CircularString *a)
{
    if (a == NULL || a->str == NULL)
        return NULL;

    return a->str;
}

int n_gira(struct CircularString *a)
{
    if (a == NULL)
        return -1;

    return a->n_gira;
}

void cancella(struct CircularString *a)
{
    if (a == NULL)
        return;

    // Libera la memoria allocata per la stringa e per la struttura
    free(a->str); //Ricordati di eliminare anche questa allocazione
    free(a);
}

int main()
{
    char s[] = "pippo";

    // Costruzione dell'oggetto
    struct CircularString *ogg = costruttore(s);
    if (ogg == NULL)
    {
        printf("Errore durante la creazione dell'oggetto\n");
        return 1;
    }

    // Utilizzo dell'oggetto
    printf("Stringa: %s\n", toString(ogg));
    printf("N_giri: %d\n", n_gira(ogg));
    gira(ogg);

    printf("Stringa: %s\n", toString(ogg));
    printf("N_giri: %d\n", n_gira(ogg));

    gira(ogg);

    printf("Stringa: %s\n", toString(ogg));
    printf("N_giri: %d\n", n_gira(ogg));

    gira(ogg);
    gira(ogg);

    printf("Stringa: %s\n", toString(ogg));
    printf("N_giri: %d\n", n_gira(ogg));

    // Eliminazione dell'oggetto
    cancella(ogg);

    // Attendi l'input dell'utente prima di chiudere
    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}
