
#include <iostream>
using namespace std;

class Batteria {
  private:
    int capacita;
    int livello;
    int identificativo;
    string nome;
    int& numReference;
  public:


    Batteria(int c):capacita(c),livello(c),numReference(capacita) {
      identificativo = 5;
      nome = "Batteria";
    }

    int getLivello() {
      return livello;
    }

    int getCapacita() {
      return capacita;
    }

    void consumaUnita() {
      if(livello > 0){
        livello--;
      }
    }

    void carica(int u) {
      livello = livello + u;
      if(livello > capacita) {
        livello = capacita;
      }
    }
};

class Cellulare {
  private:
    Batteria a;             //Stack: A meno di definire il costruttore di default Batteria(), non è possibile istanziarlo nel costruttore, solo in Initializer List
                            //se invece definisco il costruttore di default di batteria posso inizializzarlo anche nel costruttore normalmente

    Batteria* b;            //Puntatore, Heap: Il puntatore all'inizio può essere a null, volendo posso istanziarlo anche nel metodo del costruttore
    Batteria& c;            //Reference, Heap: Il reference all'inizio non può essere a null, quindi posso istanziarlo solo nell'Initializer list
    int numeroChiamate;  
    int secondiChiamate;
    int numeroSms;
    const int numeroDiSerie;   //Essendo a const, non può essere inizializzata nel costruttore, inizializzato per forza in initializer list

  public:
    Cellulare(int unita) :a(unita),b(new Batteria(unita-10)), c(*(new Batteria(unita-20))),
    numeroDiSerie(26789) {

      //a = Batteria(unita); //errore per la presenza di int& numReference; in Batteria che è una reference
      b = new Batteria(unita);
      //c= * (new Batteria(unita)); //errore

      numeroChiamate = 0;
      secondiChiamate = 0;
      numeroSms = 0;

    }

    //Creo un metodo per visualizzare la carica di ogni batteria

    int getLivelloBatteriaA() {
      return a.getLivello();
    }
   
    int getLivelloBatteriaB() {
        return b->getLivello();
    }

    int getLivelloBatteriaC() {
      return c.getLivello();
    }




};

int main(int argc, char const *argv[])
{

    Batteria b = Batteria(100);

    
    Cellulare cell(100);

    cout << "Livello batteria A: " << cell.getLivelloBatteriaA() << endl;
    cout << "Livello batteria B: " << cell.getLivelloBatteriaB() << endl;
    cout << "Livello batteria C: " << cell.getLivelloBatteriaC() << endl;


    return 0;
}
