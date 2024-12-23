//============================================================================
// Scrivi una funzione che prende un puntatore ad una classe Point (che ha
// solo x e y), lo stampa ed azzera sia la x che la y. Scrivi due versioni:
// una con un raw pointer ed una con uno smart pointer di tua scelta (motiva
// la scelta). Fai un main con qualche esempio.
//============================================================================

#include <iostream>

#include <memory> // per puntatori

using namespace std;

// classe Point
class Point {

public:

    int x_;
    int y_;

    Point(int x, int y) : x_(x), y_(y) {} // initializer list
};

// Puntatore raw
void stampaEdAzzeraPoint(Point* ptr) {

    // stampa
    cout << "Coordinate: x =" << ptr -> x_ << ", y =" << ptr -> y_ << endl;

    // azzera
    ptr -> x_ = 0;
    ptr -> y_ = 0;
}

// Puntatore smart (unique_ptr scelto per la sua efficienza)
void stampaEdAzzeraPoint(unique_ptr<Point>& ptr) {

    cout << "Coordinate: x =" << ptr -> x_ << ", y =" << ptr -> y_ << endl;

    ptr -> x_ = 0;
    ptr -> y_ = 0;
}

int main() {

	// raw
	Point raw(3, 4);
	stampaEdAzzeraPoint(&raw); // attenzione &

	cout << "Coordinate dopo la funzione (raw): x =" << raw.x_
			<< ", y =" << raw.y_ << endl;

	// smart
	unique_ptr<Point> smart = make_unique<Point>(7, 8);
	stampaEdAzzeraPoint(smart);

	cout << "Coordinate dopo la funzione (smart): x =" << smart -> x_
			<< ", y =" << smart -> y_ << endl;

	return 0;
}
