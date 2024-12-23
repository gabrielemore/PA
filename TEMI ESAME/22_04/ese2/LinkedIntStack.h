#ifndef LINKED_INT_STACK_H
#define LINKED_INT_STACK_H
#include <stdbool.h>

typedef struct LinkedIntStack link;

link *costruttore();
char *toString(link *);
void push(link *, int);
int pop(link *);
bool empty(link *);
void cancella(link *);

#endif