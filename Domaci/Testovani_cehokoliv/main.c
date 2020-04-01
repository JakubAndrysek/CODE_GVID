#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int Digits(int number){
    int count = 0;
    while(number != 0)
    {
        number /= 10;
        ++count;
    }
    //printf("%d", count);
    return count;
}

int pole[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void ToLen(int cislo, int *pole[]){
    printf("ASD");
    int i = 0;

    int dig = Digits(cislo);

    int poc = dig-1;
    for (i; i<dig; i++){
        //printf("%d\n", cislo%10);
        *pole[poc]=cislo%10;
        poc--;
        cislo/=10;
    }

    int p = dig;
    for(i=0;i<20;i++){
        printf("%d",*pole[i]);
    }


}

int main()
{
    int a[100];

    ToLen(1554548, &a);

    return 0;







    return 0;
}
