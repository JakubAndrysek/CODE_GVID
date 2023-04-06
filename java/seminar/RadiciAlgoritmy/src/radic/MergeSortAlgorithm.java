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
public class MergeSortAlgorithm extends Radic {

    @Override
    public Integer[] serad(Integer[] array) {
        // sort using merge sort algorithm
        Integer[] arraySorted = new Integer[array.length];
        for (int i = 0; i < array.length; i++)
        {
            arraySorted[i] = array[i];
        }
        arraySorted = mergeSort(arraySorted);
        return arraySorted;
    }

    private Integer[] mergeSort(Integer[] array) {
        if (array.length <= 1)
        {
            return array;
        }
        Integer[] left = new Integer[array.length / 2];
        Integer[] right = new Integer[array.length - left.length];
        System.arraycopy(array, 0, left, 0, left.length);
        System.arraycopy(array, left.length, right, 0, right.length);
        mergeSort(left);
        mergeSort(right);
        merge(left, right, array);
        return array;
    }

    private void merge(Integer[] left, Integer[] right, Integer[] result) {
        int i1 = 0;
        int i2 = 0;
        int j = 0;
        while (i1 < left.length && i2 < right.length)
        {
            if (left[i1] < right[i2])
            {
                result[j] = left[i1];
                i1++;
            }
            else
            {
                result[j] = right[i2];
                i2++;
            }
            j++;
        }
        System.arraycopy(left, i1, result, j, left.length - i1);
        System.arraycopy(right, i2, result, j, right.length - i2);
    }

    @Override
    public String toString() {
        return "MergeSortAlgorithm";
    }

}
