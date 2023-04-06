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
public abstract class Radic {
    public Integer[] serad(Integer[] array) {
        return array;
    }

    protected void swap(Integer[] array, Integer indexA, Integer indexB) {
        Integer helper = array[indexA];
        array[indexA] = array[indexB];
        array[indexB] = helper;
    }

    @Override
    public String toString() {
        return "abstract Radic{" + '}';
    }
}
