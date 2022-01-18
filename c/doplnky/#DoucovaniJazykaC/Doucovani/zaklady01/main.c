/*
 * Projekt: Doučování 1
 * Téma: Proměnné a podprogramy
 * Autor:
 * Datum:
 * 
 * Poznámka: Za komentářem se zadáním je obvykle zakomentovaná hlavička
 * funkce, kterou máš doplnit. Dále je tu vynechaný prostor pro tvé řešení.
 * Délka vynechaného prostoru zhruba odpovídá délce očekávaného řešení.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...


/**
 * Úkol 1
 * a. Vytvoř proměnné znak, cele a real.
 *    Použij datové typy pro znak, celé číslo a desetinné číslo.
 * b. Inicializuj je hodnotami a, 17 a 15.18964.
 * c. Vytiskni je na standardní výstup (obrazovku) takto, včetně zarovnání:
 * Promenna znak je     a.
 * Promenna cele je    17.
 * Promenna real je 15.19.
 *
 * Otázky:
 * Co je to proměnná?
 * -
 * Co je to datový typ?
 * -
 * Co je to deklarace proměnné?
 * -
 * Co je to inicializace proměnné?
 * -
 */
void ukol1(void)
{
  printf("Není implementováno.\n"); // to smaž
  // a. + b.
  
  
  
  // c.
  
  
  
}

/**
 * Úkol 2a (nejprve se podívej na úkol 2, viz dále)
 * Vytvoř funkci zadejCele, která vytiskne uživateli text uložený v parametru 
 * pojmenovaném dotaz. Funkce poté přečte od uživatele celé číslo a vrátí jej
 * jako funkční hodnotu.
 */
//    zadejCele(char *dotaz)






/** 
 * Úkol 2b (nejprve se podívej na úkol 2, viz dále)
 * Vytvoř funkci jePrvocislo, která otestuje celočíselný parametr cislo a vrátí
 * logickou hodnotu. Pokud je zadané číslo prvočíslem, vrátí funkce hodnotu 1,
 * jinak vrátí hodnotu 0. (Můžeš použít i typ bool z knihovny stdbool.h - pak 
 * místo 1 a 0 vracej hodnoty true a false.)
 * Funkci musí jít použít tak, jak je to uděláno ve funkci ukol2 - viz dále.
 *
 * Test prvočísla: Postupně použij jako dělitele čísla od 2 do poloviční hodnoty
 * proměnné cislo. Pokud zbytek po dělení testovaného čísla a dělitele je roven
 * nule, není to prvočíslo.
 *
 * Tip: jak se funkce chová, když dostane zadánu zápornou hodnotu?
 */
//    jePrvocislo








/** 
 * Úkol 2
 * Vytvoř funkce zadejCele a jePrvocislo tak, aby je bylo možné použít tak,
 * jak je to předvedeno v této funkci.
 * Odkomentuj: Shift+Ctrl+X
 */
void ukol2(void)
{
  printf("Není implementováno.\n");

//  int x = zadejCele("Zkus zadat prvocislo: ");
//  if (jePrvocislo(x))
//    printf("Hodnota %d je prvocislo.\n", x);
//  else
//    printf("Hodnota %d neni prvocislo.\n", x);
}

/**
 * Úkol 3a (nejprve se podívej na úkol 3, viz dále)
 * Vytvoř podprogram tiskniPole, který vytiskne na jeden řádek počet prvků pole
 * a na další řádek prvky oddělené mezerami. Bude mít parametry pole a delka.
 * Pole bude obsahovat desetinná čísla. Vytiskni je zaokrouhlené na 2 desetinná
 * místa. Nakonec odřádkuj.
 */
//     tiskniPole











/** Úkol 3b (nejprve se podívej na úkol 3, viz dále)
 * Vytvoř funkci prumer, která vrátí průměrnou hodnotu prvků pole desetinných
 * čísel. Funkce bude mít parametry pole a delka.
 */
//      prumer










/** Úkol 3
 * Vytvoř pole desetinných čísel a inicializuj je hodnotami 6.5, 9.3, -4.1,
 * 3.456, 4.87, .007, 1.78.
 * Vypiš prvních 5 prvků pole a pak průměr z prvních 5 prvků pole. Použij
 * své funkce prumer a tiskniPole.
 * Pak proveď totéž pro prvních 6 a 7 prvků pole. Výsledek musí vypadat takto:
 * Pole:
 * 5
 * 6.50 9.30 -4.10 3.46 4.87
 * Prumer prvnich 5 prvku je 4.01.
 *
 * Pole:
 * 6
 * 6.50 9.30 -4.10 3.46 4.87 0.01
 * Prumer prvnich 6 prvku je 3.34.
 *
 * Pole:
 * 7
 * 6.50 9.30 -4.10 3.46 4.87 0.01 1.78
 * Prumer prvnich 7 prvku je 3.12.
 */
void ukol3(void)
{
  printf("Není implementováno.\n");






}

/** Ukol 4a (nejprve se podívej na úkol 4, viz dále)
 * Vytvoř podprogram nactiPoleN, který do připraveného pole délky n načte
 * hodnoty ze standardního vstupu. Parametry jsou pole desetinných čísel
 * a jeho délka n. Na vstupu se očekává n desetinných čísel oddělených mezerami
 * nebo konci řádků.
 * Podprogram nesmí nic tisknout.
 */
//     nactiPoleN









/** Úkol 4
 * Řekni uživateli, ať zadá délku pole (3 a více prvků).
 * Použij funkci zadejCele.
 *
 * Pokud uživatel zadá hodnotu 3 a více, vytvoř pole desetinných čísel této
 * délky. Jinak vytiskni hlášení, že zadaná hodnota neodpovídá požadavku.
 *
 * Vytiskni text "Zadej N prvků pole a odděl je mezerami: ", kde za N dosaď
 * délku vyrobeného pole.
 *
 * Pomocí příkazu nactiPoleN naplň pole hodnotami.
 *
 * Stejně jako v úkolu 3c pro délky pole n-2, n-1 a n vždy vytiskni část pole
 * této délky a spočítej průměr těchto prvků.
 */
void ukol4(void)
{
  printf("Není implementováno.\n");















}



/**
 * Startovní bod programu.
 */
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

  printf("*** Ukol c. 4 ***\n");
  ukol4();
  printf("-----------------\n");

  return 0;
}
