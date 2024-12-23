public class App {
    public static void main(String[] args) throws Exception {
        Integer v[] = { 1, 2, 3, 3 };
        Integer v2[] = { 2, 3, 6, 7 };

        MySet2<Integer> s1 = new MySet2<>(v);
        MySet2<Integer> s2 = new MySet2<>(v2);

        MySet2<Integer> s3 = MySet2.unione(s1, s2);

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);

        Character c[] = { 'a', 'b', 'b', 'b', 'c' };
        Character cr2[] = { 'b', 'c', 'e', 'f' };

        MySet2<Character> c1 = new MySet2<>(c);
        MySet2<Character> c2 = new MySet2<>(cr2);

        MySet2<Character> c3 = MySet2.unione(c1, c2);

        System.out.println(c1);
        System.out.println(c2);
        System.out.println(c3);

    }
}
