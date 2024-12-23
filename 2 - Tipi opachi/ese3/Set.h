/*  TE 08/01/2024
    ES.3 Tipi opachi
*/
#include <stdbool.h>
#ifndef SET_H
#define SET_H

typedef struct insieme in;

in *costruttore(int *, int);
in *unione(in *, in *);
void print(in *);
void cancella(in *);
bool presente(int *, int, int);

#endif