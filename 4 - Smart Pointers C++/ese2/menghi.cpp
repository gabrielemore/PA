// Es4
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Persona {
	public:
		string name;
		Persona(string nome){
			name = nome;
		}
	void stampainfo(){
		cout<< "\n Nome della persona :" << name ;
	}
	~Persona(){
		cout << "distruzione persona" << endl;
	}
};

void UseRawPointer() {
	/**
	 * La  gestione della memoria viene completamente affidata all'utente.
	 * Sarà necessario sia allocare la memoria che deallocarla
	*/
	Persona *p_raw = new Persona();
	delete p_raw;
}


void UseSmartPointer() {
	/**
	 * Uno unique pointer è uno shared pointer che può appartenere a solo un oggetto. P_unique viene deallocato automaticamente alla fine del blocco
	*/
	unique_ptr<Persona> p_unique(new Persona());
}

void UseSharedSmartPointer() {
	/**
	 * Uno shared pointer è uno smart pointer la cui ownership può essere condivisa da più oggetti. Il puntatore viene deallocato quando il numero di oggetti che usano il puntatore è 0.
	*/
	shared_ptr<Persona> p_shared(new Persona());
	shared_ptr<Persona> p_shared2(p_shared);
} 

int main() {
	cout << "UseRawPointer" << endl;
  UseRawPointer();
	cout << "UseSmartPointer" << endl;
	UseSmartPointer();
	cout << "UseSharedSmartPointer" << endl;
	UseSharedSmartPointer();
	return 0;
}
