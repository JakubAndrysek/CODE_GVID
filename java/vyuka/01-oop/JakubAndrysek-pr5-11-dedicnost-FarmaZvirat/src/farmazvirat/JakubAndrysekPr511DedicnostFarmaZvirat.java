/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package farmazvirat;

import java.util.ArrayList;
import zoo.Zvire;
import zoo.Pes;
import zoo.Ptak;
import zoo.Kocka;
import zoo.Krava;


/**
 *
 * @author andrysekj
 */
public class JakubAndrysekPr511DedicnostFarmaZvirat {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Pes pes = new Pes("Alik", 2);
        Ptak andulka = new Ptak("Julca");
        
        System.out.println(pes);
        System.out.println(andulka);
        
        System.out.println(pes.vydejZvuk());
        System.out.println(andulka.vydejZvuk());
        
        System.out.println("Polymorfismus");
        ArrayList<Zvire> z = new ArrayList<Zvire>();
        
        z.add(new Pes("Fousek", 2, "Alik"));
        z.add(new Pes("Vlcak", 3, "Azor"));
        z.add(new Ptak("asd", 4, "Arara"));
        z.add(new Kocka("Micka"));
        z.add(new Krava("Liza"));
        
        for(Zvire zvire : z) {
            System.out.println(zvire.vydejZvuk() + " - " + zvire + " (" + zvire.getClass().getName() + ")");
        }         
    }
}
