#ifndef STROM_H_INCLUDED
#define STROM_H_INCLUDED

/*
 * Projekt: PTest05 - Binarni vyhledavaci strom
 * Autor: David Martinek
 * Datum: 24. 3. 2018
 */

 /** Hodnota pro bvsHledej, ktera dava najevo, ze klic nebyl nalezen. */
#define NENALEZENO -1

/** Hodnota pravda - true pro operace, ktere vraceji logickou hodnotu. */
#define USPECH 1

/** Hodnota nepravda - false pro operace, ktere vraceji logickou hodnotu. */
#define NEUSPECH 0


/** Uzel binárního stromu. Deklarace složek typu. */
typedef struct tuzel
{
  float klic;           //< Klíč pro vyhledávání
  int data;             //< Data vázaná na klíč
  struct tuzel *levy;   //< Ukazatel na levý podstrom
  struct tuzel *pravy;  //< Ukazatel na pravý podstrom
} Tuzel;

/** INICIALIZACE
 * Vraci ukazatel na prazdny strom.
 */
Tuzel *bvsInit(void);

/** PRAZDNY STROM
 * Vraci hodnotu USPECH (true), kdyz je zadany strom prazdny.
 */
int bvsJePrazdny(Tuzel *u);

/** VKLADANI KLICE
 * Vlozi par (klic, data) do stromu jako novy uzel na spravne misto.
 * Vkladana data nesmi byt zaporna cisla.
 * Vraci hodnotu USPECH (true), kdyz se operace povedla, jinak NEUSPECH (false).
 *
 * \param u Tuzel**  Ukazatel na koren stromu predavany odkazem.
 * \param klic float Vkladany klic.
 * \param data int   Vkladana data.
 * \return int       Vraci hodnotu USPECH nebo NEUSPECH.
 */
int bvsVloz(Tuzel **u, float klic, int data);

/** HLEDANI KLICE
 * Hleda data k zadanemu klici.
 * Vraci hodnotu nalezene polozky data, jinak vraci hodnotu NENALEZENO.
 * Predpoklada se, ze polozky data ve stromu nikdy nenabyvaji zapornych hodnot,
 * proto je hodnota konstanty NENALEZENO zaporne cislo.
 *
 * \param u Tuzel*    Ukazatel na korenovy uzel stromu.
 * \param klic float  Hodnota hledaneho klice.
 * \return int        Vraci nalezena data odpovidajici klici nebo NENALEZENO.
 */
int bvsHledej(Tuzel *u, float klic);

/** ODEBRANI KLICE
 * Odebere uzel se zadanym klicem. Pokud strom zadany klic neobsahuje, strom
 * se nezmeni.
 * Vraci hodnotu USPECH (true), kdyz se operace povedla, jinak NEUSPECH (false).
 *
 * \param u Tuzel**  Ukazatel na koren stromu predavany odkazem.
 * \param klic float Hodnota klice, podle ktere se hleda uzel k odstraneni.
 * \return int       Vraci hodnotu USPECH nebo NEUSPECH.
 */
int bvsOdeber(Tuzel **u, float klic);

/** ZRUSENI STROMU
 * Provede kompletni uvolneni pameti alokovane vsemi uzly. Na konci bude
 * v parametru koren vracen prazdny ukazatel NULL.
 *
 * \param koren Tuzel** Ukazatel na koren stromu predavany odkazem.
 */
void bvsZrus(Tuzel **koren);

/** TISK STROMU
 * Vytiskne obsah stromu na standardní výstup.
 * \param koren Tuzel* Ukazatel na koren stromu.
 */
void bvsTisk(Tuzel *koren);


#endif // STROM_H_INCLUDED
