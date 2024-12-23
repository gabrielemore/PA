// ESERCIZIO 5: Overriding
import java.util.Random;

class Persona {
    void echo(int x) {
        System.out.println("Ciao");
    }
}

class Studente extends Persona {
    // qui facciamo overloading (NO overriding)
    void echo(long x) {
        System.out.println("Aloa");
    }
}

public class Prova {
    public static void main(String[] args) {
        Persona p = new Persona();
        p.echo(5);
        Studente s = new Studente();
        // mettendo direttamente il numero nel metodo Java lo interpreta come int.
        // Quindi abbiamo echo(int).
        // echo(int) non c'è in Studente. Allora risale in Persona e li lo trova.
        s.echo(4);
        // cosi invece viene stampato "Aloa"
        long a = 4;
        s.echo(a);
        // p.echo(a); questo darebbe errore in compilazione non essendoci nessun
        // echo(long) in Persona
        Random rnd = new Random();
        if (rnd.nextBoolean()) {
            p = s;
        }
        // Qui verrà stampato sempre "Ciao":
        // STATICO: p è Persona. Java cerca in Persona
        // un echo(int). Lo trova e lo seleziona
        // DINAMICO: p può essere Persona o Studente (in base al random bool)
        // SE Persona allora cerca in Persona echo(int). Lo trova e lo seleziona
        // SE Studente allora cerca in Studente echo(int). Non c'è. Risale in Persona.
        // in Persona lo trova e lo seleziona
        p.echo(6);
    }
}