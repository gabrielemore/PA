object Main {

  def hth[T](l1: List[T], l2: List[T]): List[T] = {
    def rev(l: List[T]): List[T] = {
      l match
        case head :: next =>
          rev(next) :+ head
        case Nil => Nil
    }

    rev(l1) ++ l2
  }

  def main(args: Array[String]): Unit = {

    val l1 = List(1, 2, 3)
    val l2 = List('a', 'b', 'c')

    println(hth(l1,l2))

  }
}
