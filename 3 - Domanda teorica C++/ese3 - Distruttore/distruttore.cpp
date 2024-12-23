//============================================================================
// A cosa serve un distruttore in C++ e quando viene chiamato? E' consigliato
// definirlo virtuale e perchè? Spiega il tutto tramite commenti in un esempio
// di codice.
//============================================================================

#include <iostream>
using namespace std;

// Il distruttore è il metodo duale del costruttore ed ha il compito di
// deallocare risorse allocate dinamicamente prima che l'oggetto di una
// determinata classe venga distrutto.
//
// La necessità di definire un distruttore virtuale si presenta quando
// si ha una classe madre e classi figlie. Se un oggetto di una classe
// figlia viene distrutto attraverso un puntatore alla classe madre, e il
// distruttore della classe madre non è virtuale, allora solo il distruttore
// della classe madre verrà chiamato. Ciò può portare a comportamenti indesiderati,
// in quanto le risorse della classe figlia potrebbero non essere liberate correttamente.
//
// Infine, la chiamata del distruttore è duale di quella del costruttore ovvero:
// il costruttore chiama prima la classe madre e poi la classe figlia, il distruttore
// chiama prima la classe figlia e poi la classe madre.

class Madre {

public:

	Madre() {
        cout << "Costruttore Madre" << endl;
    }

    virtual ~Madre() {
        cout << "Distruttore Madre" << endl;
    }
};

class Figlia : public Madre {

public:

	Figlia() {
        cout << "Costruttore Figlia" << endl;
    }

    ~Figlia() override {
        cout << "Distruttore Figlia" << endl;
    }
};

int main() {

	// creo un oggetto Figlia e assegno il puntatore a un puntatore Madre
	Madre* obj = new Figlia();

	// chiama il distruttore Figlia grazie alla virtualità del distruttore in Madre
	delete obj;

	return 0;
}
