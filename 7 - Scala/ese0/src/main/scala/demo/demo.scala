/*  TE 08/01/2024
    ES.7 SCALA 
*/

object Main {
  def main(args: Array[String]): Unit = {
    /*(a) Definire in Scala la funzione mult6 che dato un numero intero lo moltiplica per sei,
    e la funzione mult che dati due numeri interi il moltiplica.*/

    def mult6(x:Int):Int = {
      x * 6
    }

    def mult(x:Int,y:Int): Int = {
      x*y
    }

    val x = 5;
    val y = 10
    println("Moltiplica " + x + " per 6 = "+ mult6(x))
    println("Moltiplica "+ x + " per "+ y + " = "+ mult(x,y))

    /*Definire al funzione magic che data una funzione f:Integer -> Integer e una funzione f: Integer X Integer -> Integer
    restituisce la funzione g(f(x), f(y)).
     Dati due numeri interi, utilizzare la funzione magic in combinazione con le funzioni definite in precedenza
     per moltiplicare i numeri interi per sei e poi moltiplicarli tra di loro.*/

    def magic(f: Int => Int, g: (Int, Int) => Int): (Int, Int) => Int = {
      (x, y) => g(f(x), f(y))
    }

    val multiplyMagic = magic(mult6, mult)

    println("Funzione Magic1: " + multiplyMagic(2,3))          //216
    println("Funzione Magic2: " + magic(mult6,mult)(2,3))      //216

    /*Definire una list di interi contenente gli interi 1,2,3.
    Moltiplicare ogni elemento della lista per due, utilizzando una funzione anonima*/
    val lista = List(1,2,3)
    println(lista.map(x => x*2))  //Moltiplico ogni elemento della lista per 2

    //Utilizzare map-reduce per sommare la lista dei valori ottenuti al punto (c).
    val lista2 = lista.map(x => x*2)
    // reduce (accumulatore, elementoLista)
    // all'inizio accumulatore è il primo elemento della lista (che non puo essere quindi vuota)
    // elementoLista è il secondo elemento della lista
    // viene eseguita la funzione (somma degli elementi in questo caso)
    // il risultato viene salvato nell'accumulatore (che viene quindi sovrascritto)
    // il nuovo elementoLista sara il terzo elemento della lista e cosi via..
    println(lista2.reduce((x,y) => x+y))


  }
}