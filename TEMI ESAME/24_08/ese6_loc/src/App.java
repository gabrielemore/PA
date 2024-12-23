
import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) throws Exception {


        //INTEGER
        List<Integer> l = new ArrayList<>();
        l.add(1);
        l.add(2);
        l.add(3);
        l.add(3);

        List<Integer> l1 = new ArrayList<>();
        l1.add(1);
        l1.add(7);
        l1.add(5);
        l1.add(7);

        List<Integer> l2 = new ArrayList<>();
        l2.add(8);
        l2.add(3);
        l2.add(3);
        l2.add(1);

        DescSet<Integer> d = new DescSet<>(l);
        DescSet<Integer> d1 = new DescSet<>(l1);
        DescSet<Integer> d2 = new DescSet<>(l2);

        DescSet<Integer> d3 = DescSet.unione(d1, d2);

        System.out.println(d);
        System.out.println(d1);
        System.out.println(d2);
        System.out.println(d3);

        List<Character> lc = new ArrayList<>();
        lc.add('a');
        lc.add('b');
        lc.add('c');
        lc.add('b');

        List<Character> lc1 = new ArrayList<>();
        lc1.add('a');
        lc1.add('g');
        lc1.add('d');
        lc1.add('d');

        //CHARACTER

        List<Character> lc2 = new ArrayList<>();
        lc2.add('a');
        lc2.add('b');
        lc2.add('b');
        lc2.add('f');

        DescSet<Character> dc = new DescSet<>(lc);
        DescSet<Character> dc1 = new DescSet<>(lc1);
        DescSet<Character> dc2 = new DescSet<>(lc2);

        DescSet<Character> dc3 = DescSet.unione(dc1, dc2);

        System.out.println(dc);
        System.out.println(dc1);
        System.out.println(dc2);
        System.out.println(dc3);

    }
}
