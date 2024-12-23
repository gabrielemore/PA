object Main {

  def ttt[T](l1:List[T], l2:List[T]): List[T] = {
    def ric(l:List[T]): List[T]={
      l match
        case head::next =>
          ric(next) :+ head
        case Nil => Nil
    }

    l1 ++ ric(l2)
  }

  def main(args: Array[String]): Unit = {
    val l1=List('a','b','c')
    val l2=List(1,2,3)

    println(ttt(l1,l2))
  }

}
