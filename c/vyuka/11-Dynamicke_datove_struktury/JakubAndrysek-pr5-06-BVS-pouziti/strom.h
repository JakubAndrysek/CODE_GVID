#ifndef STROM_H_INCLUDED
#define STROM_H_INCLUDED

/*
 * Projekt: Binární vyhledávací strom
 * Autor: David Martinek a Jakub Andrysek
 * Datum: 2020-11-11
 * Popis
 * Toto je hlavičkový soubor - obsahuje deklarace konstant, typů a hlavičky
 * funkcí, ktere můžeš použít ve svém řešení.
 *
 * Strom
 * Uzly obsahují dvojici klíč-data typu int-float. Vyhledává se tedy podle
 * celých čísel a data jsou desetinná čísla.
 */

#include <stdbool.h>


/** Uzel binárního stromu. Dvojice klic-data je zde int-float. */
typedef struct _tuzel Tuzel;
// Vnitřek typu Tuzel je ukryt v souboru strom.c.

// Tohle uživatel vidět nemusí. Ještě by mi do toho vlezl a něco mi tu poničil.
struct _tuzel
{
  char klic[51];           //< Klíč pro vyhledávání -- zde celé číslo
  char data[51];         //< Data vázaná na klíč -- zde desetinné číslo
  Tuzel* levy;   //< Ukazatel na levý podstrom
  Tuzel* pravy;  //< Ukazatel na pravý podstrom
};

typedef struct _slovnik Tslovnik;

struct _slovnik
{
  char klic[51];
  char data[51];
};


/** Struktura reprezentující celý strom. */
typedef struct _strom Tstrom;

struct _strom
{
  Tuzel* koren;
  int vaha;
};


/**
 * Alokuje prázdný strom a vraci na něj ukazatel nebo NULL.
 */
Tstrom *bvsInit(void);

/** \brief Uvolní z paměti všechny uzly i pomocnou strukturu.
 *
 * \param strom Tstrom* Ukazatel na alokovaný a inicializovaný strom.
 */
void bvsZrus(Tstrom *strom);

/** \brief Testuje zda je strom prázdný
 *
 * \param strom Tstrom* Ukazatel na alokovaný a inicializovaný strom.
 * \return bool Vrací true, když je strom prázdný, jinak false.
 */
bool bvsJePrazdny(Tstrom* strom);

/** \brief Vrací aktuální váhu stromu, tj. počet uzlů.
 *
 * \param strom Tstrom* Ukazatel na alokovaný a inicializovaný strom.
 * \return int Vrací počet uzlů stromu.
 */
int bvsVaha(Tstrom* strom);

/** \brief Vloží pár (klíč, data) do stromu jako nový uzel na správné místo.
 *
 * Jde o binární vyhledávací strom, který neakceptuje duplicitní prvky.
 *
 * \param strom Tstrom* Ukazatel na alokovaný a inicializovaný strom.
 * \param klic int   Hodnota klíče.
 * \param data float Hodnota dat asociovaných s klíčem.
 * \return bool Vrací true, když se klíč povedlo vložit, jinak false.
 */
bool bvsVloz(Tstrom *strom, char klic[], char data[]);

/** \brief Pokud najde ve stromu uzel se zadaným klíčem, odstraní ho.
 *
 * \param strom Tstrom* Ukazatel na alokovaný a inicializovaný strom.
 * \param klic int Hodnota hledaného klíče.
 * \return bool Vrací true, pokud proběhlo zrušení uzlu, jinak false.
 */
bool bvsOdeber(Tstrom *strom, char klic[]);

/** \brief Vytiskne uzly stromu seřazené podle klíčů.
 *
 * \param strom Tstrom* Ukazatel na alokovaný a inicializovaný strom.
 */
void bvsTisk(Tstrom *strom, FILE* vystup);

int bvsVahaIn(Tstrom *strom);
int bvsVyska(Tstrom *strom);
void bvsPreorder(Tstrom *strom);
void bvsInorder(Tstrom *strom);
void bvsPostorder(Tstrom *strom);

int bvsVyvazeni(Tstrom *strom);
bool bvsJeVyvazeny(Tstrom *strom);
bool bvsHledej(Tstrom *strom, char klic[], char hledany[]);

void bvsStromNaPole(Tstrom* strom, Tuzel *uzel[], int *index);

#endif // STROM_H_INCLUDED
