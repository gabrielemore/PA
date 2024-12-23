#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H

typedef struct StringBuffer SB;

SB *costruttore(char *);
void accoda(SB *, SB *);
char *toString(SB *);
void cancella(SB *);

#endif