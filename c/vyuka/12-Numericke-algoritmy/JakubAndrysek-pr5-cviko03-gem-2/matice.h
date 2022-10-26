/* Modul pro práci s maticemi.
 *
 * Copyright (c) David Martinek, 2018--2022
 */

#ifndef matice_H_GUARD
#define matice_H_GUARD

#include <stdio.h>

#define LIB_VARIANT "Matice - pevna varianta"

#define MATICE_MAX_VELIKOST 100

/** \brief Deklarace typu Tmatice pro statickou matici.
 *
 * <p>Struktura zde obaluje pole pevné délky a skutečně využívané rozměry.
 * Výhodou takové stuktury je, že se snadno předává jako parametr a zvyšuje
 * přehlednost při práci s více maticemi. Nevýhodou je omezená maximální
 * velikost matice a zbytečné paměťové nároky při práci s menšími maticemi.
 * Z toho důvodu předáváme tuto strukturu vždy odkazem, nikdy hodnotou.</p>
 */
typedef struct {
    float prvek[MATICE_MAX_VELIKOST][MATICE_MAX_VELIKOST]; /**< Dvourozměrné pole prvků. */
    int radku;   /**< Počet řádků matice. */
    int sloupcu; /**< Počet sloupců matice */
} Tmatice;

/** \brief Deklarace chybových kódů pro jednotlivé operace. */
enum maticeErrors {
    EMOK,          /**< Kód pro stav bez chyby. */
    EMCREATE,      /**< Kód chyby při vytváření matice v paměti.  */
    EMREAD,        /**< Kód chyby při čtení ze souboru. */
    EMUNKNOWN,     /**< Kód nezámé chyby. */
};


/** \brief Vytvoří matici zadaných rozměrů.
 *
 * \param matice Tmatice* Ukazatel na neinicializovanou proměnnou typu Tmatice.
 * \param radku uint      Počet řádků nové matice.
 * \param sloupcu uint    Počet sloupců nové matice.
 * \return Tmatice*       Ukazatel na strukturu s maticí nebo NULL.
 *
 * <p>Pokud má matice uvnitř struktury pevné rozměry, musí být skutečné rozměry
 * menší nebo rovny hodnotě matice_MAX_SIZE, jinak funkce vrací NULL.</p>
 *
 * <p>Funkce končí s chybou i v případě, že zadané rozměry jsou nulové.</p>
 *
 */
Tmatice *maticeAlokuj(int radku, int sloupcu);

/** \brief Zruší zadanou matici.
 *
 * \param matice Tmatice* Ukazatel na ničenou matici.
 *
 * <p>Uvolní alokovanou paměť.</p>
 */
void maticeUvolni(Tmatice *matice);

/** \brief Inicializuje všechny prvky matice počáteční hodnotou.
 *
 * \param matice Tmatice*   Ukazatel na alokovanou matici.
 * \param hodnota float    Nová hodnota všech prvků.
 *
 * <p>Inicializovaná matice již musí být vytvořena pomocí #maticeAlokuj. Při
 * pokusu o inicializaci matice, která nebyla řádně vytvořena, může dojít
 * k havárii, zvláště u dynamicky vytvořené matice.</p>
 */
void maticeNastavPrvky(Tmatice *matice, float hodnota);

/** \brief Inicializuje všechny prvky matice náhodnými hodnotami.
 *
 * \param matice Tmatice* Ukazatel na alokovanou matici.
 *
 * <p>Inicializovaná matice již musí být vytvořena pomocí #maticeAlokuj. Při
 * pokusu o inicializaci matice, která nebyla řádně vytvořena, může dojít
 * k havárii, zvláště u dynamicky vytvořené matice.</p>
 */
void maticeRandom(Tmatice *matice);

/** \brief Vytiskne matici na obrazovku.
 *
 * \param matice const Tmatice* Ukazatel na řádně vyrobenou matici.
 * \return void
 *
 * <p>Matice se tiskne ve formátu "počet_řádků počet_sloupců prvky". Tento
 * formát je kompatibilní s funkcemi pro čtení matice.</p>
 *
 * <p>Matice musí být vytvořena pomocí #maticeAlokuj. Při pokusu o tisk matice,
 * která nebyla řádně vytvořena, může dojít k havárii, zvláště u dynamicky
 * vytvářené matice.</p>
 *
 * <p>Používá funkci #maticeTiskniSoubor.</p>
 */
void maticeTiskni(const Tmatice *matice);

/** \brief Vytiskne matici do souboru.
 *
 * \param soubor FILE*           Soubor otevřený pro zápis.
 * \param matice const Tmatice*  Ukazatel na řádně vyrobenou matici.
 *
 * <p>Matice se tiskne ve formátu "počet_řádků počet_sloupců prvky". Tento
 * formát je kompatibilní s funkcemi pro čtení matice.</p>
 *
 * <p>Matice musí být vytvořena pomocí #maticeAlokuj. Při pokusu o tisk matice,
 * která nebyla řádně vytvořena, může dojít k havárii, zvláště u dynamicky
 * vytvářené matice.</p>
 *
 * <p>Soubor musí být řádně otevřen pro zápis, jinak dojde při tisku k havárii.
 * </p>
 *
 * <p>Poznámka: Všimni si, že zde se předává otevřený soubor, ne jméno souboru.
 * Takto je totiž možné sem místo souboru předat stdout a tisknout na standardní
 * výstup. </p>
 */
void maticeTiskniSoubor(FILE *soubor, const Tmatice *matice);

/** \brief Vytvoří a přečte matici ze standardního vstupu (klávesnice).
 *
 * \return Tmatice* Vrací ukazatel na alokovanou a inicializovanou matici,
 *                  nebo NULL.
 * \param int chyba Vrací tudy EMCREATE nebo EMREAD, když dojde k chybě při
 *                  vytváření nebo čtení matice. Jinak vrací EMOK.
 *
 * <p>Matice se čte ve formátu "počet_řádků počet_sloupců prvky". Tento
 * formát je kompatibilní s funkcemi pro zápis matice.</p>
 *
 * <p>Může generovat chybu EMREAD, když dojde k chybě při čtení matice.</p>
 *
 * <p>Používá funkci #maticeCtiZeSouboru.</p>
 */
Tmatice *maticeCtiZeVstupu(int *chyba);

/** \brief Vytvoří a přečte matici ze souboru.
 *
 * \param file FILE* Soubor otevřený pro čtení.
 * \param int* chyba Vrací tudy EMCREATE nebo EMREAD, když dojde k chybě při
 *                   vytváření nebo čtení matice. Jinak vrací EMOK.
 * \return Tmatice* Ukazatel na nealokovanou matici.
 *
 * <p>Pokud nebude soubor řádně otevřen pro čtení, dojde při pokusu o čtení
 * k havárii.</p>
 *
 * <p>Matice se čte ve formátu "počet_řádků počet_sloupců prvky". Tento
 * formát je kompatibilní s funkcemi pro zápis matice.</p>
 *
 * <p>Může generovat chybu EMREAD, když dojde k chybě při čtení matice.</p>
 *
 * <p>Poznámka: Všimni si, že zde se předává otevřený soubor, ne jméno souboru.
 * Takto je totiž možné sem místo souboru předat stdin a číst ze standardního
 * vstupu. </p>
 */
Tmatice *maticeCtiZeSouboru(FILE *file, int *chyba);

/** \brief Vymění v matici řádky zadané pomocí indexů.
 *
 * <p>Pokud některý z indexů bude mimo matici nebo budou oba indexy totožné,
 * operace nic neudělá.</p>
 *
 * \param m Tmatice* Ukazatel na řádně alokovanou matici.
 * \param r1 int     Index prvního řádku.
 * \param r2 int     Index druhého řádku.
 */
void maticeVymenRadky(Tmatice *m, int r1, int r2);

int maxAbsPivot(Tmatice *matice, int d);

void maticeRadkoveUpravy(Tmatice *matice, int r);

#endif // matice_H_GUARD
