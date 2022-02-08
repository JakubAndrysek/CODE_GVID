/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bod;

import java.lang.Math;

/**
 *
 * @author kuba
 */
public class Bod {
    protected double x;
    protected double y;
    
    public Bod(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    public double getX() {
        return this.x;
    }
    
    public double getY() {
        return this.y;
    }
    
    public double vzdalenost(double x, double y) {
        double soucet = ((this.x - x)*(this.x - x) + (this.y - y)*(this.y - y));
        return Math.sqrt(soucet);        
    }
    
    public double vzdalenost(Bod b) {
        return vzdalenost(b.x, b.y);
    }
}
