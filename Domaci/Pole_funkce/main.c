/*
**  Pole_funkce
**
**  Prace s ciselnym polem
**
**  Jakub Andrysek 17.9.2019
*/

#include <stdio.h>
#include <stdlib.h>

#define ArraySize 20

int Array[ArraySize] = {1,2,3,4,5,6,7,8};

void NL(){  //Odradkovani
    printf("\n");
}

void ArrayEdit(int Arrey[], int position, int newnum){  //zmena cisla na pozici
    Array[position] = newnum;
}

void ArrayAdd(int Array[], int position, int newnum){   //pridani pozice
    int i = ArraySize-1;
    for (i; i>=position; i--){
        if (Array[i]!=0){
            Array[i+1] = Array[i];
        }
    }
    ArrayEdit(Array,position,newnum);
}

void ArrayDel(int Array[], int position){   //odebrani pozice
    int i = ArraySize-1;
    for (i=position; i<=ArraySize; i++){
        if (Array[i]!=0){
            Array[i] = Array[i+1];
        }
    }

}

void ArrayPrint(int Array[]){ //vypis Array
    int i;
    for (i= 0; i<ArraySize; i++){
        printf("%i", Array[i]);
    }
    NL();
}

int main()
{
    int k, l ,m ,n;

    printf("Prace s ciselnym polem\n");

    ArrayPrint(Array);
    //ArrayEdit(Array,0,8);
    //ArrayAdd(Array,2,9);

    for(k=0; k<ArraySize; k++){
        ArrayDel(Array,0);
    }
    ArrayPrint(Array);

    for(k=0; k<8; k++){
        ArrayAdd(Array,k,k+1);
    }
    ArrayPrint(Array);
    return 0;

}
