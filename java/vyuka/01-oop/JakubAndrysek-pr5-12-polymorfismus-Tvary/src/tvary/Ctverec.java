/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 *
 * @author andrysekj
 */
public class Ctverec extends Tvar {

    private final double hrana;

    public Ctverec(double hrana, Bod stred) {
        super(stred);
        this.hrana = hrana;
    }

    /**
     * Get the value of hrana
     *
     * @return the value of hrana
     */
    public double getHrana() {
        return hrana;
    }


    
    @Override
    public double getObsah() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public double getObvod() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
    
}
