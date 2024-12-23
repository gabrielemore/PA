/*  TE 05/04/2023
    ES.3 Tipi opachi
*/
#ifndef CIRCULAR_STRING_H
#define CIRCULAR_STRING_H

//volendo per evitare di riportarsi dietro struct CircularString si poteva fare typedef struct CircularString cs e utilizzare da qui in poi cs
struct CircularString;

//quindi questo sarebbe cs * costruttore(char*)
struct CircularString *costruttore(char *);

//NB: non mettere variabili nelle funzioni, metti solamente il tipo di dato del parametro
void gira(struct CircularString *);

char *toString(struct CircularString *);

int n_gira(struct CircularString *);

void cancella(struct CircularString *);

#endif