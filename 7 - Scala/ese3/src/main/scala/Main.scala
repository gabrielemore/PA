/*  TE 04/2023
    ES.7 SCALA
*/

object Main {

  def ttt[T](l1: List[T], l2: List[T]): List[T] = {
    def ricSecondaLista(l: List[T]): List[T] = {
      l match
        case head :: next =>
          ricSecondaLista(next) :+ head
        case Nil => Nil
    }

    l1 ++ ricSecondaLista(l2)
  }


  def main(args: Array[String]): Unit = {

    val list1 = List("a", "b", "c")
    val list2 = List(1, 2, 3)

    println(ttt(list1, list2))

  }
}
