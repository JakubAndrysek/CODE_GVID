/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zoo;

/**
 *
 * @author andrysekj
 */
public class Ptak extends Zvire {
    protected String rasa;

    public Ptak(String rasa, int vek, String jmeno) {
        super(jmeno, 2, "Pip pip");
        this.rasa = rasa;
    }

    public Ptak(String rasa, int vek) {
        this(rasa, vek, "NoName");
    }
    
    public Ptak(String rasa, String jmeno) {
        this(rasa, 0, jmeno);
    }
    
    public Ptak(String rasa) {
        this(rasa, 0, "NoName");
    }

    public String getRasa() {
        return rasa;
    }

    
    @Override
    public String toString() {
        return "Ptak{" + super.toString() + " rasa=" + rasa + ", vek=" + vek + '}';
    }
}
