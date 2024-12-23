#ifndef CIRCULAR_STRING
#define CIRCULAR_STRING

typedef struct circularString CF;

CF *costruttore(char *,int);
void gira(CF *);
char *toString(CF *);
int n_gira(CF *);
void cancella(CF *);

#endif