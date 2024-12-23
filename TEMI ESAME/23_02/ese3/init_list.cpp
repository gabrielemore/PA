#include <iostream>

using namespace std;

class Esempio
{
    string nome;
    int &e; // reference: non puo essere null, per forza initializer list

public:
    // Esempio() : e(*new int(29))
    // {
    //     nome = "";
    // }
    Esempio(string n) : e(*new int(29))
    {
        nome = n;
    }
};

class Esempio2
{
    Esempio m;  // stack: non esiste un deafult constructor in Persona -> per forza initializer list
    Esempio *p; // heap: può essere null. Posso sia farlo con initializer list che all'interno del costruttore madre
    Esempio &r; // heap: non puo essere null -> per forza initializer list

    const int e; // campo const-> per forza initializer list

public:
    Esempio2(string nome) : m(nome), p(new Esempio(nome)), r(*(new Esempio(nome))), e(2)
    {
        // m = Esempio("elena"); // Errore perche persona ha un campo &ref (anche se esistesse un costruttore di default)
        p = new Esempio("chiara");
        // r = *(new Esempio("genoveffa")); // Errore
    }
};

// L'initializer list utilizzato per inizializzare i membri di un oggetto
// o di una classe quando viene creato.
// In generale più efficente utilizzare initializer list

// Risulta obbligatorio quando non ho costruttore di default nella classe madre
// o ho campi riferimento (&) che non possono essere null oppure ho campi const

int main()
{
    return EXIT_SUCCESS;
}