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

    private Integer[] generateSortedList(int n, int step, int seed){
        Integer[] array = new Integer[n];
        Random random = new Random(seed);
        int startNumber = random.nextInt(10);
        for (int i = 0; i < n; i++)
        {
            startNumber += random.nextInt(step);
            array[i] = startNumber;
        }
        return array;
    }


    public ArrayPair generateSortedArray(int n) {
        int randomSeed = new Random().nextInt();
        Integer[] list = generateSortedList(n, 5, randomSeed);
        return new ArrayPair(list, list, "Sorted");
    }

    public ArrayPair generateReverseArray(int n) {
        int randomSeed = new Random().nextInt();
        Integer[] list = generateSortedList(n, 5, randomSeed);
        Integer[] listReverse = new Integer[n];
        for (int i = 0; i < n; i++)
        {
            listReverse[i] = list[n - i - 1];
        }
        return new ArrayPair(listReverse, list, "Reverse");
    }

    public ArrayPair generateRandomArray(int n) {
        int randomSeed = new Random().nextInt();
        Integer[] list = generateSortedList(n, 5, randomSeed);
        ArrayList<Integer> listRandom = new ArrayList<>();
        for (int i = 0; i < n; i++)
        {
            listRandom.add(list[i]);
        }
        Collections.shuffle(listRandom);
        Integer[] listRandomArray = new Integer[n];
        for (int i = 0; i < n; i++)
        {
            listRandomArray[i] = listRandom.get(i);
        }
        return new ArrayPair(listRandomArray, list, "Random");
    }

    public ArrayPair generateSameArray() {
        // 5 2 1 5 4 5 0 1 2 7 3 - from presentation
        Integer[] listSame = {5, 2, 1, 5, 4, 5, 0}; //, 1, 2, 7, 3};
        Integer[] list = {0, 1, 2, 4, 5, 5, 5}; //, 1, 2, 7, 3};

        return new ArrayPair(listSame, list, "[Every time the same array]");
    }

}
