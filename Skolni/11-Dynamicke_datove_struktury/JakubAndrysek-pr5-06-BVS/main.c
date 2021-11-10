/*
 * Projekt: BVStrom
 * Autor: David Martinek
 * Datum: 2020-11-11
 *
 * Popis: Program pro práci s binárním vyhledávacím stromem.
 *
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
#include <stdbool.h> // pro praci s typem bool a konstantami true a false
#include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem


// natažení rozhraní modulu strom
#include "strom.h"


void operace1(Tstrom *strom)
{
//Úkol1: Realizuj v modulu funkci, která zjistí výšku stromu
//a vyzkoušej ji tady.
  printf("Tato operace jeste nebyla vytvorena.\n");
}

void operace2(Tstrom *strom)
{
//Úkol 2: Realizuj v modulu funkci, která vypíše prvky stromu průchodem
//preorder a vyzkoušej ji tady.
//Na každý řádek vypisuj dvojici klíč-data.
  printf("Tato operace jeste nebyla vytvorena.\n");
}

void operace3(Tstrom *strom)
{
//Úkol 3: Realizuj v modulu funkci, která vypíše prvky stromu průchodem
//postorder a vyzkoušej ji tady.
//Na každý řádek vypisuj dvojici klíč-data.
  printf("Tato operace jeste nebyla vytvorena.\n");
}

void operace4(Tstrom *strom)
{
//Úkol 4: Realizuj v modulu funkci, která vypíše prvky stromu průchodem
//inorder a vyzkoušej ji tady.
//Na každý řádek vypisuj dvojici klíč-data.
  printf("Tato operace jeste nebyla vytvorena.\n");
}

void operace5(Tstrom *strom)
{
//Úkol 5: Realizuj v modulu funkci, která zjistí, zda je strom vyvážený.
//Úkol 6: Tady (mimo modul) napiš algoritmus, který strom vyváží.
//Návod:
//- Ulož si obsahy uzlů do pole seřazené podle klíčů.
//- (Vzpomeň si na princip průchodu polem při binárním vyhledávání.)
//- Vlož do stromu prostřední prvek pole.
//-- Pak totéž udělej rekurzivně s levou půlkou pole.
//-- Pak totéž udělej rekurzivně s pravou půlkou pole.
  printf("Tato operace jeste nebyla vytvorena.\n");
}



/** Vytiskne uživatelské menu*/
void menu(void)
{
  printf(
    "\n"
    "Inicializace/zruseni..................I\n"
    "Tisk stromu...........................T\n"
    "Vlozeni...............................V\n"
    "Odebrani..............................O\n"
    "Konec.................................K\n"
    "---------------------------------------\n"
    "Doplnene operace\n"
    "Ukol 1. xxxxxxxxxxxxxxxxx.............1\n"
    "Ukol 2. xxxxxxxxxxxxxxxxx.............2\n"
    "Ukol 3. xxxxxxxxxxxxxxxxx.............3\n"
    "Ukol 4. xxxxxxxxxxxxxxxxx.............4\n"
    "Ukol 5. xxxxxxxxxxxxxxxxx.............5\n"
    "\n"
    "Tva volba: "
  );
}

/** Volba pro obsluhu menu. */
char zjistiVolbu(void)
{
  char volba;
  scanf(" %c", &volba);

  int c;
  while((c = getchar()) != EOF && c != '\n') {}

  return volba;
}

/********************************* MAIN ***********************************/
int main(void)
{
  Tstrom *strom = bvsInit();

  bvsVloz(strom, 5, 55);
  bvsVloz(strom, 5, 55);
  bvsVloz(strom, 4, 55);
  bvsVloz(strom, 1, 55);
  bvsVloz(strom, 6, 55);

  char volba;
  int konec = 0;
  do {
    printf("\n\n\n\n");
    menu();
    volba = zjistiVolbu();
    printf("\n\n\n\n\n");

    switch (toupper(volba))
    {
      case '1': // Úkol 1
        operace1(strom);
      break;

      case '2': // Úkol 2
        operace2(strom);
      break;

      case '3': // Úkol 3
        operace3(strom);
      break;

      case '4': // Úkol 4
        operace4(strom);
      break;

      case '5': // Úkol 5
        operace5(strom);
      break;



      case 'I': // Inicializace / zrušení
        bvsZrus(strom);
        strom = bvsInit();
        printf("Strom byl zrusen a znovu inicializovan.\n");
      break;

      case 'T': // Tisk stromu
        printf("Aktualni podoba stromu\n");
        bvsTisk(strom);
        printf("Pocet uzlu stromu: %d\n", bvsVaha(strom));
      break;

      case 'V': // Vložení
      {
        printf("Zadej hodnotu klice pro vlozeni - kladne cislo.\n");
        int klic;
        float data;
        scanf(" %d", &klic);
        printf("Zadej hodnotu dat ke klici %d - kladne desetinne cislo.\n", klic);
        scanf(" %f", &data);
        if (data < 0) data = -data;
        if (bvsVloz(strom, klic, data))
          printf("Uspech. Par (%d - %g) byl uspesne vlozen.\n", klic, data);
        else
          printf("Neuspech. Par (%d - %g) nebyl vlozen.\n", klic, data);
      }
      break;

      case 'O': // Odebrání
      {
        printf("Zadej hodnotu klice, ktery chces odebrat.\n");
        int klic;
        scanf(" %d", &klic);
        printf("Zadal jsi klic s hodnotou %d.\n", klic);
        if (bvsOdeber(strom, klic))
          printf("Uspech. Uzel se zadanym klicem odebran.\n");
        else
          printf("Neuspech. Uzel se zadanym klicem neodebran.\n");
      }
      break;

      case 'K': // Konec
        printf("Rusim strom a koncim.\n");
        konec = 1;
      break;

      default:
        printf("Neznamy prikaz. Zkus to znovu.\n");
      break;
    }
  } while (!konec);

  bvsZrus(strom);
  return EXIT_SUCCESS;
}



