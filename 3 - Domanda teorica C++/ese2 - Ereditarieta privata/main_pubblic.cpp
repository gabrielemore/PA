// Nell'ereditarietà pubblica, i membri pubblici e protetti della classe base diventano membri pubblici della classe derivata, 
// mentre i membri privati della classe base non sono accessibili direttamente dalla classe derivata. 
// Questo significa che i membri pubblici della classe base possono essere utilizzati senza restrizioni dalla classe derivata e dai suoi oggetti.
#include <iostream>

// Classe base
class Veicolo {
public:
    void avvia() {
        std::cout << "Il veicolo è stato avviato." << std::endl;
    }
};

// Classe derivata pubblica
class Automobile : public Veicolo {
public:
    void guida() {
        std::cout << "L'automobile è in movimento." << std::endl;
    }
};

int main() {
    Automobile auto1;
    auto1.avvia(); // OK, il metodo della classe base è accessibile
    auto1.guida(); // OK, il metodo della classe derivata è accessibile
    return 0;
}



