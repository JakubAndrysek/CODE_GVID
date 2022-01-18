#ifndef KONTEJNER_H
#define KONTEJNER_H

#include <stdio.h>
#include <stdlib.h>


class Kontejner
{
    public:
        Kontejner(int _max_vaha);
        int MaxVaha();
        int Celkem();
        int Novy();
        int Pocitadlo();
        void PocitadloPlus();
        void Nacteni();
        void NovyToCelkem();
        void Info();
        void Konec();
    protected:

    private:
        int d_max_vaha = 1000;
        int d_celkem = 0;
        int d_novy = 0;
        int d_pocitadlo = 0;

};

#endif // KONTEJNER_H
