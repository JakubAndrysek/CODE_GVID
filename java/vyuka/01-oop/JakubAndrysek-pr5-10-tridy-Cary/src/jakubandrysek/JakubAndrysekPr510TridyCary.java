package jakubandrysek;

import bod.Bod;
import java.util.Scanner;

/**
 *
 * @author kuba
 */
public class JakubAndrysekPr510TridyCary {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Bod bod1 = new Bod(4, 4);
        
        double vzdalenost = bod1.vzdalenost(1, 1);
        
        System.out.println("Vzdalenost bodu:" + vzdalenost);
        
        Bod bod2 = new Bod(1, 1);
        double vz2 = bod1.vzdalenost(bod2);
        System.out.println("Vzdalenost2: " + vz2);
    }
    
    protected double nactiCislo(String souradnice) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Zadej souradnici %s: ", souradnice);
        double sourdnice = sc.nextDouble();
        return sourdnice;
    }
    
    public double celaCara() {
        double bod1X = nactiCislo("X");
        double bod1Y = nactiCislo("Y");
        
        System.out.printf("X: %f; Y: %f", bod1X, bod1Y);
        
        return 0;
    }
    
}

