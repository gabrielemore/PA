//============================================================================
// A cosa serve l'initializer list in C++? Fai un piccolo esempio e spiega il
// tutto tramite commenti ad un esempio di codice. Ci sono alcuni casi in cui
// il suo uso è facoltativo (mostra le alternative al caso) e invece casi in cui
// risulta essere necessario (mostra eventualmente un esempio).
//============================================================================

// L'initializer list è utilizzato per inizializzare i membri di un oggetto
// o di una classe quando viene creato. Fornisce un modo più efficiente rispetto
// all'assegnazione di valori nei costruttori.
//
// Esso è sempre consigliato per motivi di efficienza e per evitare comportamenti
// indesiderati tuttavia ci sono situazioni in cui il suo uso è necessario, ad
// esempio quando si lavora con membri costanti o con classi madre senza un costruttore
// di default.

#include <string>
#include <iostream>

using namespace std;

class Madre
{
    string n;
    int &ref; // essendo ref non può essere inizializzata nel costruttore-> per forza initializer

public:
    // NB: in madre non ho un costruttore di default, ovvero manca Madre()
    Madre(string nome) : ref(*(new int(10)))
    {
        n = nome;
    }
};

class Famiglia
{

    Madre m;  // Stack: senza costruttore di deafault in Madre per forza necessito di utilizzare initializer list
    Madre *p; // Heap: puo essere null, non necessita initializer list, posso farlo in entrambi i modi
    Madre &r; // heap: non puo essere null, necessita initializer list

    const int e; // essendo const non può essere inizializzata nel costruttore-> per forza initializer

public:
    Famiglia(string nomeMadre, string nomePadre) : m(nomeMadre), p(new Madre("elena")), r(*(new Madre("sara"))), e(5)
    {
        // m = Madre("chiara"); // ERRORE perchè madre ha un campo &
        p = new Madre("elena");
        // r = *new Madre("sara"); // ERRORE
    }
};

int main()
{
    Madre test = Madre("rebe");
    Madre *test2 = new Madre("rebe");
    Madre &test3 = *new Madre("rebe");
}