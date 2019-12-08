/*
 * Projekt: Doučování pro PR-5
 * Téma: Soubory, pole a struktury
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
  char nazev[21];
  float vaha;
} Tzvire;

/**
 * Zkopíruj hotovou funkci z projektu zaklady02.
 */
//void tiskniZvire(Tzvire zvire)


/**
 * Zkopíruj hotovou funkci z projektu zaklady02.
 */
//void tiskniZvirata(const Tzvire zvirata[], int kolik)


/** Funkce s parametrem soubor - soubor otevřený pro čtení. 
 * Vrací počet prvků přečtený z prvního řádku souboru jako svou funkční hodnotu.
 */
//     nactiPocetZvirat(      soubor)
// {
// 
// 
// 
// }


/** Funkce s parametry: f - soubor otevřený pro čtení, 
 *                      zvirata - pole zvířat, kolik - počet očekávaných prvků
 * Funkce vrací počet skutečně přečtených prvků jako svou funkční hodnotu.
 */
//     nactiZvirata(      f,        zvirata  ,     kolik)
// {
// 
//   // Čti kolik-krát řádek ze souboru. Každý řádek obsahuje max 20znakový název
//   // zvířete a jeho váhu jako desetinné číslo.
//   // Načítej přímo do jednotlivých složek prvků pole zvirata.
// 
// 
// 
// 
// 
//   // Nezapomeň vrátit skutečný počet načtených zvířat.
//   
// }

/**
 * Úkol č. 1
 * a. Zkopíruj sem funkce tiskniZvire a tiskniZvirata z projektu zaklady02.
 * b. Budeš zpracovávat soubor v tomto formátu:
 *    - na prvním řádku je počet záznamů v souboru
 *    - každý další řádek obsahuje dvojici: názevZvířete váha
 *    Příklad vstupního souboru:
 *    3
 *    Slon 1247.7
 *    Slepice 1.5
 *    Pes 15.34
 * c. Vytvoř funkce nactiPocetZvirat a nactiZvirata.
 * d. Vytvoř pole nad typem Tzvire, pojmenuj ho zoo, o délce přečtené ze souboru.
 * e. Načti do něj prvky ze souboru (pomocí funkce nactiZvirata).
 * f. Vytiskni pole zoo na obrazovku
 */
void ukol1(char *jmenoSouboru)
{
  // otevři a ošetři soubor s názvem uloženým v parametru jmenoSouboru


  // načti počet zvířat uložených v souboru
  
  // vytvoř pole zoo nad typem Tzvire a s délkou zjištěnou v předchozím kroku
  
  // načti zvířata ze souboru do zoo
  
  // použij tohle:
//   if (nacteno != pocet)
//     printf("Bylo nacteno jen %d zvirat, ale v souboru je uveden pocet %d!\n", nacteno, pocet);
//   printf("V ZOO jsou tato zvirata:\n");
//   tiskniZvirata(zoo, nacteno);

  // se souborem je třeba udělat ještě něco...
  
}






/** Funkce, která vrací pozici nejlehciho zvirete v zoo.
 *  Parametry: zoo - pole zvířat, kolik - délka pole.
 *
 * Vytvoř funkci, která vrátí index zvířete v zoo s nejmenší váhou.
 * Použij sekvenční vyhledávání v neseřazeném poli.
 */
//     najdiNejlehci(       zoo  ,     kolik)
// {
// 
// 
// 
// 
// 
// 
// 
// 
// 
// }

/**
 * Úkol č. 2
 * a. Vytvoř funkci najdiNejlehci.
 * b. V souboru zadaného jména najdi nejlehčí zvíře a vytiskni jej na výstup.
 *    Použij funkce najdiNejlehci a tiskniZvire.
 */
void ukol2(char *jmenoSouboru)
{
  // otevři a načti -- to už tu bylo






  // najdi nejlehčí zvíře v zoo
  printf("V souboru je nejlehčí zvíře ");
  
  // vytiskni nejlehčí zvíře v zoo
  
  printf(".\n");

  // ještě něco se souborem...
  
}






/**
 * Zkopíruj hotovou funkci z projektu zaklady02.
 */
//void serad(Tzvire zoo[], int delka)



/** Parametry: f - soubor otevřený pro zápis, zoo - pole zvířat, kolik - délka
 *             pole
 *
 * Zapiš zoo do souboru ve stejném formátu, jako výše uvedený vstupní soubor.
 * Pozor! Tato funkce nebude soubor ani otevírat, ani zavírat. To se udělá tam,
 * odkud se tato funkce volá.
 */
//      zapisZoo(      f,        zoo  ,     kolik)
// {
// 
// 
// 
// 
// 
// }

/**
 * Úkol č. 3
 * a. Použij funkci serad z projektu zaklady02.
 * b. Načti data ze souboru zadaného jména.
 * c. Seřaď je vzestupně podle váhy zvířat.
 * d. Vytvoř funkci zapisZoo. Zapiš seřazená data do souboru ukol3-vystup.txt
 *    ve stejném formátu jako byl vstupní soubor.
 * e. Pokud se vše v pořádku povede, vytiskni na obrazovku nápis "Hotovo", jinak
 *    vytiskni text "CHYBA!".
 * f. Při dalším spuštění programu použij tento vyrobený soubor jako vstupní.
 */
void ukol3(char *jmenoSouboru)
{
  // otevři a načti -- to už tu bylo











  // seřaď načtené zoo

  // založ soubor pro zápis  
  
  
  
  

  // ulož zoo do souboru
  

  
  // ještě něco se soubory...
  
  
}

/**
 * Úkol č. 4
 * a. Uprav main tak, aby jméno souboru před provedením každého úkolu zadával
 * uživatel - zeptej se jej na něj.
 * b. Vyzkoušej to se svými vlastními soubory se zvířaty.
 */
int main(void)
{
  printf("*** Ukol c. 1 ***\n");
  ukol1("zoo.txt");
  printf("-----------------\n");

  printf("*** Ukol c. 2 ***\n");
  ukol2("zoo.txt");
  printf("-----------------\n");

  printf("*** Ukol c. 3 ***\n");
  ukol3("zoo.txt");
  printf("-----------------\n");
  return 0;
}
