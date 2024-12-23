//============================================================================
// Che differenza c'è tra ereditarietà pubblica e privata in C++? Spiegalo
// per bene con un esempio ben commentato.
//============================================================================

#include <iostream>

using namespace std;

class Madre
{
public:
    void pubMetodoMadre()
    {
        cout << "Metodo pubblico madre" << endl;
    }

protected:
    void proMetodoMadre()
    {
        cout << "Metodo protected madre" << endl;
    }

private:
    void priMetodoMadre()
    {
        cout << "Metodo private madre" << endl;
    }
};

// Figlio public: Ereditarietà pubblica
//-> i membri public della classe madre diventano membri pubblici della classe figlia
//-> i membri protected della classe madre diventano membri protected della classe figlia
//-> i membri private della classe madre NON vengono ereditati
class FiglioPublic : public Madre
{
public:
    void usoMadre()
    {
        pubMetodoMadre();
        proMetodoMadre();
        // priMetodoMadre(); ERRORE: questo metodo è private. Non viene ereditato da figlio
    }
};
// Figlio public: Ereditarietà pubblica
//-> i membri public della classe madre diventano membri private della classe figlia.
//-> i membri protected della classe madre diventano membri private della classe figlia
//-> i membri private della classe madre NON vengono ereditati (UGUALE A PUBLIC)
class FiglioPrivate : private Madre
{
public:
    // per rendere accessibili i metodi ereditati da madre (che per questo figlio diventano metodi private)
    // li posso richiamare dentro un metodo public
    void usoMadre()
    {
        pubMetodoMadre();
        proMetodoMadre();
        // priMetodoMadre(); ERRORE: questo metodo è private. Non viene ereditato da figlio
    }
};

int main()
{
    FiglioPublic pub;
    pub.usoMadre();       // OK, usoMadre è public e utilizzo sia pubMetodoMadre che proMetodoMadre (nonstante questo sia protected)
    pub.pubMetodoMadre(); // Ok, figlio public quindi pubMetodoMadre è un metodo public per FiglioPublic
    // pub.proMetodoMadre(); // Errore: questo metodo è protected per FiglioPublic
    // pub.priMetodoMadre(); // Errore: questo metodo non è ereditato da FiglioPublic

    FiglioPrivate pri;
    pri.usoMadre(); //OK, usoMadre è public e utilizzo sia pubMetodoMadre che proMetodoMadre (nonstante questi siano private)
    //pri.pubMetodoMadre(); //ERRORE: questo metodo non è public! con eredita privata diventa private.
    // pub.proMetodoMadre(); // Errore: questo metodo è private per FiglioPrivate
    // pub.priMetodoMadre(); // Errore: questo metodo non è ereditato da FiglioPrivate
    return 0;
}