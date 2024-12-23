package Visitor;

import Animali.Animale;
import Animali.Pesce;

//I metodi che voglio creare sulle classi devono implementare Visitor<SCELTA DEL TIPO RITORNATO>
//possibile eseguire il quick fix per struttura base non appena definita la prima riga

public class isPesce implements Visitor<Boolean> {

    @Override
    public Boolean visit(Animale e) {
        return false;
    }

    @Override
    public Boolean visit(Pesce e) {
        return true;
    }
    
}
