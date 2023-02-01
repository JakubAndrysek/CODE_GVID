/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package radic;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author kuba
 */
public class MergeSortAlgorithm implements Radic {

    @Override
    public void serad(ArrayList<Integer> array) {
        System.out.println("radic.MergeSortAlgorithm.serad()");
        
        try {
//            TimeUnit.MICROSECONDS.sleep((long) 9000);
            TimeUnit.MILLISECONDS.sleep(5);
        } catch (InterruptedException ex) {
            Logger.getLogger(BubbleSortAlgorithm.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
