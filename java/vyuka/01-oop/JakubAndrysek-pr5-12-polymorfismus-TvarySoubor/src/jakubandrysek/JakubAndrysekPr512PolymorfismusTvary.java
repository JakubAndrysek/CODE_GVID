/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package jakubandrysek;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import tvary.Bod;
import tvary.Ctverec;
import tvary.Kruh;
import tvary.Obdelnik;
import tvary.Trojuhelnik;
import tvary.Tvar;
import tvary.TvarReader;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author andrysekj
 */
public class JakubAndrysekPr512PolymorfismusTvary {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        ukol1();
        ukol2();

    }
    
    static void ukol2() {
        String fileName = "tvary.txt";
        
        TvarReader tvarReader = new TvarReader(fileName);
        
//        tvarReader.ins
        
//        System.out.println("");
        
//        if(!tvarReader.hasNextTvar()) {
//            System.out.println("Nekde nastala chyba / nenealezeno");
//        }
        
        while(tvarReader.hasNextTvar()) {
            try {
                    Tvar tvar = tvarReader.nextTvar();
                    System.out.println("MujTvar: " + tvar);
                
            } catch (FileNotFoundException ex) {
                System.out.println("Soubor se nepodarilo otverit");
            } catch (Throwable e) {
                System.out.println(e.getMessage());
            }
        }
        
        
    }
    
    
    public static double randomDoubleFrmTo(double min, double max) {
        var rand = new Random();
        return rand.nextDouble((max - min) + 1) + min;
    }
    
    static void ukol1() {
                double celkovyObsah = 0;
        double celkovyObvod = 0;
    

        var tvary = new ArrayList<Tvar>();
        
        for(int i = 0; i<=9; i++) {
            var stred = new Bod( randomDoubleFrmTo(20, 80), randomDoubleFrmTo(20, 80));
            
            int tvaryExistIndex = (int)randomDoubleFrmTo(0, 3);
            
            switch (tvaryExistIndex) {
                case 0:
                    tvary.add(new Ctverec(randomDoubleFrmTo(1, 20), stred));
                    break;
                case 1:
                    tvary.add(new Obdelnik(randomDoubleFrmTo(1, 20), randomDoubleFrmTo(1, 20), stred));
                    break;
                case 2:
                    tvary.add(new Kruh(randomDoubleFrmTo(1, 20), stred));
                    break;
                case 3:
                    tvary.add(new Trojuhelnik(randomDoubleFrmTo(1, 20), stred));
                    break;
            }
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
    
}