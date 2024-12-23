#include <iostream>

using namespace std;

class Zaino
{
    int peso;

public:
    Zaino(int p)
    {
        peso = p;
    }
    virtual ~Zaino()
    {
        peso = 0;
    }
};

class AlpinistaStack
{
    string nome;
    string cognome;
    Zaino z; // stack: se manca il costruttore di default nella classe zaino allora per forza devo utilizzare initializer list.
             // Alrimenti, se ci fosse il costruttore di default, dato che Zaino non ha campi const o &ref potrei farlo anche nel costruttore
public:
    AlpinistaStack(string n, string c) : z(Zaino(10))
    {
        nome = n;
        cognome = c;
    }
    virtual ~AlpinistaStack()
    {
    }
};

class AlpinistaHeap
{
    string nome;
    string cognome;
    Zaino *z; // Heap: puntatore puo essere Null. Posso utilizzare sia initializer list che farlo nel costruttore

public:
    AlpinistaHeap(string n, string c) : z(new Zaino(10))
    {
        nome = n;
        cognome = c;
        z = new Zaino(100);
    }
    virtual ~AlpinistaHeap()
    {
        delete z;
        z = nullptr;
    }
};

class AlpinistaRef
{
    string nome;
    string cognome;
    Zaino &z; // heap: ref non puo essere Null. Devo per forza utilizzare initializer list

public:
    AlpinistaRef(string n, string c) : z(*(new Zaino(10)))
    {
        nome = n;
        cognome = c;
    }
    virtual ~AlpinistaRef()
    {
    }
};

// eventuali parametri const della classe devono essere inizializzati con initializer list

int main()
{
    return EXIT_SUCCESS;
}