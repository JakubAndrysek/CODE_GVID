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
public class InsertZarazkaSortAlgorithm extends Radic {

    @Override
    public String toString() {
        return "InsertZarazkaSortAlgorithm";
    }


    @Override
    public Integer[] serad(Integer[] array) {
        Integer[] arrSor = new Integer[array.length +1]; // o jedna delsi kvuli zarazce
        System.arraycopy(array, 0, arrSor, 0, array.length);
        int len = arrSor.length;

        for(int d = len-3; d > 0; d--) {
            arrSor[len-1] =  arrSor[d];
            int i = d;
            while(arrSor[len-1] > arrSor[i+1]) {
                arrSor[i] = arrSor[i+1];
                i--;
            }
            arrSor[i] = arrSor[len-1];
        }
        return arrSor;
    }
}
