#include <iostream>
#include <memory>

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
    // raw pointers: gestione deallocazione memoria affidata all'untente
    AlpinistaStack *raw = new AlpinistaStack("gabriele", "more");

    // smart pointer: gli smart pointers gestiscono in automatico la gestione della memoria
    // non è necessario deallocare manualmente
    // Una volta che la variabile esce dal suo scope la memoria viene deallocata

    // shared pointer: è uno smart pointer la cui ownership puo essere condivisa
    shared_ptr<AlpinistaStack> sp_shr(new AlpinistaStack("paolo", "olivieri"));
    shared_ptr<AlpinistaStack> sp_shr2(sp_shr);

    // unique pointer: è uno shared pointer la cui ownership non puo essere condivisa
    unique_ptr<AlpinistaStack> sp(new AlpinistaStack("paolo", "olivieri"));

    //*** ...uso i puntatori... ***///

    // devo deallocare manualmente i raw pointer
    delete raw;
    // evito dangling pointer
    raw = nullptr;

    return EXIT_SUCCESS;
}