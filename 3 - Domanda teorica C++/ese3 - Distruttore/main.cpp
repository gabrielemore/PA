// Un distruttore in C++ è un metodo speciale di una classe che viene chiamato automaticamente quando un oggetto di quella classe viene distrutto. 
// Il suo scopo principale è quello di rilasciare risorse allocate dall'oggetto, come memoria dinamica, 
// file aperti o altre risorse esterne. È utile per pulire e deallocare le risorse prima che l'oggetto venga eliminato dalla memoria.



// I distuttori in C++ sono chiamati in ordine inverso rispetto a costruttori (prima
// quelli della classe Derivata poi quello della classe base).
// Se si prevede che una certa classe possa essere utilizzata come classe base, è bene
// dichiarare il suo distruttore come virtual: in questo modo i distruttori di tutte
// le classi che ereditano da essa conterranno un’invocazione implicita del distruttore
// della classe base. Ciò garantisce una corretta deallocazione di tutte le risorse che un
// oggetto potrebbe aver acquisito.

#include <iostream>

// Classe base
class Base {
public:
    Base() {
        std::cout << "Costruttore Base" << std::endl;
    }

    // Distruttore virtuale
    virtual ~Base() {
        std::cout << "Distruttore Base" << std::endl;
    }
};

// Il distruttore della classe Base è definito come virtuale (virtual ~Base()). Ciò significa che quando una classe ha ereditarietà, 
// se si utilizza un puntatore della classe base per gestire un oggetto della classe derivata, la distruzione dell'oggetto chiamerà 
// prima il distruttore della classe derivata e poi quello della classe base. Questo è noto come "distruzione polimorfica" ed è utile 
// quando si utilizzano puntatori alla classe base per gestire oggetti delle classi derivate.

// Classe derivata
class Derivata : public Base {
public:
    Derivata() {
        std::cout << "Costruttore Derivata" << std::endl;
    }

    ~Derivata() {
        std::cout << "Distruttore Derivata" << std::endl;
    }
};

int main() {
    {
        Base* ptr = new Derivata(); // Puntatore alla classe base che punta a un oggetto della classe derivata
        delete ptr; // Distrugge l'oggetto
    }
    return 0;
}
