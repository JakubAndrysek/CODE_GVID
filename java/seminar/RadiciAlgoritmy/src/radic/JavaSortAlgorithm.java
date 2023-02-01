/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package radic;

import java.text.CollationElementIterator;
import java.util.ArrayList;
import java.util.Collections;


/**
 *
 * @author kuba
 */
public class JavaSortAlgorithm implements Radic {

    @Override
    public String toString() {
        return "JavaSortAlgorithm";
    }

    @Override
    public void serad(ArrayList<Integer> array) {
//        System.out.println("radic.JavaSortAlgorithm.serad()");
        Collections.sort(array);
    }
    
    
    
}
