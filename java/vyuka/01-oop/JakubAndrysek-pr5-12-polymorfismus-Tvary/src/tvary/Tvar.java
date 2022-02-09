/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 * Abstraktní třída reprezentující tvar
 * @author andrysekj
 */
public abstract class Tvar {
    
    /**
     * Stred aktualniho tvaru
     */
    protected Bod stred;

    protected Tvar(Bod stred) {
        this.stred = stred;
    }

    /**
     * Get the value of stred
     *
     * @return the value of stred
     */
    public Bod getStred() {
        return stred;
    }
    
    /**
     * Vraci obsah aktualniho tvaru
     * @return 
     */
    public abstract double getObsah();
    
    /**
     * Vraci obvod aktualniho tvaru
     * @return 
     */
    public abstract double getObvod();
}
