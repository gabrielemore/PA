/*  TE 08/01/2024
    ES.4 Smart Pointers
*/
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Persona
{
private:
    string nome;

public:
    Persona(string nome) : nome(nome)
    {
    }
    void stampaNome()
    {
        cout<< nome <<endl;
    }
    ~Persona()
    {
    }
};

int main()
{
    /**
     * Con raw pointer la  gestione della memoria viene completamente affidata all'utente.
     * Sarà necessario sia allocare la memoria che deallocarla
     */
    Persona *p = new Persona("Gabri");
    /**
     * Uno unique pointer è uno shared pointer che può appartenere a solo un oggetto. P_unique viene deallocato automaticamente alla fine del blocco
     */
    unique_ptr<Persona> smr_p(new Persona("Paolo"));
    /**
     * Uno shared pointer è uno smart pointer la cui ownership può essere condivisa da più oggetti. Il puntatore viene deallocato 
     * quando il numero di oggetti che usano il puntatore è 0.
     */
    shared_ptr<Persona> shr_p(new Persona("Miri"));
    shared_ptr<Persona> shr_p2(shr_p);

    p->stampaNome();
    smr_p.get()->stampaNome();
    shr_p.get()->stampaNome();
    shr_p2.get()->stampaNome();

    // al posto di free si usa delete in cpp
    // free(p);
    delete p;

    return 0;
}