package Collezione;

import java.util.ArrayList;

import Computer.Computer;

// creo ListaComputer che rappresenta una lista di tipi generici T che siano Computer o 
// sotto tipi di Computer USANDO ereditarietà dalla classe ArrayList
public class ListaComputer<T extends Computer> extends ArrayList<T> {

}
