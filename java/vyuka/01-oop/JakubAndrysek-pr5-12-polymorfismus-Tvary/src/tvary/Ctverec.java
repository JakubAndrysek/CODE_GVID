/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 *
 * @author andrysekj
 */
public class Ctverec extends Obdelnik {

    public Ctverec(double hrana, Bod stred) {
        super(hrana, hrana, stred);
    }

    public double getHrana() {
        return this.getSirka();
    }

    
    @Override
    public String toString() {
        return "Ctverec{" + super.toString() + '}';
    }
}