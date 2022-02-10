/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 *
 * @author kuba
 */
public class Trojuhelnik extends Tvar {
    private final double strana;

    public Trojuhelnik(double strana, Bod stred) {
        super(stred);
        this.strana = strana;
    }

    public double getStrana() {
        return strana;
    }


    @Override
    public double getObsah() {
        return (this.strana * this.strana) / 2;
    }

    @Override
    public double getObvod() {
        return this.strana * 3;
    }    

    @Override
    public String toString() {
        return "Trojuhelnik{" + super.toString() + "strana=" + strana + '}';
    }
}
