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
  int vyska = bvsVyska(strom);
  printf("Strom ma vysku: %d\n", vyska);
}

void operace2(Tstrom *strom)
{
  //Úkol 2: Realizuj v modulu funkci, která vypíše prvky stromu průchodem
  //preorder a vyzkoušej ji tady.
  printf("Vypis preorder\n");
  bvsPreorder(strom);
}

void operace3(Tstrom *strom)
{
  //Úkol 3: Realizuj v modulu funkci, která vypíše prvky stromu průchodem
  //inorder a vyzkoušej ji tady.
  printf("Vypis inorder\n");
  bvsInorder(strom);
}

void operace4(Tstrom *strom)
{
  //Úkol 4: Realizuj v modulu funkci, která vypíše prvky stromu průchodem
  //postorder a vyzkoušej ji tady.
  printf("Vypis postorder\n");
  bvsPostorder(strom);

}

void operace5(Tstrom *strom)
{
  // https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
  //Úkol 5: Realizuj v modulu funkci, která zjistí, zda je strom vyvážený.
  printf("Vyvazenost: %d | je vyvazeny (bool): %d", bvsVyvazeni(strom), bvsJeVyvazeny(strom));
}

bool nactiZeSouboru(Tstrom* strom, FILE* vstup, char* nazevSouboru) {
  vstup = fopen(nazevSouboru, "r");
  if(vstup == NULL) {
    return false;
  }

  Tslovnik slovnik;

  while (fscanf(vstup, "%20c %20c", &slovnik.klic, &slovnik.klic) == 2)
  {
    printf("Klic: %s | hodnota: %s\n", slovnik.klic, slovnik.data);
  }
  

  return true;

}


void vytvorVyvazeny(Tstrom *strom, Tuzel* pole[], int from, int to) {

  if(from > to) {
    return;
  }

  int mid = (from+to)/2;
  bvsVloz(strom, pole[mid]->klic, pole[mid]->data);

  vytvorVyvazeny(strom, pole, from, mid-1);
  vytvorVyvazeny(strom, pole, mid+1, to);
}


void operace6(Tstrom *strom)
{
  // https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/
  //Úkol 6: Tady (mimo modul) napiš algoritmus, který strom vyváží.
  //Návod:
  //- Ulož si obsahy uzlů do pole seřazené podle klíčů.
  //- (Vzpomeň si na princip průchodu polem při binárním vyhledávání.)
  //- Vlož do stromu prostřední prvek pole.
  //-- Pak totéž udělej rekurzivně s levou půlkou pole.
  //-- Pak totéž udělej rekurzivně s pravou půlkou pole.

  int pocetPrvku = bvsVaha(strom);

  Tuzel *pole[pocetPrvku];
  int delkaPole = 0;

  bvsStromNaPole(strom, pole, &delkaPole);
  int mid = delkaPole/2;

  Tstrom *vyvazeny = bvsInit();

  vytvorVyvazeny(vyvazeny, pole, 0, delkaPole-1);

  printf("Vyvazeny strom: pouze zeobrzeni (na vychozim strome se nic neprojevi)\n");
  bvsTisk(vyvazeny);
}

bool nactiZeSouboru(Tstrom* strom, FILE* vstup, char* nazevSouboru) {
  vstup = fopen(nazevSouboru, "r");
  if(vstup == NULL) {
    return false;
  }

  return true;

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
    "Ukol 1. Vyska stromu\n"
    "Ukol 2. Vypis preorder\n"
    "Ukol 3. Vypis inorder\n"
    "Ukol 4. Vypis postorder\n"
    "Ukol 5. Vyvazenost\n"
    "Ukol 6. Vyvaz strom\n"
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

void prvniNastaveni(Tstrom *strom) {
  bvsVloz(strom, 5, 55);
  bvsVloz(strom, 3, 55);
  bvsVloz(strom, 1, 55);
  bvsVloz(strom, 2, 55);
  bvsVloz(strom, 4, 55);
  bvsVloz(strom, 9, 55);
  bvsVloz(strom, 7, 55);
  bvsVloz(strom, 6, 55);
  bvsVloz(strom, 8, 55);
  bvsVloz(strom, 10, 55);

  bvsTisk(strom);
}

void prvniNastaveniNevyvazeny(Tstrom *strom) {
  bvsVloz(strom, 6, 55);
  bvsVloz(strom, 5, 55);
  bvsVloz(strom, 7, 55);
  bvsVloz(strom, 3, 55);
  bvsVloz(strom, 2, 55);
  bvsVloz(strom, 1, 55);
  bvsVloz(strom, 0, 55);
  bvsVloz(strom, -1, 55);

  bvsTisk(strom);
}

/********************************* MAIN ***********************************/
int main(void)
{
  Tstrom *strom = bvsInit();

  // prvniNastaveni(strom);
  prvniNastaveniNevyvazeny(strom);

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

      case '6': // Úkol 6
        operace6(strom);
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

      case 'N': //Nacti soubor
      {
        FILE* vstup;
        nactiZeSouboru(strom, vstup,"telefoniSeznam.txt")
        
      }

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



