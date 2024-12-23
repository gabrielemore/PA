public class App {
    public static void main(String[] args) throws Exception {
        Integer[] v = { 1, 2, 3 };
        Integer[] v2 = { 4, 5, 6 };

        ArrayT<Integer> t1 = new ArrayT<>(v);

        System.out.println(t1.toString());
        t1.accoda(v2);
        System.out.println(t1.toString());

        Character[] c = { 'a', 'b', 'c' };
        Character[] c2 = { 'd', 'e', 'f' };

        ArrayT<Character> t2 = new ArrayT<>(c);

        System.out.println(t2.toString());
        t2.accoda(c2);
        System.out.println(t2.toString());

    }
}
