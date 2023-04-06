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
public class BubbleSortAlgorithm extends Radic {

    @Override
    public String toString() {
        return "BubbleSortAlgorithm";
    }


    @Override
    public Integer[] serad(Integer[] array) {
        Integer[] arraySorted = new Integer[array.length];
        for (int i = 0; i < array.length; i++)
        {
            arraySorted[i] = array[i];
        }
        for (int i = 0; i < arraySorted.length; i++)
        {
            for (int j = 0; j < arraySorted.length - 1; j++)
            {
                if (arraySorted[j] > arraySorted[j + 1])
                {
                    Integer temp = arraySorted[j];
                    arraySorted[j] = arraySorted[j + 1];
                    arraySorted[j + 1] = temp;
                }
            }
        }
        return arraySorted;
    }
}
