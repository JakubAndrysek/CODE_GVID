/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package array;

import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author kuba
 */
public class ArrayPair {
    private Integer[] arrayRandom;
    private Integer[] arraySorted;
    private String arrayType;

    public ArrayPair(Integer[] arrayRandom, Integer[] arraySorted, String arrayType) {
        this.arrayRandom = arrayRandom;
        this.arraySorted = arraySorted;
        this.arrayType = arrayType;
    }

    public Integer[] getArrayRandom() {
        return arrayRandom;
    }

    public Integer[] getArraySorted() {
        return arraySorted;
    }

    public String getArrayType() {
        return arrayType;
    }

    public void setArrayRandomWithSorted(Integer[] arraySortedByAlgorithm) {
        this.arrayRandom = arraySortedByAlgorithm;
    }

    public Boolean isEqual() {
        return Arrays.equals(arrayRandom, arraySorted);
    }

    @Override
    public String toString() {
        return "ArrayTuple {\n   arrayRandom=" + Arrays.toString(arrayRandom) + "\n   arraySorted=" + Arrays.toString(arraySorted) + "\n   arrayType=" + arrayType + "\n}";
    }
}
