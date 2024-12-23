/*  TE 25/01/2024
    ES.7 SCALA
*/

object Main {

  def mod(x: Int): Boolean = {
    if (x % 2 == 0)
      true
    else false
  }

  def mult(x: Int): Int = {
    x * 2
  }

  def magic(f: Int => Boolean, g: Int => Int): Int => Int = {
    (x) =>
      if (f(x))
        g(x)
      else x
  }


  def main(args: Array[String]): Unit = {

    def h = magic(mod, mult)

    println(h(2))
    println(h(3))

    val lista = List(1, 2, 3, 4)

    println(lista.map(x => h(x)))

    println(lista.reduce((x, y) => x + y))


  }
}
