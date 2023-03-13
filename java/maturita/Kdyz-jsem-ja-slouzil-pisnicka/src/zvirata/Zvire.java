/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zvirata;

/**
 *
 * @author kuba
 */
public abstract class Zvire {
    
    private final String oznaceni;
    private final String oznaceni2pad;
    private final String cinnost;

    public String getOznaceni() {
        return oznaceni;
    }

    public String getOznaceni2pad() {
        return oznaceni2pad;
    }

    public String getCinnost() {
        return cinnost;
    }

    public Zvire(String oznaceni, String oznaceni2pad, String cinnost) {
        this.oznaceni = oznaceni;
        this.oznaceni2pad = oznaceni2pad;
        this.cinnost = cinnost;
    }
    
    public String vyslouzil() {
        return "vysloužil jsem si " + oznaceni2pad + " za to.\n";
    }

    @Override
    public String toString() {
        return "A " + oznaceni + " " + cinnost + ",\n";
        // A ten vepř jako pepř,
        // A ta husa chodí bosa,
    }
    
    
}
