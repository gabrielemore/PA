/*  TE 11/2023
    ES.4 Smart Pointers
*/
#include <iostream>
#include <memory>
#include <cstring>
#include <string>

using namespace std;

void raw(char *str, char *ptr)
{
    ptr = new char[(strlen(str)) + 1];
    strcpy(ptr, str);
    ptr[0] = 'A';
    cout << "Raw: " << ptr << endl;
}
void uni_ptr(char *str, unique_ptr<char> &ptr)
{
    ptr.reset(new char[(strlen(str)) + 1]);
    strcpy(ptr.get(), str);
    ptr.get()[0] = 'B';
    cout << "Uniq: " << ptr.get() << endl;
}
void shr_ptr_print(shared_ptr<char> ptr)
{
    cout << "Shared: " << ptr.get() << endl;
}
//Lo shared pointer posso passarlo per valore e posso modificarlo all'interno della funzione
// Gli shared_ptr utilizzano il conteggio dei riferimenti per gestire la memoria, copiare uno 
// shared_ptr non comporta duplicare il contenuto puntato, ma solo incrementare il conteggio dei riferimenti.
void shr_ptr(char *str, shared_ptr<char> ptr1, shared_ptr<char> ptr2)
{
    //ptr1.reset(new char[strlen(str) + 1]);
    ptr2=ptr1;
    strcpy(ptr1.get(), str);
    ptr1.get()[0] = 'C';
    shr_ptr_print(ptr1);
    shr_ptr_print(ptr2);
}

int main()
{
    char str[] = "ciao";
    char *p;
    unique_ptr<char> smr_p;
    shared_ptr<char> shr_p(new char[(strlen(str)+1)]);
    shared_ptr<char> shr_p2;

    strcpy(shr_p.get(),str);


    raw(str, p);
    uni_ptr(str, smr_p);
    shr_ptr(str, shr_p, shr_p2);

    delete p;
    return 0;
}