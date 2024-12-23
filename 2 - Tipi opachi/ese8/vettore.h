/*  TE 01/2022
    ES.3 Tipi opachi
*/
#ifndef VETTORE_H
#define VETTORE_H

typedef struct Vettore vet;

vet *costruttore(int, float *);
char *toString(vet *);
vet *somma(vet *, vet *);
void cancella(vet *);

#endif