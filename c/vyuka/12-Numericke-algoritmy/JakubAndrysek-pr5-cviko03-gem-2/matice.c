/* Modul pro práci s maticemi.
 *
 * Copyright (c) David Martinek, 2018--2022
 */

#include "matice.h"
#include <stdio.h>
#include <stdlib.h>


/** \brief Vytvoří matici zadaných rozměrů.*/
Tmatice * maticeAlokuj(int radku, int sloupcu)
{
  if (radku >= 0 && radku <= MATICE_MAX_VELIKOST &&
      sloupcu >= 0 && sloupcu <= MATICE_MAX_VELIKOST)
  {
    // Tady se dynamicky alokuje jen struktura typu Tmatice.
    // Samotné pole uvnitř má v této implementaci pevné rozměry, přičemž
    // my z něj využijeme jen část odpovídající rozměrům radku a sloupcu.
    // Skutečně dynamická 2D matice se dělá jinak.
    Tmatice * m = malloc(sizeof(Tmatice));
    if (m == NULL)
      return NULL;

    m->radku = radku;
    m->sloupcu = sloupcu;

    return m;
  }
  else
  {
    return NULL;
  }
}

/** \brief Zruší zadanou matici.*/
void maticeUvolni(Tmatice *matice)
{
  free(matice);
  // Takto jednoduše to jde jen v naší primitivní implementaci. Skutečné
  // 2D dynamické pole by se muselo rušit postupně po řádcích.
}

/** \brief Inicializuje všechny prvky matice počáteční hodnotou.*/
void maticeNastavPrvky(Tmatice *matice, float initValue)
{
  for (int r = 0; r < matice->radku ; ++r)
  {
    for (int s = 0; s < matice->sloupcu ; ++s)
    {
      matice->prvek[r][s] = initValue;
    }
  }
}

/** \brief Inicializuje všechny prvky matice náhodnými hodnotami. */
void maticeRandom(Tmatice *matice)
{
  for (int r = 0; r < matice->radku ; ++r)
  {
    for (int s = 0; s < matice->sloupcu ; ++s)
    {
      {
        matice->prvek[r][s] = (float)((rand()%2000)-1000) / 100;
      }
    }
  }
}


/** \brief Vytiskne matici na obrazovku.*/
void maticeTiskni(const Tmatice *matice)
{
  maticeTiskniSoubor(stdout, matice);
}

/** \brief Vytiskne matici do souboru.*/
void maticeTiskniSoubor(FILE *file, const Tmatice *matice)
{
  fprintf(file, "%u %u\n", matice->radku, matice->sloupcu);
  for (int r = 0; r < matice->radku ; ++r)
  {
    for (int s = 0; s < matice->sloupcu ; ++s)
    {
      fprintf(file, "%7.2f ", matice->prvek[r][s]);
    }
    fprintf(file, "\n");
  }
}

/** \brief Vytvoří a přečte matici ze standardního vstupu (klávesnice).*/
Tmatice * maticeCtiZeVstupu(int *chyba)
{
  return maticeCtiZeSouboru(stdin, chyba);
}

/** \brief Vytvoří a přečte matici ze souboru.*/
Tmatice *maticeCtiZeSouboru(FILE *file, int *chyba)
{
  int radku, sloupcu;
  int ecode =  fscanf(file, "%d %d", &radku, &sloupcu);
  if (ecode != 2)
  {
    *chyba = EMREAD;
    return NULL;
  }

  Tmatice* matice = maticeAlokuj(radku, sloupcu);
  if (matice == NULL)
  {
    *chyba = EMCREATE;
    return NULL;
  }

  matice->radku = radku;
  matice->sloupcu = sloupcu;

  for (int r = 0; r < matice->radku ; ++r)
  {
    for (int s = 0; s < matice->sloupcu ; ++s)
    {
      ecode = fscanf(file, "%f ", &matice->prvek[r][s]);
      if (ecode != 1)
      {
        maticeUvolni(matice);
        *chyba = EMREAD;
        return NULL;
      }
    }
  }

  *chyba = EMOK;
  return matice;
}

 /** \brief Vymění v matici řádky zadané pomocí indexů.*/
void maticeVymenRadky(Tmatice *m, int r1, int r2)
{
  if (r1 == r2 || r1*r2 <= 0 || r1 >= m->radku || r2 >= m->radku)
    return;

  for (int s = 0; s < m->sloupcu; ++s)
  {
    float pom = m->prvek[r1][s];
    m->prvek[r1][s] = m->prvek[r2][s];
    m->prvek[r2][s] = pom;
  }
}


int maxAbsPivot(Tmatice *matice, int d) {
    int max = d;
    for(int r = 1; r < matice->radku; r++) {
        if(fabs(matice->prvek[r][d]) > matice->prvek[max][d]) {
            max = r;
        }
    }
    return max;
}

void radkoveUpravy(Tmatice* matice, int r) {
    for(int k = r+1; k <= matice->radku-1; k++) {
        float c = matice->prvek[k][r] / matice->prvek[r][r];
        matice->prvek[k][r] = 0.0f;
        for(int s = r+1; s <= matice->radku; s++) {
            matice->prvek[k][s] = c*matice->prvek[r][s] - matice->prvek[k][s];
//            printf("rad set [%d][%d]\n", k, s);
//            tiskM(stdout, matice);
        }
    }
}

