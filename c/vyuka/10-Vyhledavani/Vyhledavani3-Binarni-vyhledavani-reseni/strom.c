/*
 * Projekt: PTest05 - Binarni vyhledavaci strom
 * Autor: David Martinek
 * Datum: 24. 3. 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "strom.h"


/** INICIALIZACE */
Tuzel *bvsInit(void)
{
  return NULL;
}

/** PRAZDNY STROM */
int bvsJePrazdny(Tuzel *u)
{
  return u==NULL;
}

/** Vytvori novy uzel. */
Tuzel *novyUzel(float klic, int data)
{
  Tuzel *u = malloc(sizeof(Tuzel));
  if (u == NULL) return NULL;
  u->klic = klic;
  u->data = data;
  u->levy = u->pravy = NULL;
  return u;
}

/** VKLADANI KLICE */
int bvsVloz(Tuzel **u, float klic, int data)
{
  Tuzel *uzel = *u;

  if (uzel == NULL)
  {
    *u = novyUzel(klic, data);
    if (*u == NULL)
      return NEUSPECH;
    else
      return USPECH;
  }
  if (uzel->klic == klic)
    return NEUSPECH;
  else if (klic < uzel->klic)
    return bvsVloz(&uzel->levy, klic, data);
  else
    return bvsVloz(&uzel->pravy, klic, data);
}


/** HLEDANI KLICE */
int bvsHledej(Tuzel *u, float klic)
{
  if (u == NULL) return NENALEZENO;
  if (u->klic == klic) return u->data;
  if (klic < u->klic)
    return bvsHledej(u->levy, klic);
  else
    return bvsHledej(u->pravy, klic);
}

/** Zrusi zadany uzel. */
void ruseni(Tuzel **uzel)
{
  Tuzel *pom = *uzel;
  if (pom == NULL) return;
  if (pom->levy == NULL)
  {
    *uzel = pom->pravy;
    free(pom);
  }
  else if (pom->pravy == NULL)
  {
    *uzel = pom->levy;
    free(pom);
  }
  else if (pom->levy->pravy == NULL)
  {
    pom->klic = pom->levy->klic;
    ruseni(&pom->levy);     // nezapomenout na referenční operátor
  }
  else
  {
    pom = pom->levy;
    while (pom->pravy->pravy != NULL) // teď už stačí jít po pravé větvi
    {
      pom = pom->pravy;
    }

    (*uzel)->klic = pom->pravy->klic;  // kopie klíče do "rušeného uzlu"
    (*uzel)->data = pom->pravy->data;  // kopie dat do "rušeného uzlu"

    ruseni(&pom->pravy);     // nezapomenout na referenční operátor
  }
}

/** ODEBRANI KLICE */
int bvsOdeber(Tuzel **u, float klic)
{
  Tuzel *uzel = *u;
  if (uzel == NULL) return NEUSPECH;
  if (klic == uzel->klic)
  {
    ruseni(u);
    return USPECH;
  }
  else if (klic < uzel->klic)
    return bvsOdeber(&uzel->levy, klic);
  else
    return bvsOdeber(&uzel->pravy, klic);
}


/** ZRUSENI STROMU */
void bvsZrus(Tuzel **koren)
{
  Tuzel *u = *koren;
  if (u == NULL) return;
  bvsZrus(&u->levy);
  bvsZrus(&u->pravy);
  free(u);
  *koren = NULL;
}

/** Pomocna funkce pro tisk stromu. */
unsigned int bvsPoc1(Tuzel *u)
{
  if (u == NULL)
    return 0;
  else
    return bvsPoc1(u->levy) + bvsPoc1(u->pravy) + 1;
}


/** Pomocna funkce pro tisk stromu. */
unsigned int bvsPoc2(Tuzel *u)
{
  if (u == NULL)
    return 0;
  else
  {
    unsigned int jeden = bvsPoc2(u->levy);
    unsigned int druhy = bvsPoc2(u->pravy);
    return 1 + ((jeden > druhy)? jeden:druhy);
  }
}


/**
 * Pomocná funkce sloužící k ladícímu výpisu binárního stromu.
 * Projde stromem průchodem vlevo-kořen-vpravo.
 * Do pole uzly uloží ukazatele na uzly ve správném pořadí podle klíčů.
 * Do pole uroven vloží úroveň, ve které se nachází uzel z pole uzly.
 */
void stromNaPole(Tuzel *uzel, Tuzel *uzly[], unsigned int uroven[], int *index, int vyska)
{
  if (uzel == NULL) return;
  stromNaPole(uzel->levy, uzly, uroven, index, vyska+1);
  uzly[*index] = uzel;
  uroven[*index] = vyska;
  (*index)++;
  stromNaPole(uzel->pravy, uzly, uroven, index, vyska+1);
}


/**
 * Vytiskne hodnoty uložené ve stromu tak, že každou úroveň stromu vytiskne
 * na jeden řádek. Použitelné pro ladící účely. Pozor! Strom musí být ve
 * stavu, kdy se jím dá bezpečně procházet. Pokud listy nemají své podstromy
 * nastaveny na NULL, ale jsou v nich náhodné adresy, skončí tato operace
 * havárií.
 */
void bvsTisk(Tuzel *koren)
{
  if (koren == NULL)
  {
    printf("NULL\n");
    return;
  }
  printf("\n\n");
  unsigned int mm = bvsPoc1(koren);
  unsigned int nn = bvsPoc2(koren);

  Tuzel *uzly[mm];
  unsigned int uroven[mm];
  int index = 0;

  stromNaPole(koren, uzly, uroven, &index, 0);

  for (unsigned int u = 0; u < nn; u++)
  {
    printf("Uroven %2d: ", u);
    for(unsigned int i = 0; i < mm; i++)
    {
      if(uroven[i] == u)
      {
        printf("%s[%5g]%s",
               (uzly[i]->levy == NULL)? "|-" : "<-",
               uzly[i]->klic,
               (uzly[i]->pravy == NULL)? "-|" : "->");
      }
      else
      {
        printf("          ");
      }
    }
    printf("\n");
  }
}
