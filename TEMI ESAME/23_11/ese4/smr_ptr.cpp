#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

// INT
void cambia_primo_ele_int_raw(int *p)
{
    p[0] = 10;
}
// unique pointer deve essere passato per reference
void cambia_primo_ele_int_sp(unique_ptr<int[]> &p)
{
    p.get()[0] = 20;
}

void cambia_primo_ele_int_shr(shared_ptr<int[]> p)
{
    p.get()[0] = 30;
}

// CHAR
void cambia_primo_ele_char_raw(char *p)
{
    p[0] = 'z';
}
// unique pointer deve essere passato per reference
void cambia_primo_ele_char_sp(unique_ptr<char[]> &p)
{
    p.get()[0] = 'x';
}

void cambia_primo_ele_char_shr(shared_ptr<char[]> p)
{
    p.get()[0] = 'v';
}

int main()
{
    int i[] = {1, 2, 3};
    char s[] = "ciao";

    // unique pointer è uno shared_pointer la cui ownership non puo essere condivisa
    unique_ptr<int[]> sp_int(new int[3]);
    unique_ptr<char[]> sp_char(new char[strlen(s) + 1]);
    // shared_pointer è uno smart pointer la cui ownership puo essere condivisa
    shared_ptr<int[]> shr_int(new int[3]);
    shared_ptr<int[]> shr_int2(shr_int);
    shared_ptr<char[]> shr_char(new char[strlen(s) + 1]);
    // smart pointer gestiscono la deallocazione in modo automatico
    // Una volta che la variabile esce dallo scope viene deallocata
    // (per gli shared pointer abbiamo la deallocazione quando il
    // numero di var che si riferiscono alla memoria è 0)

    // raw pointer devo deallocare la memoria manualmente
    int *raw_i = new int[3];
    char *raw_c = new char[strlen(s) + 1];

    // copio array nello spazio riservato dai puntatori
    // int
    raw_i[0] = i[0];
    raw_i[1] = i[1];
    raw_i[2] = i[2];
    sp_int.get()[0] = i[0];
    sp_int.get()[1] = i[1];
    sp_int.get()[2] = i[2];
    shr_int.get()[0] = i[0];
    shr_int.get()[1] = i[1];
    shr_int.get()[2] = i[2];
    // char
    strcpy(raw_c, s);
    strcpy(sp_char.get(), s);
    strcpy(shr_char.get(), s);

    cambia_primo_ele_int_raw(raw_i);
    cambia_primo_ele_int_sp(sp_int);
    cambia_primo_ele_int_shr(shr_int);

    cambia_primo_ele_char_raw(raw_c);
    cambia_primo_ele_char_sp(sp_char);
    cambia_primo_ele_char_shr(shr_char);

    cout << raw_i[0] << " " << raw_i[1] << " " << raw_i[2] << endl;
    cout << sp_int.get()[0] << " " << sp_int.get()[1] << " " << sp_int.get()[2] << endl;
    cout << shr_int.get()[0] << " " << shr_int.get()[1] << " " << shr_int.get()[2] << endl;

    cout << raw_c << endl;
    cout << sp_char.get() << endl;
    cout << shr_char.get() << endl;

    // deallocazione manuale raw pointer
    // per evitare memory leaks
    delete[] raw_i;
    delete[] raw_c;
    // evito dangling pointer
    raw_i = nullptr;
    raw_c = nullptr;

    return EXIT_SUCCESS;
}