package Computer;

public class Computer implements Comparable<Computer> {

    private int ID;

    public Computer(int id) {
        this.ID = id;
    }

    @Override
    public int compareTo(Computer c) {
        return this.ID - c.ID;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(this.ID);
        return s.toString();
    }
}
