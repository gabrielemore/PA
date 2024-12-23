object Main {

  def raddoppia(x:Int):Int = x*2
  def sum(x:Int,y:Int):Int = x+y

  def magic(f:Int=>Int, g:((Int,Int)=>Int) ): (Int,Int) => Int = {
    (x,y)=>g(f(x),y)
  }

  def main(args: Array[String]):Unit = {

    val l = List(1,2,3)
    val lc = l.map(x=>x*2);
    val ld = lc.reduce((x,y)=>x+y)

    println(magic(raddoppia,sum)(4,3))

    println(lc)
    println(ld)

  }

}