#include <iostream>
#include <memory>

using namespace std;

class ese
{
public:
    void str()
    {
        cout << "esempio" << endl;
    }
};

int main()
{
    unique_ptr<ese> sp = make_unique<ese>();
    ese *raw = new ese();

    sp->str();
    // Smart pointer non devo gestire la deallocazione in meomoria
    // una volta uscito dallo scope avviene la deallocazione in automatico

    raw->str();
    // raw popinters è compito del programmatore deallocare la memoria
    // per evitare memory leak e impostare a nullptr per evitare dangling pointer
    delete (raw);
    raw = nullptr;

    // esistono anche i shared pointer
    shared_ptr<ese> shr = make_shared<ese>();
    shared_ptr<ese> shr2 = shr;

    shr->str();
    shr2->str();

    // non avrei potuto fare:
    // unique_ptr<ese> sp2 = sp;

    return EXIT_SUCCESS;
}