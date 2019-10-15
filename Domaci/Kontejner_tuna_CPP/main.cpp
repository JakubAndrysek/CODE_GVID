//////////////////////////////////////////////////////////
//                  Jakub Andrysek                      //
//                    2019-10-15                        //
//  Program na pocitani vahy baliku v kontejneru CPP    //
//////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>  //pro printf
#include <stdlib.h> //pro printf
#include "Kontejner.h"

using namespace std;

int main()
{
    printf("Kontejner_tuna_CPP\n");
    Kontejner box(1000);        //konstruktor + velikosrt kontejneru
    box.Nacteni();              //nacteni baliku
    while ((box.Novy()+box.Celkem())<=box.MaxVaha())    //opakuj dokud se do kontejneru vleze
    {
        box.PocitadloPlus();    //pocitadlo++
        box.NovyToCelkem();     //pripocitani noveho baliku
        box.Info();             //vypis informaci

        box.Nacteni();          //Nacteni baliku
    }
    box.Konec();                //vypis informaci + konec

    return 0;
}
