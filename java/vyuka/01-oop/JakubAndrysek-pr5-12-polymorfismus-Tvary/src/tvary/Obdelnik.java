/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 *
 * @author kuba
 */
public class Obdelnik extends Tvar {
    private final double vyska;
    private final double sirka;

    public Obdelnik(double vyska, double sirka, Bod stred) {
        super(stred);
        this.vyska = vyska;
        this.sirka = sirka;
    }

    public double getVyska() {
        return vyska;
    }

    public double getSirka() {
        return sirka;
    }

    @Override
    public double getObsah() {
        return this.sirka * this.vyska;
    }

    @Override
    public double getObvod() {
        return (this.sirka + this.vyska) * 2;
    }

    @Override
    public String toString() {
        return "Obdelnik{" + super.toString() +"vyska=" + vyska + ", sirka=" + sirka + '}';
    }
    
    
    
    
}
