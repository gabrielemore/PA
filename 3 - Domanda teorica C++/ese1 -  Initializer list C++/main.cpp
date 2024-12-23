/*  TE 08/01/2024
    ES.3 Inizializer list C++
*/

#include <iostream>
using namespace std;

class Motore
{
private:
    int cilindrata;

public:
    // Motore(int cilindrata){
    //     this->cilindrata = cilindrata;
    // }
    // è piu efficiente inizializzare cilindrata con l'elenco di inizializzazione
    // del costruttore, ovvero cosi:
    Motore(int cilindrata) : cilindrata(cilindrata)
    {
    }
};

class AutomobileStack
{
private:
    Motore engine;

public:
    // Costruttore per motore sullo stack (Inizializer List)
    AutomobileStack(int cilindrata) : engine(cilindrata)
    {
        //engine = Motore(cilindrata); mancando il costruttore di default in Motore non va bene così
    }
};
// Puntatore a una porzione di memoria nell'Heap come puntatore
class AutomobilePointer
{
private:
    Motore *engine;

public:
    AutomobilePointer(Motore *m) : engine(m)
    {
        engine = m;
    }
};
// Reference ad una porzione di memoria nell'Heap
class AutomobileReference
{
private:
    Motore &engine;

public:
    AutomobileReference(Motore *m) : engine(*m)
    {
        //engine = *m; //Questo non posso farlo!!
    }
};

int main()
{

    // Automobile con motore sullo stack, passo la cilindrata desiderata
    // Posso farlo solo con initializer List
    AutomobileStack *a = new AutomobileStack(300);

    // Automobile con motore puntatore sullo Heap, posso inizializzarlo sia in Inizializer List che nel corpo del
    // costruttore siccome il puntatore può essere a NULL
    AutomobilePointer *b = new AutomobilePointer(new Motore(500));

    // Automobile con motore passatto per reference, solo con Inizialitzer List
    AutomobileReference *c = new AutomobileReference(new Motore(700));

    return 0;
}