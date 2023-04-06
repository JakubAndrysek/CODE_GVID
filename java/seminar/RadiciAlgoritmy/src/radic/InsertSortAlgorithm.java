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
public class InsertSortAlgorithm extends Radic {

    @Override
    public String toString() {
        return "InsertSortAlgorithm";
    }


    @Override
    public Integer[] serad(Integer[] array) {
        Integer[] arrSor = new Integer[array.length];
        System.arraycopy(array, 0, arrSor, 0, array.length);

        for(int d = 1; d < arrSor.length; d++) {
            int vkladany = arrSor[d];
            int i = d;
            while(i > 0 && arrSor[i-1] > vkladany) {
                arrSor[i] = arrSor[i-1];
                i--;
            }
            arrSor[i] = vkladany;
        }
        return arrSor;
    }
}
