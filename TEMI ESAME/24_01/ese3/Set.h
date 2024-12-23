#ifndef SET_H
#define SET_H

typedef struct SET set;

set *costruttore(int *, int);
set *unione(set *, set *);
void print(set *);
void cancella(set *);

#endif