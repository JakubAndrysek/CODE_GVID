/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package radic;

import java.util.ArrayList;


/**
 *
 * @author kuba
 */
public class BubbleSortAlgorithm implements Radic {

    @Override
    public String toString() {
        return "BubbleSortAlgorithm";
    }
    
    public void swap(ArrayList<Integer> array, int a, int b) {
        int pom = array.get(a);
        array.set(a, array.get(b));
        array.set(b, pom);
    }
    
    public void print(ArrayList<Integer> array) {
//        for (int i = 0; i < array.size(); i++) {
//            System.out.printf("%d, ", array.get(i));
//        }
//        System.out.println("\n");
    }

    @Override
    public void serad(ArrayList<Integer> array) {
        System.out.println("radic.BubbleSortAlgorithm.serad()");
       int size = array.size();
        
        print(array);
        for(int neserazeno = 0; neserazeno < size-1; neserazeno++) {
            for(int radimI = size-1; radimI >= neserazeno+1 ; radimI--) {
                if(array.get(radimI-1) > array.get(radimI)) {
                    swap(array, radimI, radimI-1);
                }
                print(array);
            }
        }   
    }
}
