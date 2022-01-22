/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package kalkulacka.jakubandrysek;

import java.util.Scanner;



/**
 *
 * @author andrysekj
 */
public class KalkulackaJakubAndrysek {

    public static void hlavicka() {
        System.out.println("Kalkulacka ");
        System.out.println("Autor: Jakub Andrysek");
    }
    
    public static float nactiCislo(String dotaz, Scanner scanner) {
        System.out.println(dotaz);
        float read = scanner.nextFloat();
        return read;
    }
    
    private static String nactiOperaci(String dotaz, Scanner scanner) {
        System.out.println(dotaz);
        scanner.nextLine();
        String operace = scanner.nextLine();
        return operace;
    }
    
    private static float kalkulacka(float x, String operace, float y) {
        float vysledek = 0;
        switch (operace) {
            case "+":
                vysledek = x + y;
                break;
            case "-":
                vysledek = x - y;
                break;
            case "*":
                vysledek = x * y;
                break;
            case "/":
                if(y == 0) {
                    throw new ArithmeticException("Nulou nelze delit");
                }
                vysledek = x / y;
            default:
                throw new ArithmeticException("Neznama operace");
        }
        return vysledek;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        hlavicka();
        Scanner scanner = new Scanner(System.in);
        
        float x = nactiCislo("Zadej prvni cislo", scanner);
        
        String operace = nactiOperaci("Zadej operaci:", scanner);
        
        float y = nactiCislo("Zadej druhe cislo", scanner);
        
        float vysledek = 0;
        boolean endWithError = false;
        
        try {
            vysledek = kalkulacka(x, operace, y);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            endWithError = true;
        } finally {
            if(!endWithError) {
                System.out.println("Vysledek je: " + vysledek);                
            }

        }
        
    }
    
}
