#include <stdlib.h>
#include <stdio.h>

// scriviamo la print array in modo ricorsivo
// gli array li passimo come puntatori (*a)
// acceddiamo ai vari elementi del vettore
// come un normale vettore (a[indice])
void printArray(int *a, int i, int dim)
{
    // condizione di uscita funzione ricorsiva
    if (i == dim)
    {
        printf("\n");
        return;
    }
    printf("%d ", a[i]);
    printArray(a, i + 1, dim);
}

void switch_ele(int *a, int i)
{
    int app;
    app = a[i];
    a[i] = a[i + 1];
    a[i + 1] = app;
}

// il bubble sort prende il primo elemento dell'array
// e lo confronta con tutti gli elementi successivi
// appena ne incontra uno piu grand di lui effettua lo scambia
// riprende ad eseguire il confronto

void bubble_sort_it(int *a, int dim)
{
    int i = 0;
    while (i < dim)
    {
        while (i < dim - 1)
        {
            if (a[i] > a[i + 1])
            {
                switch_ele(a, i);
            }
            i++;
        }
        // riprendiamo dall'inizio a scorrere l'array
        i = 0;
        // avremo un elemento che non verrà più mosso con il bubble sort, diminuiamo quindi la dim
        dim--;
    }
}

void bubble_sort_ric_tail(int *a, int i, int dim)
{
    if (dim == 0)
        return;
    if (i == dim - 1)
        return bubble_sort_ric_tail(a, 0, dim - 1);
    if (a[i] > a[i + 1])
        switch_ele(a, i);
    return bubble_sort_ric_tail(a, i + 1, dim);
}

int main()
{
    int a[] = {-6, 7, -9, 1, 3};
    int a2[] = {-6, 7, -9, 1, 3};
    int b[] = {0, 1, 2, 3};

    // per creare un array vuoto potrei fare così
    int *a_vuoto;
    a_vuoto = (int *)malloc(0 * sizeof(int));
    // oppure anche così
    int *a_vuoto2 = NULL;
    // per verificare che sia vuoto
    if (a_vuoto2 == NULL)
        printf("array2 vuoto\n");
    // non so come verificare che sia vuoto il primo vettore
    // fare sizeof(a_vuoto) non è corretto perchè sarebbe 8 (essendo un puntatore a int)

    // per sapere qunato è grande un array
    int dim = sizeof(a) / sizeof(a[0]);

    // Test ITERATIVO
    printArray(a, 0, dim);
    bubble_sort_it(a, dim);
    printArray(a, 0, dim);

    // Test RICORSIVO
    printArray(a2, 0, dim);
    bubble_sort_ric_tail(a2, 0, dim);
    printArray(a2, 0, dim);

    printf("Premi INVIO per uscire...");
    getchar();
    return 0;
}