#include <iostream>

using namespace std;

class Motore
{
    int cilindrata;

public:
    // costruttore di default
    // Motore()
    // {
    //     cilindrata = 0;
    // }
    Motore(int c)
    {
        cilindrata = c;
    }
};

class AutomobileStack
{
    Motore m; // se nella classe madre manca il costruttore di deafult --> per forza initializer list

public:
    AutomobileStack(int c) : m(20)
    {
        m = Motore(c); // Se metto solo questo ERRORE. Se ci fosse campo &ref o const in Motore questo non potrei farlo
    }
};

class AutomobilePuntatore
{
    Motore *p; // puo essere null -> posso farlo sia nel costruttore sia con initializer list
public:
    AutomobilePuntatore(int c) : p(new Motore(c))
    {
        p = new Motore(c);
    }
};

class AutomobileReference
{
    Motore &ref; // non puo essere null-> per forza initializer list
public:
    AutomobileReference(int c) : ref(*(new Motore(c)))
    {
        ref = *(new Motore(100)); // Se metto solo questo ERRORE. Se ci fosse campo &ref o const in Motore questo non potrei farlo
    }
};

int main()
{
    return EXIT_SUCCESS;
}
