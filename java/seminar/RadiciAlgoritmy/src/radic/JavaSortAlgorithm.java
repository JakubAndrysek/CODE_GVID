/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package radic;

import java.text.CollationElementIterator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


/**
 *
 * @author kuba
 */
public class JavaSortAlgorithm extends Radic {

    @Override
    public String toString() {
        return "JavaSortAlgorithm";
    }

    @Override
    public Integer[] serad(Integer[] array) {
        ArrayList<Integer> list = new ArrayList<>();
        list.addAll(Arrays.asList(array));
        Collections.sort(list);
        Integer[] arraySorted = new Integer[array.length];
        for (int i = 0; i < array.length; i++)
        {
            arraySorted[i] = list.get(i);
        }
        return arraySorted;
    }
}