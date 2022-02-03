/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zoo;

/**
 *
 * @author andrysekj
 */
public abstract class Zvire {
    protected String jmeno;
    protected int pocetNohou;
    private String zvuk;
    protected int vek;


    public Zvire(String jmeno, int pocetNohou, String zvuk) {
        this.jmeno = jmeno;
        this.pocetNohou = pocetNohou;
        this.zvuk = zvuk;
    }    
    
    
    public String getJmeno() {
        return jmeno;
    }
    
    public int getPocetNohou() {
        return pocetNohou;
    }

    public void setPocetNohou(int pocetNohou) {
        if(pocetNohou < 0 || pocetNohou >= this.pocetNohou) {
            return;
        }
        this.pocetNohou = pocetNohou;
    }
    
    public int getVek() {
        return vek;
    }

    public void setVek(int vek) {
        if (vek <= this.vek) {
            return;
        }
        this.vek = vek;
    }
    
    public String vydejZvuk() {
        return zvuk;
    }
    
    
    
    @Override
    public String toString() {
        return "Zvire{" + "jmeno=" + jmeno + ", pocetNohou=" + pocetNohou + '}';
    }
}
