#include <iostream>
#include <memory>

using namespace std;

class Persona
{
private:
    string nome;

public:
    Persona(string n)
    {
        nome = n;
    }
    // virtual tilde Persona()
    string getNome()
    {
        return nome;
    }
};

int main()
{
    // raw pointer: gestione memoria affidata all'utente che deve deallocare la memoria manualmente
    Persona *raw = new Persona("pippo");

    // smart pointer: gestione memoria automatica. Non serve che sia l'utente a deallocare la memoria
    // una volta uscito dallo scope la memoria viene deallocata in automatico

    // unique pointer è uno shared pointer la cui ownership non è condivisa
    // nb: in caso di utilizzo all'interno di funzioni il passaggio di un unique pointer deve essere
    // fatta per riferimento (&)
    unique_ptr<Persona> sp(new Persona("gabri"));

    // uno shared pointer è uno smart pointer la cui ownership può essere condivisa
    shared_ptr<Persona> shr(new Persona("paolo"));
    shared_ptr<Persona> shr2(shr);

    cout << raw->getNome() << endl;
    cout << sp->getNome() << endl;
    cout << shr2->getNome() << endl;

    // deallocazione della memoria raw pointer manuale
    delete raw;
    // evitiamo dangling pointers
    raw = nullptr;

    return EXIT_SUCCESS;
}
