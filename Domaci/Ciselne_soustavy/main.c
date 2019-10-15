
#include <stdio.h>
#include <stdlib.h>

#define showNK false

int From=10, To=2, Number=33;


void From10(int input, int to){
    int output[100];
    int i=0, p=0;

    printf("Desitkova:%d->Dvojkova:",input);
    //Zbutek po deleni 2; celociselne deleni 2
    while(input!=0)
    {
        output[p] = input % to;
        input = input / to;
        //printf("C: %d|%d \n",input,output);
        p++;
    }
    //Vypis binarniho cisla
    for(i=p-1;i>=0;i--){
        printf("%d",output[i]);
    }
}


int main()
{
    printf("Ahoj, ja jsem inteligentni prevodnik ciselnych soustav NUKON\n\n");

    while(1){
        //Z jake soustavy
        printf("Z jake soustavy chces prevadet?\n");
        printf("2-Dvojkove; -Ctyrkove; 3-Osmickove; 4-Desitkove; 5-Sestnactkove\n");
        scanf("%d", &From);
        printf("Cislo: %d \n",From);
        //Do jake soustavy
        printf("Do jake soustavy chces prevadet?\n");
        printf("1-Dvojkove; 2-Ctyrkove; 3-Osmickove; 4-Desitkove; 5-Sestnactkove\n");
        scanf("%d", &To);
        printf("Cislo: %d \n",To);
        //Cislo
        printf("Zadej cele cislo:\n");
        scanf("%d", &Number);

        switch(From)
        {
            case 10:  //DESITKOVA
                From10(Number,To);
        }


        break;
    }

    return 0;
}
