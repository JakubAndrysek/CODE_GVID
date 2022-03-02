/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package jakubandrysek;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

/**
 *
 * @author andrysekj
 */
public class JakubAndrysekPr512Seznamy {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
//        test1();
//        test2();
        test3();
    }
    
    /**
     * Serazovani seznamu
     */
    public static void test1() {
        var seznam = new ArrayList<Double>(); // mohl by být i LinkedList<Double>var seznam = new ArrayList<Double>(); // mohl by být i LinkedList<Double>
        
        
        seznam.add(2.5); // Přidání prvku
        seznam.add(1.8); // Přidání prvku
        seznam.add(78.0); // Přidání prvku
        seznam.add(30.5); // Přidání prvku
        seznam.add(30.6); // Přidání prvku
        seznam.add(14.8); // Přidání prvku
        seznam.add(-48.0); // Přidání prvku
        
        System.out.println(seznam); // seznam pred serazenim
        
        Collections.sort(seznam); // standartni razeni A-Z
        
        System.out.println(seznam); // seznam po serazeni
        
        Collections.sort(seznam, Collections.reverseOrder()); // razeni opeacne Z-A
        
        System.out.println(seznam); // seznam po serazeni - opacne
    }
    
    /**
     * Indexovani + prochazeni seznamu
     */
    public static void test2() {
        var seznam = new LinkedList<Double>();
        
        seznam.add(2.5); // Přidání prvku
        seznam.add(1.8); // Přidání prvku
        seznam.add(78.0); // Přidání prvku
        seznam.add(30.5); // Přidání prvku
        seznam.add(30.6); // Přidání prvku
        seznam.add(14.8); // Přidání prvku
        seznam.add(-48.0); // Přidání prvku
        
        System.out.println("Prvky: " + seznam); // vypis seznamu
        
        // Indexování prvku
        double prvek0 = seznam.get(0); // parametrem je index -- pořadové číslo
        System.out.println("Prvni prvek [0]: " + prvek0);
        
        // For each
        for (Double prvek : seznam) {
            System.out.println(prvek);
        } 
    }
    
    public static void test3() {
        var seznam = new LinkedList<Double>();
        
        seznam.add(2.5); // Přidání prvku
        seznam.add(1.8); // Přidání prvku
        seznam.add(78.0); // Přidání prvku
        seznam.add(-30.5); // Přidání prvku
        seznam.add(30.6); // Přidání prvku
        seznam.add(14.8); // Přidání prvku
        seznam.add(-48.0); // Přidání prvku
        
        System.out.println("Prvky: " + seznam); // vypis seznamu
        
        seznam.remove(5); // odstran prvek na indexu 5 (6. prvek)
        
        for (Iterator<Double> iterator = seznam.iterator(); iterator.hasNext();) {
            Double prvek = iterator.next();
            
            // smaz zaporne prvky
            if(prvek < 0.0) {
                iterator.remove();
                System.out.println("Mazu prvek (zaporny):" + prvek);
            }
        }
        
        System.out.println("Prvky (pouze kladne): " + seznam); // vypis seznamu
        
        // odstrani prvky vetsi nez 30
        seznam.removeIf((prvek) -> (prvek > 30));
        
        System.out.println("Prvky (pouze kladne a mensi nez 30): " + seznam); // vypis seznamu
        
        // 
        seznam.forEach((mujPrvek) -> {
            System.out.println(mujPrvek);
        });
    
    }
}
