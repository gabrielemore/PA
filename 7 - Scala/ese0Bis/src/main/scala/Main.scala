/*  TE 08/01/2024
    ES.7 SCALA 
*/

object Main {

  def main(args: Array[String]): Unit = {

    //definiamo la funzione mult6
    //la possiamo definire all'interno di def main(args: Array[String]): Unit = {}

    //def nomeFunzione(nomeParametro: Tipo parametro) : TipoRitornato = { ... }
    def mult6(x: Int): Int = {
      x * 6
    }

    // se ho più di un parametro lo separo con una virgola
    def mult(x: Int, y: Int): Int = {
      x * y
    }

    //interessante : funzione programmazione funzionale

    //f: Int => Int: Questo parametro è una funzione che prende un intero (Int) come input e restituisce un altro intero
    // come output. Ad esempio, mult6 è un possibile argomento per f.

    //g: (Int, Int) => Int: Questo parametro è una funzione che prende due interi come input e restituisce un intero
    // come output. Ad esempio, mult è un possibile argomento per g.

    //ATENZIONE: La funzione magic restituisce una nuova funzione che accetta due interi (Int, Int) come input e
    // restituisce un intero Int come output. Questo è espresso dal tipo di ritorno (Int, Int) => Int.
    def magic(f: Int => Int, g: (Int, Int) => Int): (Int, Int) => Int = {

      //questa qui è una funzione anonima
      (x, y) => g(f(x), f(y))
      //Questi parametri x e y non sono definiti all'interno di magic , ma saranno forniti quando la funzione restituita
      // da magic sarà effettivamente chiamata
    }

    println(mult6(5))
    println(mult(5, 3))

    //multiplyMagic è ora una nuova funzione che accetta due interi, li moltiplica per 6 usando mult6, e poi
    // moltiplica i risultati ottenuti usando mult.
    //Questo perchè il tipo ritornato da magic è una FUNZIONE che accetta due interni e ne restituisce uno!

    //NB: per definire una variabile uso "val" se voglio che sia IMMUTABILE (non cambia il suo valore)
    //Userei "var" se volessi che il suo valore risulti MUTABILE
    val multiplyMagic = magic(mult6, mult)

    // posso usare magic in due modi
    //magic restituisce una funzione che accetta due parametri.
    //li metto gia in parte allora (2,3).
    println(magic(mult6, mult)(2, 3))
    // oppure uso multplyMagic definita sopra che è gia la funzione restituita da magic
    println(multiplyMagic(2, 3))


    //SECONDA PARTE
    //Definizione di lista (ricorda: val -> immutabile)
    // si usa List(...) per creare una lista
    val list = List(1, 2, 3)

    //se voglio applicare una funzione (anonima, ma non per forza) a tutti gli elementi di una lista uso map
    println(list.map(x => x * 2))

    // Ok anche println(list.map((x:Int) => x * 2)) ma non è necessario. Dal contesto scala capisce da solo

    //Posso salvare i risultati della moltiplicazione che ho fatto in una nuova lista (NON POSSO MODIFICARE LA LISTA
    // ORIGINALE)

    val ListaPuntoC = list.map(x => x * 2)
    println(ListaPuntoC)

    // Reduce riduce una collezione ad un solo risultato in base ad una certa funzione anonima
    // In x= accumulatore (che all'inizio sarà il primo elemento della lista)
    // y= scondo elemento della lista e cosi via..
    println(ListaPuntoC.reduce((x, y) => x + y))

    // si poteva usare anche fold. fold permette di separare accumulatore da elementi della lista e di inizializzarlo
    // usabile quindi anche con liste vuote
    // il primo elemento tra parentesi è l'accumulatore ( 0 in questo caso ma si puo inizializzare come si vuole)
    println(ListaPuntoC.fold(0)((x, y) => x + y))

  }

}
