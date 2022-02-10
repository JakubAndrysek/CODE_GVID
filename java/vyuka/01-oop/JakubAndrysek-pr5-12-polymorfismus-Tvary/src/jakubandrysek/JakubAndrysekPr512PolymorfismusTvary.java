/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package jakubandrysek;

import java.util.ArrayList;
import java.util.Random;
import tvary.Bod;
import tvary.Ctverec;
import tvary.Kruh;
import tvary.Obdelnik;
import tvary.Trojuhelnik;
import tvary.Tvar;

/**
 *
 * @author andrysekj
 */
public class JakubAndrysekPr512PolymorfismusTvary {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        // Tests
//        testKruh();
//        testC-tverec();
//        testTrojuhelnik();
//        testObdelnik();

        double celkovyObsah = 0;
        double celkovyObvod = 0;
    

        var tvary = new ArrayList<Tvar>();
        
        for(int i = 0; i<=9; i++) {
            var stred = new Bod( randomDoubleFrmTo(20, 80), randomDoubleFrmTo(20, 80));
            
            Tvar tvaryExist[] = { // priprav pole moznosti
                new Ctverec(randomDoubleFrmTo(1, 20), stred), 
                new Obdelnik(randomDoubleFrmTo(1, 20), randomDoubleFrmTo(1, 20), stred),
                new Kruh(randomDoubleFrmTo(1, 20), stred),
                new Trojuhelnik(randomDoubleFrmTo(1, 20), stred),
            };
            
            int tvaryExistIndex = (int)randomDoubleFrmTo(0, tvaryExist.length-1); // get number from 0 to tvaryExist.length-1 -> random position
            tvary.add(tvaryExist[tvaryExistIndex]);
        }
        
        int index = 1;        
        for (Tvar tvar : tvary) {
            
            System.out.println(index++ + " - " + tvar);
            celkovyObsah += tvar.getObsah();
            celkovyObvod += tvar.getObvod();
        }
        
        System.out.println("Celkovy OBSAH: " + celkovyObsah);
        System.out.println("Celkovy OBVOD: " + celkovyObvod);
    }
    
    public static double randomDoubleFrmTo(double min, double max) {
        var rand = new Random();
        return rand.nextDouble((max - min) + 1) + min;
    }
    
    
    
    public static void testKruh() {
        var stredKruhu = new Bod(1.5, 2.5);        
        var kruh = new Kruh(1, stredKruhu);
        
        System.out.println(kruh);
        System.out.println("Obvod: " + kruh.getObvod());
        System.out.println("Obsah: " + kruh.getObsah());
    }
    
    public static void testCtverec() {
        var stredKruhu = new Bod(1.5, 2.5);        
        var ctverec = new Ctverec(3, stredKruhu);
        
        System.out.println(ctverec);
        System.out.println("Obvod: " + ctverec.getObvod());
        System.out.println("Obsah: " + ctverec.getObsah());
    }
    
    public static void testObdelnik() {
        var stredObdelniku = new Bod(1.5, 2.5);        
        var obdelnik= new Obdelnik(3, 5, stredObdelniku);
        
        System.out.println(obdelnik);
        System.out.println("Obvod: " + obdelnik.getObvod());
        System.out.println("Obsah: " + obdelnik.getObsah());
    }    
    
    public static void testTrojuhelnik() {
        var stredTrojuhelniku = new Bod(1.5, 2.5);        
        var trojuhelnik = new Trojuhelnik(3, stredTrojuhelniku);
        
        System.out.println(trojuhelnik);
        System.out.println("Obvod: " + trojuhelnik.getObvod());
        System.out.println("Obsah: " + trojuhelnik.getObsah());
    }
}