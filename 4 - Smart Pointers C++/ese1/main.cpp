/*  TE 05/04/2023
    ES.4 Smart Pointers
*/
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

void setA(char *str)
{
    str[0] = 'A';
    cout << str << endl;
}
// per mantenere l'unicità del puntatore devi passare per riferimento lo smart pointer
void setA_ref(unique_ptr<char> &ptr)
{
    char *s = ptr.get();
    setA(s);
}
// altrimenti puoi utilizzare move() nel main e trasferire lo smart pointer alla funzione (nb: non sarà piu presente nel main)
void setA_val(unique_ptr<char> ptr)
{
    char *s = ptr.get();
    setA(s);
}
int main()
{
    char i[] = "ciao";
    //char *s = (char *)malloc(sizeof(char) * strlen(i) + 1);
    char* s = new char[sizeof(strlen(i))+1];

    // devo utilizzare un array di char
    unique_ptr<char> ptr_s(new char[strlen(i) + 1]);
    // Non devo deallocarlo io, verrà deallocato in automatico
    strcpy(s, i);
    strcpy(ptr_s.get(), i);

    setA(s);

    // passo direttamente un puntatore raw alla funzione setA
    setA(ptr_s.get());
    // passo l'oggetto puntatore
    setA_ref(ptr_s);
    //spedisco lo smart puntatore alla funzione. Dopo questo punto il puntatore muore nella funzione 
    setA_val(move(ptr_s));

    free(s);
    return 0;
}