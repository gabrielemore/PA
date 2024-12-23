/*  TE 5/07/2019
    ES.3 Tipi opachi
*/
#ifndef CHAR_QUEQUE_H
#define CHAR_QUEQUE_H

typedef struct CharQueque cq;

cq * makeCharQueque(int);
void insert(cq*,char);
char get(cq*);
char* toString(cq*);
void elimina(cq*);

#endif