//============================================================================
// Fai un esempio in cui usi gli smart pointers e fai vedere la differenza
// rispetto all'uso dei raw pointers.
//============================================================================

#include <iostream>

#include <memory> // per puntatori

using namespace std;

// classe Esempio
class Esempio {

public:

    void stampa() {

        cout << "Esempio!" << endl;
    }
};

int main() {

	// Smart pointer (std::unique_ptr)
	unique_ptr<Esempio> smartPtr = make_unique<Esempio>();

	smartPtr -> stampa(); // stampa

	// IMPORTANTE: non è necessario deallocare manualmente la memoria
	// poichè gli smart pointers si occupano automaticamente della deallocazione
	// al termine del loro ciclo di vita - non c'è bisogno di fare "delete smartPtr;"

	// Raw pointer
	Esempio* rawPtr = new Esempio();

	rawPtr -> stampa(); // stampa

	// IMPORTANTE: e' necessario deallocare manualmente la memoria
	// altrimenti si verifica una perdita di memoria (memory leak)
	delete rawPtr;

	// IMPORTANTE: per evitare i dangling pointer, devo impostare il puntatore raw
	// a nullptr dopo la deallocazione della memoria
	rawPtr = nullptr;

	return 0;
}
