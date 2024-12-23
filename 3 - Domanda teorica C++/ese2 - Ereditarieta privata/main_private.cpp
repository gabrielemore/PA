// Nell'ereditarietà privata, i membri pubblici e protetti della classe base diventano membri privati della classe derivata.
// Questo significa che i membri pubblici e protetti della classe base non sono direttamente accessibili dalla classe derivata e dai suoi oggetti. 
// L'accesso ai membri della classe base avviene attraverso i metodi pubblici della classe derivata.
#include <iostream>

// Classe base
class Veicolo {
public:
    void avvia() {
        std::cout << "Il veicolo è stato avviato." << std::endl;
    }
};

// Classe derivata privata
class Automobile : private Veicolo {
public:
    void guida() {
        std::cout << "L'automobile è in movimento." << std::endl;
    }

    void avviaVeicolo() {
        avvia(); // Accesso al metodo della classe base tramite un metodo pubblico della classe derivata
    }
};

int main() {
    Automobile auto1;
    auto1.guida(); // OK, il metodo della classe derivata è accessibile

    //qui sotto dovrebbe dare errore, provare ad eseguire
    auto1.avviaVeicolo(); // OK, il metodo pubblico della classe derivata accede al metodo della classe base
    // auto1.avvia(); // Errore! Il metodo della classe base non è direttamente accessibile dalla classe derivata
    return 0;
}