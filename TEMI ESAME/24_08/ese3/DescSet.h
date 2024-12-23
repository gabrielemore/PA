#ifndef DECS_SET_H
#define DECS_SET_H

typedef struct DecsSet *DS;

DS costruttore(int *, int);
DS unione(DS, DS);
void stampa(DS);
void cancella(DS);

#endif