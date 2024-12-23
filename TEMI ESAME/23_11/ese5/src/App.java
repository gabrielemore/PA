public class App {
    public static void main(String[] args) throws Exception {

        Integer v[] = { 1, 2, 3, 4 };
        Integer v2[] = { 10, 11, 12 };

        Character vs[] = { 'c', 'i', 'a', 'o' };
        Character vs2[] = { 'm', 'a', 'r', 'i', 'o' };

        ArrayT<Integer> a1 = new ArrayT<>(v);
        ArrayT<Integer> a2 = new ArrayT<>(v2);

        System.out.println(a1.toString());
        a1.accoda(a2);
        System.out.println(a1.toString());

        ArrayT<Character> s1 = new ArrayT<>(vs);
        ArrayT<Character> s2 = new ArrayT<>(vs2);

        System.out.println(s1.toString());
        s1.accoda(s2);
        System.out.println(s1.toString());

    }
}
