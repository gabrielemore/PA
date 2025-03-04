class Singleton {
    private Singleton() {
    }

    // modo 1
    static Singleton istance = new Singleton();
    static {
        int y = 0;
    }

    // modo 2 (alternativo a 1)
    static Singleton istance2;

    static Singleton getInstance() {
        if (istance2 == null)
            istance2 = new Singleton();
        return istance2;
    }
}

class App {
    public static void main(String[] args) {
        // NO Singleton s = new Singleton();
        Singleton s = Singleton.istance;

        Singleton b = Singleton.istance;

        s = Singleton.getInstance();
        s = Singleton.istance;
        Singleton a = Singleton.getInstance();

    }
}