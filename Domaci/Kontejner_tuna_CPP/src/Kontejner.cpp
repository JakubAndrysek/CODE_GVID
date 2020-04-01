#include "Kontejner.h"

Kontejner::Kontejner(int _max_vaha)
{
    d_max_vaha=_max_vaha;
    printf("Maximalni vaha v kg: %d\n", _max_vaha);
}

int Kontejner::MaxVaha()
{
    return d_max_vaha;
}

int Kontejner::Celkem()
{
    return d_celkem;
}

int Kontejner::Novy()
{
    return d_novy;
}

int Kontejner::Pocitadlo()
{
    return d_pocitadlo;
}
void Kontejner::PocitadloPlus()
{
    d_pocitadlo++;
}

void Kontejner::NovyToCelkem()
{
    d_celkem+=d_novy;
}

void Kontejner::Info()
{
    printf("Pocet baliku: %d\n", d_pocitadlo);
    printf("Zbyva doplnit: %d kg\n\n", (d_max_vaha-d_celkem));
}

void Kontejner::Konec()
{
    printf("\nBalik se jiz nevejde\n");
    printf("Pocet baliku: %d\n", d_pocitadlo);
    printf("Celkem: %d kg\n", (d_celkem));
    printf("Konec\n");
}

void Kontejner::Nacteni()
{
    printf("Zadej vahu baliku v kg: ");
    scanf("%d", &d_novy);
}
