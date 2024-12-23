//============================================================================
// Che differenza c'è tra ereditarietà pubblica e privata in C++? Spiegalo
// per bene con un esempio ben commentato.
//============================================================================

#include <iostream>
using namespace std;

// Ereditarietà pubblica: i membri pubblici della classe madre diventano membri
// pubblici della classe figlia, i membri protetti diventano membri protetti,
// e i membri privati non sono ereditati.
//
// Ereditarietà privata: i membri pubblici e protetti della classe madre diventano
// membri privati della classe figlia.

// classe madre
class Madre {

public:
    void publicF() {
        cout << "Membro pubblico della classe madre" << endl;
    }

protected:
    void protectedF() {
        cout << "Membro protetto della classe madre" << endl;
    }

private:
    void privateF() {
        cout << "Membro privato della classe madre" << endl;
    }
};

// classe figlia con ereditarietà pubblica
class FigliaPubblica : public Madre {

public:
    void utilizzaMadre() {
    	publicF();  // ok, membro pubblico ereditato
    	protectedF();  // ok, membro protetto ereditato
        // privateF();  // errore, membro privato non accessibile
    }
};

// Classe figlia con ereditarietà privata
class FigliaPrivata : private Madre {

public:
    void utilizzaMadre() {
    	publicF();  // ok, membro pubblico diventa privato nella classe figlia
    	protectedF();  // ok, membro protetto diventa privato nella classe figlia
        // privateF();  // errore, membro privato non accessibile
    }
};

int main() {

    cout << "Ereditarietà Pubblica:" << endl;
    FigliaPubblica pub;
    pub.utilizzaMadre();

    cout << "\nEreditarietà Privata:" << endl;
    FigliaPrivata pri;
    // pri.utilizzaMadre();  // errore, membri non accessibili dalla classe figlia

    return 0;
}

