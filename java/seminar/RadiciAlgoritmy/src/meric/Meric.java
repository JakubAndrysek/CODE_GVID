/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package meric;

import array.ArrayGenerator;
import array.ArrayPair;
import java.util.ArrayList;
import java.util.List;
import radic.BubbleSortAlgorithm;
import radic.InsertSortAlgorithm;
import radic.InsertZarazkaSortAlgorithm;
import radic.JavaSortAlgorithm;
import radic.MergeSortAlgorithm;
import radic.Radic;
import radic.SelectionSortAlgorithm;

/**
 *
 * @author kuba
 */
public class Meric {

    Radic radic;
    List<MericItem> mericItemList = new ArrayList<>();
    List<ArrayPair> arraysForTests = new ArrayList<>();
    ArrayGenerator arrayGenerator = new ArrayGenerator();

    StopWatch stopWatch;

    public Meric() {

    }



    Radic[] radicArr = {
        new JavaSortAlgorithm(),
        new BubbleSortAlgorithm(),
        new MergeSortAlgorithm(),
        new SelectionSortAlgorithm(),
        new InsertSortAlgorithm(),
//        new InsertZarazkaSortAlgorithm(), // neni dokoncen
    };

    public void showResults() {
        System.out.println("Vysledky mereni");
        for (MericItem mericItem : mericItemList) {
            System.out.println(mericItem.toString());
        }
    }


    public void zmerData(int numberOfTests) {
        System.out.println("Pripravuji se na mereni");

        final int arraySize = 5;

        arraysForTests.add(arrayGenerator.generateSortedArray(arraySize));
        arraysForTests.add(arrayGenerator.generateReverseArray(arraySize));
        arraysForTests.add(arrayGenerator.generateRandomArray(arraySize));
        arraysForTests.add(arrayGenerator.generateSameArray());

        for (ArrayPair arrayPair : arraysForTests) {

            for (Radic radicActual : radicArr) {
                stopWatch = new StopWatch();
                setRadic(radicActual);


                Boolean isSuccessful = true;
                for (int counter = 0; counter < numberOfTests; counter++) {
                    stopWatch.start();
                    arrayPair.setArrayRandomWithSorted(radic.serad(arrayPair.getArrayRandom()));
                    stopWatch.stop();


                    if(!arrayPair.isEqual()) {
                        isSuccessful = false;
                        break;
                    }
                }

                mericItemList.add(new MericItem(radicActual.toString(), stopWatch, arrayPair.getArrayType(), isSuccessful));


            }

            System.out.println("Konec mereni");

            this.showResults();


        }

    }

    private void setRadic(Radic newRadic) {
        radic = newRadic;
    }
}
