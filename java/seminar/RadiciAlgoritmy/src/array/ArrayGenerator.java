/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package array;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/**
 *
 * @author kuba
 */
public class ArrayGenerator {

    public ArrayGenerator() {
    }
    
    private ArrayList<Integer> generateSortedList(int n, int step){
        ArrayList<Integer> list = new ArrayList<>(n);
        Random random = new Random(5);
        int startNumber = random.nextInt(10);
    
        for (int i = 0; i < n; i++)
        {
            startNumber += random.nextInt(step);
            list.add(startNumber);
        }
        return list;
    }
    
   
    public ArrayPair generateSortedArray(int n) {
        ArrayList<Integer> list = generateSortedList(n, 5);
        return new ArrayPair(list, list);
    }
    
    public ArrayPair generateReverseArray(int n) {
        ArrayList<Integer> listSorted = generateSortedList(n, 5);
        ArrayList<Integer> listReverse = (ArrayList) listSorted.clone();
        Collections.reverse(listReverse);
        return new ArrayPair(listReverse, listSorted);
    }
    
    public ArrayPair generateRandomArray(int n) {
        ArrayList<Integer> listSorted = generateSortedList(n, 10);
        ArrayList<Integer> listRandom = (ArrayList) listSorted.clone();
        Collections.shuffle(listRandom);
        return new ArrayPair(listRandom, listSorted);
    }
    
    public ArrayPair generateSameArray(int n, int step) {
        ArrayList<Integer> listSorted = generateSortedList(n, 10);
        ArrayList<Integer> listRandom = (ArrayList) listSorted.clone();
        Collections.shuffle(listRandom);
        return new ArrayPair(listRandom, listSorted);
    }
    
}
