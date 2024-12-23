#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

// Importante: lo unique pointer deve essere passato per riferimento dato che deve essere univoco (non si puo farne una copia)
void setA_sp(unique_ptr<char> &p)
{
    // p.get()[0] = 'a';
    *p = 'a';
}

void setA_raw(char *p)
{
    p[0] = 'a';
}

void setA_shr(shared_ptr<char> p)
{
    p.get()[0] = 'a';
}

int main()
{

    // Attenzione ad allocare la memoria per la stringa
    char s[] = "ciao";

    // uno unique pointer è uno shared pointer che puo appartenere ad un solo oggetto
    // alla fine del suo scope verrà deallocato in modo automatico
    unique_ptr<char> sp(new char[sizeof(strlen(s)) + 1]);
    // raw pointer devo essere io a gestire la sua deallocazione
    char *raw = new char[sizeof(strlen(s)) + 1];
    // shared pointer e uno smart pointer la cui ownership puo appartenere a piu oggetti
    // il puntatore verrà deallocato quando il numero di oggetti che detiene questo puntatore diventa zero
    shared_ptr<char> shr_p(new char[sizeof(strlen(s)) + 1]);
    shared_ptr<char> shr_p2(shr_p);

    strcpy(raw, "ciao");
    strcpy(sp.get(), "ciao");
    strcpy(shr_p.get(), "ciao");

    setA_sp(sp);
    setA_raw(raw);
    setA_shr(shr_p);

    cout << "sp: " << sp.get() << endl;
    cout << "raw: " << raw << endl;
    cout << "shr_p: " << shr_p.get() << endl;

    // NB: devo deallocare io la memoria per raw pointer
    delete raw;
    // null per evitare memory leakss
    raw = nullptr;

    return EXIT_SUCCESS;
}