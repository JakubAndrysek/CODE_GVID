/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tvary;

/**
 *
 * @author andrysekj
 */
public final class Bod {
    private final int x;
    private final int y;

    public Bod(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public final int getX() {
        return x;
    }

    public final int getY() {
        return y;
    }
    

    
    public final double vzdalenostKBodu(Bod b) {
        double dx = this.x - b.x;
        double dy = this.y - b.y;
        return Math.sqrt(dx*dx + dy*dy);
    }

    @Override
    public String toString() {
        return "Bod{" + "x=" + x + ", y=" + y + '}';
    }    
}
