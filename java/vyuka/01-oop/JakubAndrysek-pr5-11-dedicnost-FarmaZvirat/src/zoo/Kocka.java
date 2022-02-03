/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zoo;

/**
 *
 * @author andrysekj
 */
public class Kocka extends Zvire {
    protected int zivoty = 10;

    public Kocka(String jmeno) {
        super(jmeno, 4, "Mnau mnau");
    }

    public int getZivory() {
        return zivoty;
    }

    public void setZivory(int zivoty) {
        if(zivoty >= this.zivoty) {
            return;
        }
        this.zivoty = zivoty;
    }          

    @Override
    public String toString() {
        return "Kocka{" + super.toString() + " zivoty=" + zivoty + '}';
    }
    
    
}
