#include <iostream>
#include <memory>

using namespace std;

class ese
{
public:
    void e()
    {
        cout << "esempio" << endl;
    }
};

int main()
{
    unique_ptr<ese> sp = make_unique<ese>();

    // smart pointer permettono una gestione della memoria automatica
    // non devo occuparmi di deallocare la memoria. Quando il puntatore
    // esce dal suo scope viene deallocata in automatico

    sp->e();

    ese *raw = new ese();

    // raw pointer devo occpuarmi di deallocare la memoria quando
    // non serve più. Per evitare memory leaks

    raw->e();

    delete (raw);
    // evito dangling pointer
    raw = nullptr;

    // esistono anche gli shared pointer
    shared_ptr<ese> shr_p = make_shared<ese>();
    shared_ptr<ese> shr_p2 = shr_p;

    // invece non potevo fare
    // shr_p = sp;
    // e tantomeno
    // unique_ptr<ese> sp2 = sp;
    return 0;
}