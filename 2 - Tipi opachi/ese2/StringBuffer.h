/*  TE 11/2023
    ES.3 Tipi opachi
*/
#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H


typedef struct StringBuffer sb;

sb * costruttore(char*);
void accoda(sb*,sb*);
char *toString(sb*);
void cancella(sb*);


#endif