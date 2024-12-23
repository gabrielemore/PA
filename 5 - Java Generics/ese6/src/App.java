/*  TE 02/2022
    ES.5 JAVA GENERICS  
*/

import TreatArray.TreatArray;

public class App {
    public static void main(String[] args) throws Exception {
        Integer[] x = { 10, 2, 3, 5, 7 };
        TreatArray<Integer> test = new TreatArray<Integer>(x);
        System.out.println(test.toString());
        System.out.println(test.max());
        System.out.println(test.min());
        test.sort();
        System.out.println(test.toString());

        Character[] a = { 'n', 'd', 't', 'a', 'p' };
        TreatArray<Character> test2 = new TreatArray<Character>(a);
        System.out.println(test2.toString());
        System.out.println(test2.max());
        System.out.println(test2.min());
        test2.sort();
        System.out.println(test2.toString());
    }
}
