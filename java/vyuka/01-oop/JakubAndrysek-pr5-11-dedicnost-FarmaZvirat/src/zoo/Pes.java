/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zoo;

/**
 *
 * @author andrysekj
 */
public class Pes extends Zvire {
    protected String rasa;
    protected int vek;
    
    public Pes(String rasa, int vek, String jmeno) {
        super(jmeno, 4);
        this.rasa = rasa;
        this.vek = vek;
    }
    
    public Pes(String rasa, int vek) {
        this(rasa, vek, "NoName");
    }
    
    public Pes(String rasa, String jmeno) {
        this(rasa, 0, jmeno);
    }
    
    public Pes(String rasa) {
        this(rasa, 0, "NoName");
    }

    public String getRasa() {
        return rasa;
    }

    public int getVek() {
        return vek;
    }

    public void setVek(int vek) {
        if(vek <= this.vek) {
            return;
        }
        this.vek = vek;
    }

    @Override
    public String vydejZvuk() {
        return "Haf Haf";
    }

    @Override
    public String toString() {
        return "Pes{" + super.toString() + "rasa=" + rasa + ", vek=" + vek + '}';
    }
    
    
    
    
    

    
    
    
    
}
