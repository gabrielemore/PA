//============================================================================
// A cosa serve l'initializer list in C++? Fai un piccolo esempio e spiega il
// tutto tramite commenti ad un esempio di codice. Ci sono alcuni casi in cui
// il suo uso è facoltativo (mostra le alternative al caso) e invece casi in cui
// risulta essere necessario (mostra eventualmente un esempio).
//============================================================================

#include <iostream>
using namespace std;

// L'initializer list è utilizzato per inizializzare i membri di un oggetto
// o di una classe quando viene creato. Fornisce un modo più efficiente rispetto
// all'assegnazione di valori nei costruttori.
//
// Esso è sempre consigliato per motivi di efficienza e per evitare comportamenti
// indesiderati tuttavia ci sono situazioni in cui il suo uso è necessario, ad
// esempio quando si lavora con membri costanti o con classi madre senza un costruttore
// di default.

// classe Point
class Point {

public:

    int x_;
    int y_;

    // costruttore con initializer list
    Point(int x, int y) : x_(x), y_(y) {}

    // costruttore senza initializer list (FACOLTATIVO)(overloading)
    Point() {

        x_ = 0;
        y_ = 0;
    }
};

int main() {

    // utilizzo del costruttore con initializer list
	Point punto1(3, 5);

    // utilizzo del costruttore senza initializer list
	Point punto2;

    return 0;
}
