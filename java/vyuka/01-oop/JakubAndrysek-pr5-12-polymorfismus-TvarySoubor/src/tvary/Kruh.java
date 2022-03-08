/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 *
 * @author andrysekj
 */
public class Kruh extends Tvar{

    private final double polomer;

    
    /**
     * 
     * @param polomer
     * @param stred 
     */
    public Kruh(double polomer, Bod stred) {
        super(stred);
        this.polomer = polomer;
    }


    /**
     * Get the value of polomer
     *
     * @return the value of polomer
     */
    public double getPolomer() {
        return polomer;
    }
    
    
    @Override
    public double getObsah() {
        return Math.PI * this.polomer * this.polomer;
    }

    @Override
    public double getObvod() {
        return 2 * Math.PI * this.polomer;
    }

    @Override
    public String toString() {
        return "Kruh{" + super.toString() + "polomer=" + polomer + '}';
    }
    
    
    
}
