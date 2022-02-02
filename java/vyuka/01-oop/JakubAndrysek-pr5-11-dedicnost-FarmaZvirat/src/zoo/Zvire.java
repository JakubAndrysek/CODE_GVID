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


    public Zvire(String jmeno, int pocetNohou) {
        this.jmeno = jmeno;
        this.pocetNohou = pocetNohou;
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

    @Override
    public String toString() {
        return "Zvire{" + "jmeno=" + jmeno + ", pocetNohou=" + pocetNohou + '}';
    }
    
    public abstract String vydejZvuk();  
}
