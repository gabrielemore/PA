#ifndef VETTORE_H
#define VETTORE_H

// si definisce la struttura
typedef struct Vettore vet;

// si definiscono i metodi (non si implementano)

// lavorando su una struct i metodi che ritornano vet sono tutti dei puntatori
// meglio infatti usare i puntatori che puntano ad un oggetto piuttosto che l'oggetto intero

vet *Costruttore(int, float *);
// vet Costruttore(int, float[]);

// ritorna un array di caratteri(una stringa)
char *toString(vet *);

vet *somma(vet *, vet *);

// servirà a distruggere e liberare spazio in memoria
void cancella(vet *);

#endif