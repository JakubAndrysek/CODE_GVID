/*
 * Projekt: Doučování pro PR-5
 * Téma: Pole a struktury
 * Autor:
 * Datum:
 */

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...


/**
 * Typ popisující jedno zvíře. Budeme ukládat jeho název a váhu.
 */
typedef struct _tzvire
{
  float vaha;
  char nazev[21];
} Tzvire;

/**
 * Konstantní pole zvířat. Pozor, prvky jsou konstanty a nejde je měnit.
 * Chceme-li pole jen procházet a neměnit, musí mít podprogram parametr typu
 * const Tzvire pole[].
 * Pokud chceme pole a jeho prvky měnit, je nutné si udělat nejprve jeho
 * nekonstantní kopii a pracovat až s ní.
 */
const Tzvire ZOO[11] =
{
  { .nazev = "Slon", .vaha = 1247.7 },
  { .nazev = "Slepice", .vaha = 1.5 },
  { .nazev = "Pes", .vaha = 15.34 },
  { .nazev = "Medved", .vaha = 153.1 },
  { .nazev = "Tchor", .vaha = 6.4 },
  { .nazev = "Husa", .vaha = 2.5 },
  { .nazev = "Houser", .vaha = 3.5 },
  { .nazev = "Tygr", .vaha = 112.2 },
  { .nazev = "Kocour", .vaha = 6.5 },
  { .nazev = "Mys", .vaha = 0.25 },
  { .nazev = "Blecha", .vaha = 2.34e-4 },
};

/** Parametr: zvire - jedno zvíře, které se bude tisknout.
 *
 * Vytvoř funkci, která vytiskne jedno zvíře. Neodřádkovávej.
 * Například slepice se vytiskne takto, včetně závorek:
 * (Slepice, 1.5 kg)
 */
// odkomentování: označit, pak Shift+Ctrl+X
//     tiskniZvire(       zvire)
//{
//
//}

/** Parametry: zvirata a kolik. Parametr zvirata bude konstantní pole nad
 *  typem Tzvire. Parametr kolik říká, kolik zvířat z pole se má vytisknout.
 *
 * Vytiskni všechna zvířata v poli. Použij při tom podprogram tiskniZvire.
 * Jednotlivá zvířata odděl čárkou a mezerou. Nakonec odřádkuj.
 * Příklad:
 * (Slon, 1247.7 kg), (Slepice, 1.5 kg), (Pes, 15.34 kg)
 */
// odkomentování: označit, pak Shift+Ctrl+X
//     tiskniZvirata(const        zvirata  ,     kolik)
//{
//
//
//
//
//
//
//
//
//}

/**
 * Úkol č. 1
 * a. Vytvoř funkce tiskniZvire a tiskniZvirata.
 * b. Vytiskni všechna zvířata, která jsou v konstantním poli ZOO, které je
 *    vyrobeno výše --> použij na to funkci tiskniZvirata.
 */
void ukol1(void)
{
  printf("V ZOO jsou tato zvirata:\n");
  // vytiskni zvířata v ZOO (je jich 11)

}







/** Parametry: odkud, kam, kolik.
 *  Parametr odkud je konstantní pole zvířat,
 *  parametr kam je obyčejné pole zvířat,
 *  parametr kolik je počet prvků pole, které se budou kopírovat.
 *
 * Vytvoř podprogram, který zkopíruje zadaný počet prvků z pole odkud do pole
 * kam.
 */
//     kopirujZoo(   )
//{
//
//
//
//
//}

/** Parametry: zvire - předávané odkazem, procenta - číslo od 0 do 1,
 *  kde 0 znamená 0 % a 1 znamená 100 %.
 *
 * Uprav váhu zadaného zvířete o zadaný počet procent. Zvíře se předává odkazem.
 */
//     upravVahu(   )
//{
//
//}

/** Parametry: zoo - pole zvířat, kolik - počet prvků pole, procenta - číslo
 *  od 0 do 1, kde 0 znamená 0 % a 1 znamená 100 %.
 *
 * Uprav váhu všem zvířatům v zoo o zadaný počet procent.
 */
//     upravVahuVsem(    )
//{
//
//
//
//
//}

/** Funkce, která vrací desetinné číslo.
 *  Parametry: zoo - pole zvířat, kolik - délka pole.
 *
 * Vytvoř funkci, která sečte váhy všech zvířat v poli a vrátí ji jako svou
 * funkční hodnotu.
 */
//      celkovaVaha(   )
//{
//
//
//
//
//
//
//}

/**
 * Úkol č. 2
 * a. Vytvoř výše naznačené podprogramy.
 * b. Použij je.
 */
void ukol2(void)
{
  // vyrob pole noveZoo o délce 5 zvířat

  // kopíruj 5 prvků z konstanty ZOO do pole noveZoo

  printf("Nove zoo pred krmenim:\n");
  // vytiskni zvířata z noveZoo

  // Vytiskni text: "Zvirata vazi celkem XXX kg." a odřádkuj.


  printf("Nove zoo po krmeni:\n");
  // Zvyš váhu všech zvířat v noveZoo o 5 % (to je 0.05).

  // Vytiskni zvířata z noveZoo

  // Vytiskni text: "Zvirata vazi celkem XXX kg." a odřádkuj.

}






/** Parametry: zoo - pole zvířat, delka - délka pole.
 *
 * Seřaď zvířata v zoo podle váhy vzestupně.
 */
//     serad(  )
//{
//
//
//
//
//
//
//
//
//
//
//
//}

/**
 * Úkol č. 3
 * a. Vytvoř si kopii ZOO do nové proměnné noveZoo (všech 11 prvků).
 * b. Seřaď noveZoo a vypiš zvířata seřazená podle váhy.
 */
void ukol3(void)
{



  printf("Serazene zoo:\n");

}


int main(void)
{
  printf("*** Ukol c. 1 ***\n");
  ukol1();
  printf("-----------------\n");

  printf("*** Ukol c. 2 ***\n");
  ukol2();
  printf("-----------------\n");

  printf("*** Ukol c. 3 ***\n");
  ukol3();
  printf("-----------------\n");
  return 0;
}
