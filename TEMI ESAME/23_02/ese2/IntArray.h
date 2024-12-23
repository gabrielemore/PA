#ifndef INT_ARRAY_H
#define INT_ARRAY_H

typedef struct IntArray int_a;

int_a *costruttore(int *, int);
void accoda(int_a *, int *, int);
char *toString(int_a *);
void cancella(int_a *);

#endif