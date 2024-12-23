/*  TE 01/2022
    ES.7 SCALA 
*/

import scala.annotation.tailrec

object main {

  def main(args: Array[String]): Unit = {

    def concat_for(x: List[String]): String = {
      //definisco una variabile s e gli dico che deve essere Stringa. Inizializzo a stringa vuota
      var s: String = " "
      // prendo ad ogni ciclo, un elemento presente nella lista x e lo metto in app.
      for (app <- x) {
        if (app.nonEmpty && app.head != 'a') {
          s = s.concat(app);
        }
      }
      s //return della funzione
    }

    //alternativa
    def concat_for_alt(x: List[String]): String = {
      var s: String = ""
      for (app <- x if app.nonEmpty && app.head != 'a')
        {
          s = s.concat(app)
        }
        return s
    }

    def concat_foreach(x: List[String]): String = {
      var s: String = ""
      // foreach prende ogni elemento di x uno alla volta, lo mette in app, e applica la funzione anonima dopo la
      // freccia
      x.foreach(app =>
        if (app.nonEmpty && app.head != 'a')
          //s = s.concat(app)
          // in alternativa si puo fare anche cosi
          s += app
      )
      s
    }

    def concat_rec(x: List[String]): String = {
      x match
        case Nil => ""
        //separa il primo elemento della lista con il resto della lista
        //in questo caso head è una stringa, next è una lista di stringhe
        case head :: next =>
          //in alternativa head.head != 'a' non funziona se ho "" )
          if (!head.startsWith("a")) {
            head + concat_rec(next)
          } else
            concat_rec(next)

    }

    @tailrec
    def concat_rec_tail(x: List[String], res: String = ""): String = {
      x match
        case Nil => res
        case head :: next =>
          if (!head.startsWith("a"))
            concat_rec_tail(next, res + head)
          else
            concat_rec_tail(next, res)
    }

    def concat_filter(x: List[String]): String = {
      var s = ""
      val listaFiltrata = x.filter(e => !e.startsWith("a"))
      listaFiltrata.foreach(e => s += e)
      s
    }

    def concat_map(x: List[String]): String = {
      //var s = ""
      val listaModificata = x.map(e =>
        if (e.startsWith("a"))
          ""
        else
          e
      )
      //listaModificata.foreach(e => s += e)

      //listaModificata.foldLeft("")((s, t) => s + t)
      //s
      listaModificata.foldLeft("")((x, y) => x + y)
    }


    //ZONA TEST
    val lista1 = List("anno", "gio", "rno")
    val lista2 = List("", "ak", "mo")

    //concat_for con un semplice ciclo for
    val resultA1 = concat_for(lista1)
    println("Ciclo For: " + resultA1)
    val resultA2 = concat_for(lista2)
    println("Ciclo For: " + resultA2)
    //concat_foreach usando il foreach (e una funzione + var locale)
    val resultB1 = concat_foreach(lista1)
    println("For Each: " + resultB1)
    val resultB2 = concat_foreach(lista2)
    println("For Each: " + resultB2)
    //concat_rec: usando la ricorsione
    val resultC1 = concat_rec(lista1)
    println("Ricorsiva:" + resultC1)
    val resultC2 = concat_rec(lista2)
    println("Ricorsiva:" + resultC2)
    //concat_tail usando la tail recursion
    val resultD1 = concat_rec_tail(lista1)
    println("Tail:" + resultD1)
    val resultD2 = concat_rec_tail(lista2)
    println("Tail:" + resultD2)
    //concat_filter usando anche filter
    val resultE1 = concat_filter(lista1)
    println("Filter:" + resultE1)
    val resultE2 = concat_filter(lista2)
    println("Filter:" + resultE2)
    // concat_map usando anche map che converte le stringe che iniziano con ‘a’ in "" e poi le concatena tutte
    println(concat_map(lista1))

  }

}
