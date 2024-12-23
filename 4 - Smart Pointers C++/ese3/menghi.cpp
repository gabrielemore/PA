// Es4
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Song{
	private:
		std::string  title;

	public:
		Song(std::string titolo){
			title=titolo;
		}
		void printname() {cout << title << endl; }
		~Song(){
			cout << "distruzione canzone" << endl;
		}
};


void UseRawPointer() {
// Utilizzo di un puntatore raw - non consigliato .
Song *pSong = new Song(" Nothing on You"); // Usa pSong ...
// Non dimenticare di eliminare !
delete pSong;
}


void UseSmartPointer() {
// Dichiara un puntatore intelligente sullo stack e // gli passa il puntatore raw.
unique_ptr<Song> song2(new Song(" Nothing on You")); // Usa song2 ...
//wstring s = song2 -> duration_;
// ...
} // song2 viene cancellata automaticamente qui.


// shared_ptr Puntatore intelligente con conteggio dei riferimenti.
//Utilizzare quando si desidera assegnare un puntatore raw a più proprietari, ad esempio, quando si restituisce
//una copia di un puntatore da un contenitore ma si desidera mantenere l’originale.

void UseSharedSmartPointer() {
// Dichiara un puntatore intelligente sullo stack e // gli passa il puntatore raw.
shared_ptr<Song> song2(new Song(" Nothing on You")); // Usa song2 ...
cout << song2.get() << endl;
shared_ptr<Song> song3(song2);
cout << song3.get() << endl;
//wstring s = song2 -> duration_;
// ...
} // song2 viene cancellata automaticamente qui.

int main() {
	cout << "UseRawPointer" << endl;
  UseRawPointer();
	cout << "UseSmartPointer" << endl;
	UseSmartPointer();
	cout << "UseSharedSmartPointer" << endl;
	UseSharedSmartPointer();
	return 0;
}
