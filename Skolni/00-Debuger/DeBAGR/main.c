/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>


/**
    Pole má být naplněno posloupností čísel 1, 2, 3, 4, ... 10
    Pomocí debugeru odlaď s co nejmenším počtem zásahů do kódu, aby tomu opravdu
    tak bylo.
**/


int funkce()
{
    int k=5, i=3;
    return (10-k+i*2);
}



int main()
{
    int pole[10];
    int i, j, k, m=7;

    i=j=k=2;

    // v komentářích je předpokládaný index

    pole[m-i]=2+k+2;  // 5

    pole[pole[m-i]-2]= pole[m-i] -1; // 4

    pole[i] = k;  //1

    pole[pole[i]] = m-5+1;   //2

    pole[m-2] = i;  //0

    pole[j+i] = 3*k;   //3

    pole[3+pole[j+i]] = funkce(); //9

    pole[k=3*k] = 8;   //6

    pole[m*4] = pole[k] +1;   //8

    pole[7] = k + 3*i - 2*m;


    return 0;
}
