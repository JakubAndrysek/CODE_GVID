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
import radic.JavaSortAlgorithm;
import radic.MergeSortAlgorithm;
import radic.Radic;

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
//        new JavaSortAlgorithm(),
        new BubbleSortAlgorithm(),
//        new MergeSortAlgorithm(),
    };
    
    
    public void zmerData() {
        System.out.println("Pripravuji se na mereni");
        
        final int arraySize = 8000;
        
//        arraysForTests.add(arrayGenerator.generateSortedArray(arraySize));
//        arraysForTests.add(arrayGenerator.generateReverseArray(arraySize));
        arraysForTests.add(arrayGenerator.generateRandomArray(arraySize));
        
        for (ArrayPair arrayPair : arraysForTests) {
            
            for (Radic radicActual : radicArr) {
                stopWatch = new StopWatch();
                setRadic(radicActual);



                for (int counter = 0; counter < 1; counter++) {
                    stopWatch.start();
                    radic.serad(arrayPair.getArrayRandom().clone());
                    stopWatch.stop();


                    if(!arrayPair.isEqual()) {
                        System.out.println("Not same " + counter);
                        System.exit(0);
                    }
                }

                System.out.println(stopWatch);

                mericItemList.add(new MericItem(stopWatch, radic.toString()));
            } 
            
            System.out.println()
            
            
        }
        
        


            
    }
    
    private void setRadic(Radic newRadic) {
        radic = newRadic;
    }
}
