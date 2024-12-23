import set.MySet;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //Set di Integer
        Integer[] arrayInt = {4,3,2,8};
        MySet<Integer> setInt1 = new MySet<Integer>(Arrays.asList(arrayInt));
        System.out.println(setInt1);

        MySet<Integer> setInt2 = new MySet<>(Arrays.asList(new Integer[] {4,3,2,5}));
        System.out.println(setInt2);

        MySet<Integer> setInt3 = setInt1.clone();
        System.out.println(setInt3);

        setInt3.addElement(5);
        System.out.println(setInt3);

        //Distruttore
        setInt3.cancella();

        MySet<Integer> listaUnione = MySet.unione(setInt1,setInt2);
        System.out.println(listaUnione);



        //Set Character
        Character[] arrayChar = {'c','d','e','e','d','s','a'};
        MySet<Character> setChar1 = new MySet<>(Arrays.asList(arrayChar));
        System.out.println(setChar1);

        MySet<Character> setChar2 = new MySet<>(Arrays.asList(new Character[] {'d','z','e'}));
        System.out.println(setChar2);

        MySet<Character> listaCharUnione = MySet.unione(setChar1,setChar2);
        System.out.println(listaCharUnione);



    }
}