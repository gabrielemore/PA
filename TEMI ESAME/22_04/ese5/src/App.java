//NB: l'inserimento e rimozione era da fare in testa! non ho voglia di rifarlo. Negli esercizi singoli dovrebbe essere giusto

import Persone.*;

public class App {
    public static void main(String[] args) throws Exception {

        OrderedStack<Integer> t1 = new OrderedStack<>();

        t1.push(2);
        t1.push(10);
        System.out.println(t1);
        System.out.println(t1.pop());
        t1.push(7);
        t1.push(4);
        t1.push(9);
        t1.push(13);
        t1.push(3);
        t1.push(1);
        t1.push(4);
        t1.push(34);
        t1.push(32);
        t1.push(21);
        System.out.println(t1);
        System.out.println(t1.max());
        System.out.println(t1.min());

        OrderedStack<String> t2 = new OrderedStack<>();

        t2.push("a");
        t2.push("b");
        t2.push("z");
        System.out.println(t2.pop());
        System.out.println(t2.max());
        System.out.println(t2.min());

        // Se class OrderedStack è scritta in questo modo: public class OrderedStack<T
        // extends Comparable<T>>
        // non posso farlo questo
        // OrderedStack<Studente> t3 = new OrderedStack<>();
        // ma posso fare questo
        OrderedStack<Persona> t4 = new OrderedStack<>();
        t4.push(new Studente("giacomo"));
        // Se class OrderedStack è scritta in questo modo: public class OrderedStack<T
        // extends Comparable<? super T>>
        // T = Studente, allora abbiamo <Studente extends Comparable<? super Studente>>
        // ? allora è Persona. Viene rispettato il bound
        // SI
        OrderedStack<Studente> t3 = new OrderedStack<>();

    }
}
