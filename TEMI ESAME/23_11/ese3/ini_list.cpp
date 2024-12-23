#include <iostream>

using namespace std;

// Initializer list permette di inizializzare i membri di una classe in modo efficiente
// prima che venga eseguito il codice del costruttore.

// In alcuni casi risulta obbligatorio come nel caso di membri costanti, membri reference(&) e
// nel caso manchi il costruttore nella classe madre

class ese1
{
    string nome; // -> posso usare initializer list oppure inizializzarlo nel costruttore ->non obbligatorio initializer list
    int &ref;    // riferimento, non puo essere null-> per forza initializer list

public:
    ese1(string n) : ref(*new int(10))
    {
        nome = n;
    }
};

class ese2
{
    ese1 m;  // stack: manca costruttore di default nella classe ese1-> per forza initializer list
    ese1 *p; // heap: puntatore puo essere null -> posso usare initializer list oppure inizializzarlo nel costruttore ->non obbligatorio initializer list
    ese1 &r; // heap: reference non puo essere null-> per forza initializer list

    const int a; // membro costante-> per forza initializer list

public:
    ese2(string n) : m(ese1(n)), p(new ese1(n)), r(*(new ese1(n))), a(5)
    {
        // m = ese1(n); ERRORE: per la presenza in ese1 di &ref
        p = new ese1(n);
        // r = *new ese1(n); ERRORE
    }
};

int main()
{
    return EXIT_SUCCESS;
}