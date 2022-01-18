/*
 * Projekt: Doučování pro PR-5
 * Téma: Soubory a pole
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



/** Funkce s parametrem soubor - soubor otevřený pro čtení.
 * Vrací součet prvků souboru jako svou funkční hodnotu.
 */
//      soucet(      soubor)
//{
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
 * a. Zpracuj textový soubor obsahující desetinná čísla oddělená bílými znaky.
 *    Dopředu není známo, kolik má prvků.
 * b. Vytvoř výše popsanou funkci soucet.
 * c. Připrav soubor zadaného jména pro zpracování a vypočítej součet prvků daného souboru.
 * d. Vytiskni součet na obrazovku.
 */
void ukol1(char *jmenoSouboru)
{
  // otevři a ošetři soubor s názvem uloženým v parametru jmenoSouboru

//  if (         )
//  {
//    printf("Soubor %s se nepovedlo otevrit.\n", jmenoSouboru);
//    return;
//  }

  // vypočti součet prvků souboru a ulož jej do proměnné suma


  // vytiskni výsledek
//  printf("Soucet prvku v souboru %s je %g.\n", jmenoSouboru, suma);

  // se souborem je třeba udělat ještě něco...

}






/** Funkce s parametry: soubor - soubor otevřený pro čtení,
 *                      suma - desetinné číslo, předávaný odkazem
 *                      pocet - celé číslo, předávaný odkazem.
 * Funkce vrací hodnotu EOF, pokud úspěšně zpracovala celý soubor.
 * V případě chyby čtení vrací hodnotu různou od EOF.
 *
 * Výsledky vrací přes parametry suma - součet přečtených prvků a
 * pocet - počet přečtených prvků.
 */
//    soucet2(      soubor,        suma,      pocet)



/** Podprogram s parametry: vstup - vstupní soubor otevřený pro čtení
 *                          vystup - výstupní soubor otevřený pro zápis
 *                          mez - desetinné číslo
 *
 * Podprogram vytiskne do výstupního souboru jen ty prvky ze vstupního souboru,
 * které jsou menší než zadaná mez.
 */
//     opisMensiNez(      vstup,       vystup,       mez)


/**
 * Úkol č. 2
 * a. Vytvoř funkce soucet2 a opisMensiNez.
 * b. Připrav soubor zadaného jména na zpracování.
 * c. Vytiskni na obrazovku součet a počet prvků daného souboru a také
 *    aritmetický průměr z prvků souboru.
 * d. Použij funkci rewind pro návrat na začátek souboru.
 * e. Pomocí funkce opisMensiNez vytiskni na obrazovku pouze podprůměrné prvky
 *    vstupního souboru. (obrazovka = soubor stdout).
 */
void ukol2(char *jmenoSouboru)
{
  // otevři a načti -- to už tu bylo








  // Vytvoř proměnné suma, pocet a err. Použij je při volání funkce soucet2.



//  if (err == EOF)
//    printf("Soubor %s byl nacten v poradku.\n", jmenoSouboru);
//  else
//    printf("Cteni souboru %s skoncilo s chybou.\n", jmenoSouboru);

//  printf("Soucet prvku =  %10g\n",     );
//  printf("Pocet prvku =   %10d\n",      );
//  printf("Prumer hodnot = %10g\n",           );
//  rewind(f);

//  printf("\nPodprumerne prvky jsou:\n");
  // Vypiš podprůměrné prvy souboru. Použij funkci opisMensiNez.

  // ještě něco se souborem...

}





/** Funkce s parametrem soubor - soubor otevřený pro čtení
 * Funkce vrací počet prvků v souboru. Předpokládá se, že počet prvků je v souboru zapsán jako
 * celé číslo na prvním řádku.
 */
//    zjistiDelku(      soubor)


/** Funkce s parametry: soubor - soubor otevřený pro čtení
 *                      pole - pole desetinných čísel, kam se zapíší hodnoty přečtené ze souboru
 *                      delka - skutečná délka pole
 * Funkce přečte ze souboru desetinná čísla, která v ní jsou oddělena bílými znaky, a uloží je
 * do zadaného pole dané délky. Funkce vrací skutečně přečtený počet prvků jako svou funkční
 * hodnotu pro případ, že by v souboru bylo prvků méně. Funkce nikdy nepřečte více než delka hodnot.
 */
//    nactiPole(      soubor,       pole  ,     delka)


/** Podprogram s parametry: vystup - soubor otevřený pro zápis
 *                          pole - pole desetinných čísel
 *                          delka - počet prvků pole
 * Podprogram vytiskne na první řádek výstupního souboru délku pole.
 * Potom vypíše všechny prvky pole a oddělí je vždy jednou mezerou.
 * Nakonec odřádkuje.
 * Poznámka: Pro tisk desetinných čísel použij formátovací značku %g.
 */
//     tiskniPole(      vystup,       pole  ,     delka)



/** Funkce s parametry: pole - pole desetinných čísel
 *                      delka - délka pole
 * Funkce vrací jako funkční hodnotu medián, to je hodnotu, která leží na
 * střední pozici v seřazeném poli hodnot. Narozdíl od průměru jde o skutečnou
 * hodnotu jednoho konkrétního prvku pole.
 * Poznámka - pole asi bude nutné seřadit (ideálně podprogramem). Nevadí, když
 * se v této funkci prvky v poli přeuspořádají.
 */
//      median(      pole  ,     delka)


/**
 * Úkol č. 3
 * a. Zpracuj soubor zadaného jména, který obsahuje na prvním řádku počet prvků
 *    a pak odpovídající počet desetinných čísel oddělených bílými znaky.
 * b. Vyrob pole stejné délky, jako je počet prvků v souboru. Použij funkci zjistiDelku.
 * c. Načti do pole prvky ze souboru. Použij funkci nactiPole.
 * d. Pokud je v souboru chyba, vytiskni o tom chybové hlášení.
 * e. Zjisti a vytiskni medián z načtených prvků. Použij funkci median.
 * f. Pro kontrolu vytiskni prvky ještě jednou.
 */
void ukol3(char *jmenoSouboru)
{
  // otevři a načti -- to už tu bylo







  // Zjisti počet prvků v souboru.

  // Vyrob pole desetinných čísel o této délce a načti do něj prvky ze souboru.


//  if (nacteno != delka)
//    printf("Varovani! Ve vstupnim souboru je chybna delka!\n");

  // Vytiskni pole. Pro tisk na obrazovku použij soubor stdout.


  // Najdi medián.


//  printf("Median zadaneho souboru hodnot je %g.\n", med);

  // Znovu pole vytiskni.


  // ještě něco se souborem...


}

/**
 * Úkol č. 4
 * a. Uprav main tak, aby jméno souboru před provedením každého úkolu zadával
 * uživatel - zeptej se jej na něj.
 * b. Vyzkoušej to se svými vlastními soubory, včetně souborů ve kterých budou schválně chyby.
 */
int main(void)
{
  printf("*** Ukol c. 1 ***\n");
  ukol1("data1.txt");
  printf("-----------------\n");

  printf("*** Ukol c. 2 ***\n");
  ukol2("data2.txt");
  printf("-----------------\n");

  printf("*** Ukol c. 3 ***\n");
  ukol3("data3.txt");
  printf("-----------------\n");
  return 0;
}
