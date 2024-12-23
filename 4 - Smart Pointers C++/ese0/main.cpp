// Gestione della memoria: Gli smart pointer gestiscono automaticamente l'allocazione e la deallocazione della memoria dinamica. 
// Quando un oggetto smart pointer esce dallo scope, la memoria associata viene automaticamente liberata. Al contrario, i raw pointer 
// richiedono esplicitamente l'allocazione e la deallocazione della memoria da parte del programmatore, il che può portare a errori 
// se non gestiti correttamente.

// Sicurezza: Gli smart pointer forniscono un livello aggiuntivo di sicurezza rispetto ai raw pointer. Gli smart pointer tengono 
// traccia del numero di riferimenti all'oggetto puntato e liberano automaticamente la memoria solo quando non ci sono più riferimenti 
// all'oggetto. Ciò previene i memory leaks e i dangling pointers, che sono comuni con i raw pointer.

// Sintassi semplificata: Gli smart pointer forniscono una sintassi più semplice e intuitiva rispetto ai raw pointer. Gli smart 
// pointer supportano l'operatore di dereferenziazione (*) e l'operatore di accesso ai membri (->), proprio come i raw pointer, 
// ma forniscono anche metodi aggiuntivi per la gestione della memoria, come reset(), get(), release(), operator bool(), e così via.

#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr(new int(42)); // Creo un unique_ptr per un intero

    std::cout << "Valore puntato da ptr: " << *ptr << std::endl;

    return 0; // Alla fine del blocco, la memoria associata a ptr viene automaticamente deallocata
}
