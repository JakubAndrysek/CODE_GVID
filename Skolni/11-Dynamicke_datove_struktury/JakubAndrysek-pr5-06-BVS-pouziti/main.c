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
#include <string.h>  // pro praci s textovymi retezci
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
  int a, b;
//  while (fscanf(vstup, "%50s\t%20[^\n] \n", &slovnik.klic, &slovnik.data) == 2)
  //  while (fscanf(vstup, "%50s\t%50s\t%d\t%d ", &slovnik.klic, &slovnik.data, &a, &b) == 4)
   while (fscanf(vstup, "%50s\t%50s\t%d\t%d ", &slovnik.data, &slovnik.klic, &a, &b) == 4)
  {
    printf("Klic: %s | data: %s\n", slovnik.klic, slovnik.data);
    bvsVloz(strom, slovnik.klic, slovnik.data);
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
  bvsTisk(strom, stdout);
}


/** Vytiskne uživatelské menu*/
void menu(void)
{
  printf(
    "\n"
    "Inicializace/zruseni..................I\n"
    "Tisk stromu...........................T\n"
    "Uloz stromu...........................U\n"
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
  bvsVloz(strom, "d", "55");
  bvsVloz(strom, "m", "55");
  bvsVloz(strom, "h", "55");
  bvsVloz(strom, "e", "55");
  bvsVloz(strom, "p", "55");
  bvsVloz(strom, "q", "55");
  bvsVloz(strom, "l", "55");
  bvsVloz(strom, "b", "55");
  bvsVloz(strom, "u", "55");
  bvsVloz(strom, "f", "55");

  bvsTisk(strom, stdout);
}

/********************************* MAIN ***********************************/
int main(void)
{
  Tstrom *strom = bvsInit();

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


      case 'D': // Default
        bvsZrus(strom);
        strom = bvsInit();
        prvniNastaveni(strom);
        printf("Strom byl defaultne inicializovan.\n");
      break;

      case 'T': // Tisk stromu
        printf("Aktualni podoba stromu\n");
        bvsTisk(strom, stdout);
        printf("Pocet uzlu stromu: %d\n", bvsVaha(strom));
      break;


      case 'U': // Tisk stromu
      {
        char nazevSouboru[] = "vystup.txt";
        // strcpy("", nazevSouboru);
        printf("Aktualni podoba stromu\n");
        printf("Tisknu do souboru '%s'\n", nazevSouboru);
        FILE* vystup = fopen(nazevSouboru, "w");
        if(vystup == NULL) {
          printf("Nepodarilo se otevrit/vytvorit soubor %s\n", nazevSouboru);
          return EXIT_FAILURE;
        }
        bvsTisk(strom, vystup);
      }
      break;

      case 'V': // Vložení
      {
        printf("Zadej hodnotu klice pro vlozeni - kladne cislo.\n");
        char klic[51];
        char data[51];
        scanf(" %s", &klic);
        printf("Zadej hodnotu dat ke klici %s - kladne desetinne cislo.\n", klic);
        scanf(" %f", &data);
        if (bvsVloz(strom, klic, data))
          printf("Uspech. Par (%s - %s) byl uspesne vlozen.\n", klic, data);
        else
          printf("Neuspech. Par (%s - %s) nebyl vlozen.\n", klic, data);
      }
      break;

      case 'O': // Odebrání
      {
        printf("Zadej hodnotu klice, ktery chces odebrat.\n");
        char klic[51];
        scanf(" %50s", &klic);
        printf("Zadal jsi klic s hodnotou %s.\n", klic);
        if (bvsOdeber(strom, klic))
          printf("Uspech. Uzel se zadanym klicem odebran.\n");
        else
          printf("Neuspech. Uzel se zadanym klicem neodebran.\n");
      }
      break;

      case 'N': //Nacti soubor
      {
        FILE* vstup;
        // nactiZeSouboru(strom, vstup,"telefoniSeznam.txt");
        nactiZeSouboru(strom, vstup,"svatkySeznam.txt");
        // nactiZeSouboru(strom, vstup,"svatkySeznamLong.txt");
        break;
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



