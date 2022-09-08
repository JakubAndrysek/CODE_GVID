/*
 * Projekt: Hlavičkový soubor s užitečnými definicemi.
 *          Určeno pro výuku programování na Gymnáziu Brno, Vídeňská.
 *
 * Autor: David Martinek
 * Datum: 2021
 *
 * Šablona školního projektu © 2021 David Martinek.
 */
#ifndef _GVID_H_DM_
#define _GVID_H_DM_


//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##
// Pomůcka pro ladění.
// Funkci dprintf používej pro tisk ladících informací.

// Napiš na začátek svého zdrojáku: #define NDEBUG
// a příkaz dprintf se začne chovat jako prázdný příkaz.
// ==> Ladící výpisy jde snadno globálně vypnout.

// #define NDEBUG

#ifdef NDEBUG
  // Příkaz dprintf pro tisk ladících zpráv. Funguje stejně jako printf,
  // ale jde jej globálně vypnout definováním symbolu NDEBUG.
  // Vhodný pro povídání s uživatelem v průběhu ladění a následně vypnutí.
  #define dprintf(...)
#else
  #define dprintf(...) printf(__VA_ARGS__)
#endif //NDEBUG
//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##



// Tohle kouzlo je podmíněný překlad a makro, které vyčistí konzoli v Linuxu
// a ve Windows.
#ifdef __unix__
  // příkaz pro unixovou konzoli, možná funguje i pod MacOS
  #define vycistiKonzoli() system("clear")
#else
  // příkaz pro konzoli ve Windows a DOSu
  #define vycistiKonzoli() system("cls")

  // Tohle zaříkání je nutné použít v překladači MINGW ve Windows, protože
  // překladač běžně používá céčkovou knihovnu od MS, která nemá správně
  // implementováno rozšíření C99 a novější. Tento přepínač donutí překladač
  // používat knihovnu šířenou s MINGW. Bez tohoto woodoo ve Windows nefungují
  // například některé formátovací značky příkazu printf (%zd, %zu, %hhd,
  // %lld aj.).
  //
  // Aby tohle kouzlo zafungovalo, je potřeba tento define mít ve zdrojovém
  // textu před systémovými #include.
  //
  // Také je dobré si sundat ponožku, ukázat bosou nohou do čtyř světových
  // stran a přát si brzký a potupný zánik firmy MS.
  #define __USE_MINGW_ANSI_STDIO 1
#endif // __unix__



// Nové jméno pro typ unsigned int --> uint.
typedef unsigned int uint;



// Matematické konstanty, které nejsou součástí standardu jazyka C.
// Zde jsou kvůli použití přepínačů -std=c99 a -pedantic ve školním projektu.
# define M_E        2.7182818284590452354	  /* e */
# define M_LOG2E    1.4426950408889634074	  /* log_2 e */
# define M_LOG10E   0.43429448190325182765	/* log_10 e */
# define M_LN2      0.69314718055994530942	/* log_e 2 */
# define M_LN10     2.30258509299404568402	/* log_e 10 */
# define M_PI       3.14159265358979323846	/* pi */
# define M_PI_2     1.57079632679489661923	/* pi/2 */
# define M_PI_4     0.78539816339744830962	/* pi/4 */
# define M_1_PI     0.31830988618379067154	/* 1/pi */
# define M_2_PI     0.63661977236758134308	/* 2/pi */
# define M_2_SQRTPI 1.12837916709551257390	/* 2/sqrt(pi) */
# define M_SQRT2    1.41421356237309504880	/* sqrt(2) */
# define M_SQRT1_2  0.70710678118654752440	/* 1/sqrt(2) */



#endif // _GVID_H_DM_
