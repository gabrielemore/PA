/*  TE 02/2022
    ES.3 Tipi opachi
*/
#ifndef MATRICE_H
#define MATRICE_H

typedef struct matrice m;

m *costruttore(int);
char *toString(m *);
void set(m *, int, int, int);
m *somma(m *, m *);
void cancella(m *);

#endif