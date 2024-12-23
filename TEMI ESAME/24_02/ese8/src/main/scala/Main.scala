object Main {

  def mod(x: Int): Boolean = {
    if (x % 2 == 0)
      true;
    else
      false;
  }

  def mult(x: Int) = x * 2

  def magic(f: Int => Boolean, g: Int => Int): Int => Int = {
    (x) =>
      if (f(x))
        g(x)
      else
        x
  }

  def main(args: Array[String]): Unit = {

    def h = magic(mod, mult)

    println(h(2))
    println(h(3))

    val list = List(1, 2, 3)

    val le = list.map(x => h(x))

    val lf = le.reduce((x, y) => x + y)
    
    println(le)
    println(lf)

  }

}
