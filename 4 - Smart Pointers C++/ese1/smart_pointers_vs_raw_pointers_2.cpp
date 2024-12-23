//============================================================================
// Fai un esempio di una funzione setA che prende una string S (come puntatore
// a char) e setta la prima lettera di S a 'A'. Fai una versione setA con i
// puntatori raw (char*) e tutte quelle che riesci con i puntatori smart.
// Fai poi un main in cui chiami tutte le funzioni con stringhe di prova.
//============================================================================

#include <iostream>

#include <memory> // per puntatori
#include <cstring> // per strcpy

using namespace std;

// setA con puntatori raw
void setA(char *s){

	*s = 'A'; // in alternativa s[0] = 'A';
}

// setA con puntatori smart
void setA(unique_ptr<char[]>& s){ // attenzione al &

	s[0] = 'A';
}

int main() {

	// Puntatori raw
	char raw[] = "Esempio";
	setA(raw);
	cout << "Puntatore raw: " << raw << endl;

	// Puntatori smart
	unique_ptr<char[]> smart(new char[6]);

	strcpy(smart.get(), "Esempio"); // copia la stringa Esempio nel puntatore smart

	setA(smart);
	cout << "Puntatore smart: " << smart.get() << endl;

	return 0;
}
