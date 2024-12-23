//============================================================================
// Fai un esempio in cui hai un dangling pointer e non ti accorgi
// per un po' e poi ti accorgi che il puntatore non è piu' valido.
// Commenta il codice.
//============================================================================

#include <iostream>

#include <memory> // per puntatori

using namespace std;

// Un dangling pointer è un puntatore che fa riferimento a una zona di memoria
// che è stata deallocata o che non è più valida. Questo può accadere quando il
// puntatore non viene correttamente aggiornato dopo la deallocazione della memoria
// a cui puntava o quando la memoria a cui il puntatore fa riferimento è stata liberata.

// classe Esempio
class Esempio {

public:

    void stampa() {

        cout << "Esempio!" << endl;
    }
};

int main() {

	Esempio* ptr = new Esempio(); // alloca un oggetto dinamicamente

	ptr -> stampa(); // stampa

	delete ptr; // dealloca l'oggetto, ma il puntatore non è stato posto a nullptr

	// ptr = nullptr; // imposta il puntatore a nullptr per evitare il dangling pointer

	// dopo un po'...

	// cerco di chiamare una funzione sull'oggetto puntato da ptr
	// senza accorgermi che è un dangling pointer

	ptr -> stampa(); // qui abbiamo un dangling pointer

	// per evitare i dangling pointer, devo impostare il puntatore a nullptr
	// dopo la deallocazione della memoria (riga 34 commentata)

	return 0;
}
