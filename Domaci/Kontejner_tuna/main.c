//////////////////////////////////////////////////////
//                  Jakub Andrysek                  //
//                    2019-10-15                    //
//  Program na pocitani vahy baliku v kontejneru C  //
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kontejner = 1000;
    int novy = 0;
    int celkem = 0;
    int pocitadlo = 0;
    printf("Zadej vahu baliku: ");

    scanf("%d", &novy);
    while ((novy+celkem)<kontejner){
        pocitadlo++;
        celkem+=novy;
        printf("Pocet baliku: %d\n", pocitadlo);
        printf("Zbyva doplnit: %d kg\n\n", (kontejner-celkem));

        printf("Zadej vahu baliku: ");
        scanf("%d", &novy);
    }
    printf("\nBalik se jiz nevejde\n");
    printf("Pocet baliku: %d\n", pocitadlo);
    printf("Celkem: %d kg\n", (celkem));
    printf("Konec\n");


    return 0;
}
