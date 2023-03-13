/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pisnicka;
import java.util.ArrayList;
import zvirata.Husa;
import zvirata.Kachna;
import zvirata.Kure;
import zvirata.Tele;
import zvirata.Veprik;
import zvirata.Zvire;




/**
 *
 * @author kuba
 */
public class frame {
    public static void main(String[] args) {
        String pisnicka = "";
        
        ArrayList<Zvire> zvirata = new ArrayList<>();
        
        zvirata.add(new Kure());
        zvirata.add(new Kachna());
        zvirata.add(new Husa());
        zvirata.add(new Veprik());
        zvirata.add(new Tele());
        
        int index = 1;
        for (Zvire zvire : zvirata) {
            pisnicka += intro(index++);
            pisnicka += zvire.vyslouzil();
            
            for(int i = index-2; i >= 0 ; i--) {
                pisnicka += zvirata.get(i);
//                pisnicka += i;
            }
            pisnicka += outro();
        }
        
        System.err.println(pisnicka);
    }
    
    private static String intro(int poradi) {
        return "Když jsem já sloužil to " + poradi + ". léto,\n";
    }
    
    private static String outro() {
        return "má panenka pláče doma v komoře.\n\n";
    }
    
    
    
    
    
    
    public static void prvniSlokaNaTvrdo(String[] args) {
        String basnicka = "";
        
        basnicka += intro(1);
        Kure kure = new Kure();
        basnicka += kure.vyslouzil();
        basnicka += kure;
        basnicka += outro();
        
        System.out.print(basnicka);
    }
    
}
