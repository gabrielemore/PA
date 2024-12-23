/*  TE 04/2022
    ES.7 SCALA
*/

object Main {

  def ignoraMaiuscole(str: String): String = {
    val s = new StringBuilder()
    for (c <- str) {
      if (!c.isUpper) s.append(c)
    }
    s.toString()
  }

  def distanceFor(s1: String, s2: String): Int = {

    val new_s2: String = ignoraMaiuscole(s2)
    var count: Int = 0
    val l_min = Math.min(s1.length, new_s2.length)
    val l_max = Math.max(s1.length, new_s2.length)

    count += 100 * (l_max - l_min)

    //ciclo for con parametro intero
    for (i <- 0 until l_min) {
      if (s1.charAt(i).toString != "" && new_s2.charAt(i).toString != "")
        count += (s1.charAt(i) - new_s2.charAt(i)).abs
    }
    count
  }

  def distance_foreach(s1: String, s2: String): Int = {
    val new_s2: String = ignoraMaiuscole(s2)

    var count: Int = 0
    var i: Int = 0
    val l_min = Math.min(s1.length, new_s2.length)
    val l_max = Math.max(s1.length, new_s2.length)

    count += 100 * (l_max - l_min)

    s1.take(l_min).foreach(c =>
      count += (c - new_s2.charAt(i)).abs
      i += 1
    )
    count
  }

  def distance_ric(s1: String, s2: String): Int = {
    val new_s2: String = ignoraMaiuscole(s2)

    var i: Int = 0
    val l_min = Math.min(s1.length, new_s2.length)
    val l_max = Math.max(s1.length, new_s2.length)

    def ric(str1: String, str2: String, i: Int, min: Int): Int = {
      if (i == min - 1)
        (str1.charAt(i) - str2.charAt(i)).abs
      else
        (str1.charAt(i) - str2.charAt(i)).abs + ric(str1, str2, i + 1, min)
    }

    100 * (l_max - l_min) + ric(s1.take(l_min), new_s2.take(l_min), i, l_min)
  }

  def distance_ric_tail(s1: String, s2: String): Int = {
    val new_s2: String = ignoraMaiuscole(s2)

    var i: Int = 0
    val l_min = Math.min(s1.length, new_s2.length)
    val l_max = Math.max(s1.length, new_s2.length)

    def ric_tail(str1: String, str2: String, i: Int, min: Int, c: Int): Int = {
      if (i >= min)
        c
      else
        val diff = (str1.charAt(i) - str2.charAt(i)).abs
        ric_tail(str1, str2, i + 1, min, c + diff)
    }

    val count = ric_tail(s1, new_s2, i, l_min, 0)

    count + 100 * (l_max - l_min)
  }

  def distance_filter(s1: String, s2: String): Int = {
    val new_s2: String = s2.filter(c => c.isLower)
    var count: Int = 0
    val l_min = Math.min(s1.length, new_s2.length)
    val l_max = Math.max(s1.length, new_s2.length)

    count += 100 * (l_max - l_min)

    //ciclo for con parametro intero
    for (i <- 0 until l_min) {
      if (s1.charAt(i).toString != "" && new_s2.charAt(i).toString != "")
        count += (s1.charAt(i) - new_s2.charAt(i)).abs
    }
    count
  }

  //map e fold mancano

  def main(args: Array[String]): Unit = {
    val s1: String = "aa"
    val s2: String = "adCc"

    println(distanceFor(s1, s2))

    println(distance_foreach(s1, s2))

    println(distance_ric(s1, s2))

    println(distance_ric_tail(s1, s2))

    println(distance_filter(s1, s2))

    println(distance_map(s1, s2))

  }

}
