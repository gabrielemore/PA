package Visitor;

//Utilizziamo le interfacce e non le classi astratte
//Come prima cosa scriviamo Visitor e Visitable

//Visitable contiene l'implementazione GENERICA del metodo accept
public interface Visitable {
    public <T> T accept(Visitor<T> v);
}
