#include <iostream>

using namespace std;

class ese1
{
public:
    string nome;
    int &ref; // reference: non puo essere null, per forza initializer list

    ese1(string n) : ref(*new int(3))
    {
        nome = n;
    }
};

class ese2
{
public:
    ese1 m;  // stack: non essendoci costruttore di default in ese1 per forza initializer list
    ese1 *p; // heap: puo essere null, posso farlo sia nel costruttore si con initializer list
    ese1 &r; // heap: non puo essere null, per forza init. list

    const int a; // campo const -> per forza initializer list

    ese2() : m("genoveffa"), r(*new ese1("gertrude")), a(10)
    {
        // m = ese1("genoveffa"); //ERRORE per la presenza di &ref in ese1
        p = new ese1("sara");
        // r = *(new ese1("gertrude")); //ERRORE
    }
};

// Initializer list permette di inizializzare i campi di una classe in modo piu efficiente prima che venga
// eseguito il codice del costruttore

// Si rende obbligatorio quando manca costruttore di default, se ho campi const, se ho &ref

int main()
{
    return EXIT_SUCCESS;
}