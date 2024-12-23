package Algoritmi;

import Collezione.ListaComputer;
import Computer.Computer;

public class Algoritmi {

    public static <T extends Computer> T getFirst(ListaComputer<T> l) {
        return l.get(0);
    }
}
