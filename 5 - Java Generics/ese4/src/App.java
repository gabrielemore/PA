/*  TE 02/2023
    ES.5 JAVA GENERICS  
*/

import ArrayT.ArrayT;

public class App {
    public static void main(String[] args) throws Exception {

        Integer[] x = {1,2,3};
        Integer[] y = {4,5,6};
        Character[] a = {'a','b'};
        Character[] b = {'c','d'};

        ArrayT<Integer> w = new ArrayT<>(x);
        ArrayT<Integer> r = new ArrayT<>(y);
        ArrayT<Character> n = new ArrayT<>(a);
        ArrayT<Character> m = new ArrayT<>(b);

        System.out.println(w.toString());
        ArrayT<Integer> v = ArrayT.accoda(w,r);
        System.out.println(v.toString());

        System.out.println(n.toString());
        ArrayT<Character> t = ArrayT.accoda(n,m);
        System.out.println(t.toString());
    }
}
