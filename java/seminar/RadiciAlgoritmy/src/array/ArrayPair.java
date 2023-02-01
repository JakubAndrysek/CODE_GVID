/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package array;

import java.util.ArrayList;

/**
 *
 * @author kuba
 */
public class ArrayPair {
    private ArrayList<Integer> arrayRandom;
    private ArrayList<Integer> arraySorted;

    public ArrayPair(ArrayList<Integer> arrayRandom, ArrayList<Integer> arraySorted) {
        this.arrayRandom = arrayRandom;
        this.arraySorted = arraySorted;
    }

    public ArrayList<Integer> getArrayRandom() {
        return arrayRandom;
    }

    public ArrayList<Integer> getArraySorted() {
        return arraySorted;
    }
    
    public Boolean isEqual() {
        return this.arrayRandom.equals(this.arraySorted);
    }

    @Override
    public String toString() {
        return "ArrayTuple {\n   arrayRandom=" + arrayRandom + "\n   arraySorted=" + arraySorted + "\n}";
    } 
}
