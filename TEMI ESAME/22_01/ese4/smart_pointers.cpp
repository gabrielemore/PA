//============================================================================
// Fai un esempio in cui usi gli smart pointers e fai vedere la differenza
// rispetto all'uso dei raw pointers.
//============================================================================

#include <iostream>
#include <memory>

using namespace std;

class Esempio
{
public:
    void stampa()
    {
        cout << "Hello world" << endl;
    }
};

int main()
{
    unique_ptr<Esempio> smr_ptr = make_unique<Esempio>();
    // oppure (preferibile make_unique)
    unique_ptr<Esempio> smr_p(new Esempio());

    // smr_ptr = smr_p; ERRORE: è uno smart pointer UNICO

    smr_ptr->stampa();

    smr_p->stampa();

    // Non devo deallocare manualmente la memoria con smart pointers
    // dato che viene deallocata in modo automatico
    // al termine del ciclo di vita dello smartpointer

    // raw pointers
    Esempio *raw_ptr = new Esempio();

    raw_ptr->stampa();

    // devo deallocare la memoria manualmente per evitare memory leak
    // in c++ abbiamo delete (non free come in C)
    delete (raw_ptr);

    // shared pointer
    shared_ptr<Esempio> shr_ptr = make_shared<Esempio>();
    shared_ptr<Esempio> shr_ptr2 = shr_ptr; // OK: shared smart pointer
    shr_ptr->stampa();
    shr_ptr2->stampa();

    return 0;
}