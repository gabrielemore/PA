/*  TE 02/2023
    ES.7 SCALA
*/

object Main {
  //funzione con tipo generico [T]
  def hth[T](list1: List[T], list2: List[T]): List[T] = {
    //faccio una funzione annidata, solo questa sarà ricorsiva
    def reverseList(list: List[T]): List[T] = {
      list match {
        case Nil => Nil
        //Separo la lista in head e tail e passo solo la coda in chiamata ricorsiva, poi ai risultati aggiungo in coda
        // la testa corrente
        //:+ aggiunge elementi alla lista
        case head :: tail => reverseList(tail) :+ head
      }
    }

    //Due modi per concatenare due liste
    //reverseList(list1) ::: list2
    reverseList(list1) ++ list2
  }

  def main(args: Array[String]): Unit = {

    val lista1 = List("a", "b", "c")
    val lista2 = List(1,2,3)

    val lista3 = hth(lista1, lista2)

    println(lista3)


  }
}
