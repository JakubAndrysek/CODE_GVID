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
public class SelectionSortAlgorithm extends Radic {

    @Override
    public String toString() {
        return "SelectionSortAlgorithm";
    }


    @Override
    public Integer[] serad(Integer[] array) {
        Integer[] arrSor = new Integer[array.length];
        System.arraycopy(array, 0, arrSor, 0, array.length);

        for(int d = 0; d < arrSor.length-1; d++) { // array.length-1 = přehážu vše kromě největšího prvku → již je největší, takže neměním
            int minIndex = d;
            for(int x = d+1; x < arrSor.length; x++) { // d+1 = již seřazené prvky – hledám v následujících
                int xNum = arrSor[x];
                int dNum = arrSor[minIndex];
                if(xNum < dNum) {
                    minIndex = x;
                }
            }
            swap(arrSor, minIndex, d);
        }
        return arrSor;
    }
}
