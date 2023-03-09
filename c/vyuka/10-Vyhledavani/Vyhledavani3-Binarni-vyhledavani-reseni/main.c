/*
 * Projekt: PTest05 - Binarni vyhledavaci strom
 * Autor: David Martinek
 * Datum: 24. 3. 2018
 *
 * Popis
 * Toto je demonstracni program s abstraktnim datovym typem Binarni vyhledavaci
 * strom. Tento strom je implementovan v modulu, ktery tvori soubory strom.h
 * s deklaracemi typu a funkci a strom.c s implementaci jednotlivych operaci.
 * Soubor main.c realizuje nabidku pro uzivatele a obsahuje misto pro doplnovani
 * vlastnich uloh vyuzivajicich strom.
 *   Strom slouzi k uchovavani paru (klic - data), kde klicem jsou desetinna
 * cisla a daty jsou cela cisla. Jde o zjednodusenou variantu stromu. Da se
 * napriklad pouzit pro zaznamenavani vysledku zavodu, kde klic odpovida
 * dosazenemu casu a data odpovidaji cislu zavodnika.
 *
 * Navod k pouziti
 * 1. Projdi si soubor strom.h a precti si, jake funkce mas k dispozici.
 * 2. Projdi si soubor main.h a prozkoumej realizaci nabidky.
 * 3. V main.c se vyskytuji komentare s predponou TODO. Do techto mist doplnuj
 *    svuj kod a prikazy uzivatelske nabidky.
 * 4. Vytvor v main.c vlastni verze operaci hledani klice, vlozeni uzlu, ruseni
 *    uzlu, zruseni stromu. Potom muzes svou implementaci srovnat s resenim
 *    v souboru strom.c.
 * 5. Rozsir nabidku o nasledujici operace. Pouziti operaci realizuj jako funkce
 *    podle vzoru funkce "vzorovaOperace". Pokud to jde, pouzij jiz hotove
 *    funkce, budto sve nebo zverejnene v souboru strom.h. V modulu strom nesmis
 *    nic menit.
 *    - Vypis vahy stromu.
 *    - Vypis vysky stromu.
 *    - Vypis zadane urovne stromu (uzlu ve stejne vysce).
 *    - Vypis uzlu pruchody "in order", "pre order", "post order". Uzly vypisuj
 *      ve formatu (klic -> data).
 *    - Pridani prvku do stromu ze souboru. Vyuzij i hotove operace z modulu.
 *    - Vyhledani dat z aktualniho stromu podle klicu prectenych ze souboru.
 *    - Test, zda je strom vyvazeny, tj. pro kazdy uzel plati, ze vaha obou jeho
 *      podstromu se lisi jen o 1.
 *    - Vyvazeni stromu pomoci pole - pary (klic-data) se ulozi serazene do
 *      pole a pak se vkladaji do prazdneho stromu ve vhodnem poradi.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// natazeni rozhrani modulu strom
#include "strom.h"


// TODO Sem dopln dalsi operace se stromem.
void vzorovaOperace(Tuzel **koren)
{
  printf("Test, zda je strom prazdny.\n");
  Tuzel *pom = *koren;
  if (bvsJePrazdny(pom))
    printf("Strom je prazdny.\n");
  else
    printf("Strom neni prazdny.\n");
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
    "Najdi prvek...........................N\n"
    "Konec.................................K\n"
    "---------------------------------------\n"
    "Doplnene operace\n"
    // TODO Sem dopln nabidku o vlastni operace
    "Zatim nic.............................1\n"
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
  Tuzel *koren = bvsInit();

  char volba;
  int konec = 0;
  do {
    menu();
    volba = zjistiVolbu();

    switch (toupper(volba))
    {
      // TODO Sem dopln sve dalsi operace.
      case '1': // tva operace
        vzorovaOperace(&koren);
      break;





      case 'I': // Inicializace / zruseni
        bvsZrus(&koren);
//        koren = bvsInit(); // zbytecne - bvsZrus nastavi do korene NULL
        printf("Strom byl zrusen a znovu inicializovan.\n");
      break;

      case 'T': // Tisk stromu
        printf("Aktualni podoba stromu\n");
        bvsTisk(koren);
      break;

      case 'V': // Vlozeni
      {
        printf("Zadej hodnotu klice pro vlozeni - desetinne cislo.\n");
        float klic;
        int data;
        scanf(" %f", &klic);
        printf("Zadej hodnotu dat ke klici %g - kladne cele cislo.\n", klic);
        scanf(" %d", &data);
        if (data < 0) data = -data;
        if (bvsVloz(&koren, klic, data))
          printf("Uspech. Par (%g -> %d) byl uspesne vlozen.\n", klic, data);
        else
          printf("Neuspech. Par (%g -> %d) nebyl vlozen.\n", klic, data);
      }
      break;

      case 'O': // Odebrani
      {
        printf("Zadej hodnotu klice, ktery chces odebrat.\n");
        float klic;
        scanf(" %f", &klic);
        printf("Zadal jsi klic s hodnotou %g.\n", klic);
        if (bvsOdeber(&koren, klic))
          printf("Uspech. Uzel se zadanym klicem odebran.\n");
        else
          printf("Neuspech. Uzel se zadanym klicem neodebran.\n");
      }
      break;

      case 'N': // Najdi prvek
      {
        printf("Zadej hodnotu klice, ktery chces ve stromu najit.\n");
        float klic;
        scanf(" %f", &klic);
        printf("Zadan klic s hodnotou %g.\n", klic);
        int data = bvsHledej(koren, klic);
        if (data == NENALEZENO)
          printf("Zadany klic nebyl nalezen.\n");
        else
          printf("Je tam! Nasel jsem k nemu data: (%g -> %d).\n", klic, data);
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

  bvsZrus(&koren);
  return EXIT_SUCCESS;
}



