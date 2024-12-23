/*  TE 07/02/2023
    ES.3 Tipi opachi
*/
#ifndef INT_ARRAY_H
#define INT_ARRAY_H

typedef struct IntArray ia;

ia *costruttore(int *, int);
void accoda(ia *, int *, int);
char *toString(ia *);
void cancella(ia *);

#endif