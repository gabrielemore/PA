object Main {

  def mult6(x: Int) = x * 6

  def mult(x1: Int, x2: Int) = x1 * x2

  def magic(f: (Int) => (Int), g: (Int, Int) => Int): (Int,Int)=>Int = {
    (x1, x2) => g(f(x1), f(x2))
  }

  def main(args: Array[String]): Unit = {
    val l = List(1, 2, 3);
    val lc = l.map(x => x * 2)
    val ld = lc.reduce((x, y) => x + y)

    println(magic(mult6,mult)(2,3))
    println(lc)
    println(ld)

  }

}
