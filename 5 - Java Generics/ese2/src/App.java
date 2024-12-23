/*  TE 8/01/2024
    ES.5 JAVA GENERICS  
*/

import Set.Set;

public class App {
    public static void main(String[] args) throws Exception {
        Integer[] x = { 3, 5, 7, 7 };
        Integer[] y = { 3, 8, 10 };

        Character[] a = { 'a', 'g' };
        Character[] b = { 'w', 'g' };

        Set<Integer> z = new Set<>(x);
        Set<Integer> w = new Set<>(y);

        Set<Character> p = new Set<>(a);
        Set<Character> q = new Set<>(b);

        System.out.println(z.toString());
        System.out.println(w.toString());
        System.out.println(p.toString());
        System.out.println(q.toString());

        Set<Integer> k = Set.unione(z, w);
        System.out.println(k.toString());
        Set.cancella(k);
        System.out.println(k.toString());

        Set<Character> s = Set.unione(p, q);
        System.out.println(s.toString());
        Set.cancella(s);
        System.out.println(s.toString());
    }
}
