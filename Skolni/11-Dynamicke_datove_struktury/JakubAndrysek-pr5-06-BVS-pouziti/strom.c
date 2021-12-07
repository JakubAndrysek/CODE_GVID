/*
 * Projekt: Binární vyhledávací strom
 * Autor: David Martinek a Jakub Andrysek
 * Datum: 2020-11-11
 * Popis
 * Implementace funkcí realizující binární vyhledávací strom.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strom.h"
#include "gvid.h"


Tstrom *bvsInit(void)
{
  Tstrom* strom = malloc(sizeof(Tstrom));
  if (strom == NULL)
  {
    return NULL;
  }

  strom->koren = NULL;
  strom->vaha = 0;
  return strom;
}

void _bvsZrus(Tuzel *u)
{
  if (u == NULL) return;
  _bvsZrus(u->levy);
  _bvsZrus(u->pravy);
  free(u);
}

void bvsZrus(Tstrom *strom)
{
  _bvsZrus(strom->koren);
  free(strom);
}


bool bvsJePrazdny(Tstrom *strom)
{
  return strom->koren==NULL;
}

int bvsVaha(Tstrom* strom)
{
  return strom->vaha;
}


Tuzel *_novyUzel(char klic[], char data[])
{
  Tuzel *u = malloc(sizeof(Tuzel));
  if (u == NULL) return NULL;
  strcpy(u->klic, klic);
  strcpy(u->data, data);
  u->levy = u->pravy = NULL;
  return u;
}

bool _bvsVloz(Tuzel **u, char klic[], char data[])
{
	Tuzel *pom = *u;

  // Prazdny strom
  if(pom == NULL) {
    pom = _novyUzel(klic, data);
    if(pom == NULL) {
      return false;
    }
      *u = pom;
      return true;
  }
  else if(strcmp(klic, pom->klic)==0) {
    printf("Klic '%s' uz existuje\n", klic);
    return false;
  }
  // Klic je mensi do leva
  else if(strcmp(klic, pom->klic)<0) {
    _bvsVloz(&pom->levy, klic, data);
  }
  // Klic je vetsi do prava
  else {
    _bvsVloz(&pom->pravy, klic, data);
  }
  return true;
}

bool bvsVloz(Tstrom *strom, char klic[], char data[])
{
  if (_bvsVloz(&strom->koren, klic, data))
  {
    strom->vaha += 1;
    return true;
  }
  return false;
}

/** Zruší zadaný uzel. */
bool _zrusUzel(Tuzel **uzel)
{
  Tuzel *pom = *uzel;
  if(pom == NULL) {
    return false;
  }

  if(pom->levy == NULL) {
    *uzel = pom->pravy;
    free(pom);
    return true;
  }

  if(pom->pravy == NULL) {
    *uzel = pom->levy;
    free(pom);
    return true;
  }

  if(pom->levy->pravy == NULL) {
    strcpy(pom->levy->klic, pom->klic);
    strcpy(pom->levy->data, pom->data);
    return _zrusUzel(&pom->levy);
  }

  pom = pom->levy;
  while(pom->pravy->pravy != NULL) {
    pom = pom->pravy;
  }

  strcpy(pom->pravy->klic, (*uzel)->klic);
  strcpy(pom->pravy->data, (*uzel)->data);
  return _zrusUzel(&pom->pravy);

}

bool _bvsOdeber(Tuzel **u, char klic[])
{
  Tuzel *uzel = *u;
  if (uzel == NULL) return false;
  int rozdil = strcmp(klic, uzel->klic);
  if (rozdil==0)
  {
    _zrusUzel(u); // tady se předává odkazem, i když to tak nevypadá! u se změní
    return true;
  }
  else if (rozdil) //Mozna chyba
    return _bvsOdeber(&uzel->levy, klic);
  else
    return _bvsOdeber(&uzel->pravy, klic);
}


bool bvsOdeber(Tstrom *strom, char klic[])
{
  if (_bvsOdeber(&strom->koren, klic))
  {
    strom->vaha -= 1;
    return true;
  }
  return false;
}


int _bvsVahaIn(Tuzel *uzel) {
  if(uzel == NULL) {
    return 0;
  }

  return _bvsVahaIn(uzel->levy)+_bvsVahaIn(uzel->pravy)+1;
}

int bvsVahaIn(Tstrom *strom) {
  return _bvsVahaIn(strom->koren);
}

// je stejny jako funkce _bvsPom2
int _bvsVyska(Tuzel *uzel) {
  if(uzel == NULL) {
    return 0;
  } else {
    int levy = _bvsVyska(uzel->levy);
    int pravy = _bvsVyska(uzel->pravy);
    if(levy>pravy) {
      return 1+levy;
    } else {
      return 1+pravy;
    }
  }
}

int bvsVyska(Tstrom *strom) {
  return _bvsVyska(strom->koren);
}

// PreOrder
void _bvsPreorder(Tuzel* uzel){
  if(uzel == NULL) {
    return ;
  }

  printf("Klic: %s -> data: %s\n", uzel->klic, uzel->data);
  _bvsPreorder(uzel->levy);
  _bvsPreorder(uzel->pravy);
}

void bvsPreorder(Tstrom *strom) {
  _bvsPreorder(strom->koren);
}


// InOrder
void _bvsInorder(Tuzel* uzel){
  if(uzel == NULL) {
    return;
  }

  _bvsInorder(uzel->levy);
  printf("Klic: %s -> data: %s\n", uzel->klic, uzel->data);
  _bvsInorder(uzel->pravy);
}

void bvsInorder(Tstrom *strom) {
  _bvsInorder(strom->koren);
}

// PostOrder
void _bvsPostorder(Tuzel* uzel){
  if(uzel == NULL) {
    return;
  }
  _bvsPostorder(uzel->levy);
  _bvsPostorder(uzel->pravy);
  printf("Klic: %s -> data: %s\n", uzel->klic, uzel->data);
}

void bvsPostorder(Tstrom *strom) {
  _bvsPostorder(strom->koren);
}

int _bvsVyvazeni(Tuzel *uzel) {
  if(uzel == NULL) {
    return 0;
  } else {
    int levy = _bvsVyvazeni(uzel->levy);
    int pravy = _bvsVyvazeni(uzel->pravy);
    if(abs(levy-pravy)<=1) {
      return pravy+levy+1;
    }
    return -1;
  }
}


int bvsVyvazeni(Tstrom *strom) {
  return _bvsVyvazeni(strom->koren);
}


bool bvsJeVyvazeny(Tstrom *strom) {
  return bvsVyvazeni(strom)>=0;
}

void _bvsStromNaPole(Tuzel* uzel, Tuzel *pole[], int *index) {
  if (uzel == NULL) {
    return;
  }

  _bvsStromNaPole(uzel->levy, pole, index);
  pole[*index] = uzel;
  (*index)++;
  _bvsStromNaPole(uzel->pravy, pole, index);
}

void bvsStromNaPole(Tstrom* strom, Tuzel *uzel[], int *index) {
  _bvsStromNaPole(strom->koren, uzel, index);
}


bool _bvsHledej(Tuzel *uzel, char klic[], char hledany[]) {
  if(uzel == NULL) {
    return;
  }

  if(strcmp(uzel->klic, klic) == 0){
    strcpy(hledany, uzel->data);
    return;
  }
  _bvsHledej(uzel->levy, klic, hledany);
  _bvsHledej(uzel->pravy, klic, hledany);
}


bool bvsHledej(Tstrom *strom, char klic[], char hledany[]) {
  _bvsHledej(strom->koren, klic, hledany);
  return strlen(hledany)>0;
}


/////////////////////////////

/** Pomocna funkce pro tisk stromu. */
unsigned int _bvsPom1(Tuzel *u)
{
  return (u == NULL)? 0 : _bvsPom1(u->levy) + _bvsPom1(u->pravy) + 1;
}


/** Pomocna funkce pro tisk stromu. */
unsigned int _bvsPom2(Tuzel *u)
{
  if (u == NULL)
    return 0;
  else
  {
    unsigned int a = _bvsPom2(u->levy);
    unsigned int b = _bvsPom2(u->pravy);
    return 1 + ((a > b)? a:b);
  }
}


/**
 * Pomocná funkce sloužící k ladícímu výpisu binárního stromu.
 * Do pole uzly uloží ukazatele na uzly ve správném pořadí podle klíčů.
 * Do pole uroven vloží úroveň, ve které se nachází uzel z pole uzly.
 */
void _stromNaPole(Tuzel *uzel, Tuzel *uzly[], unsigned int uroven[], int *index, int vyska)
{
  if (uzel == NULL) return;
  _stromNaPole(uzel->levy, uzly, uroven, index, vyska+1);
  uzly[*index] = uzel;
  uroven[*index] = vyska;
  (*index)++;
  _stromNaPole(uzel->pravy, uzly, uroven, index, vyska+1);
}


/**
 * Vytiskne hodnoty uložené ve stromu tak, že každou úroveň stromu vytiskne
 * na jeden řádek. Použitelné pro ladící účely. Pozor! Strom musí být ve
 * stavu, kdy se jím dá bezpečně procházet. Pokud listy nemají své podstromy
 * nastaveny na NULL, ale jsou v nich náhodné adresy, skončí tato operace
 * havárií.
 */
void bvsTisk(Tstrom *strom, FILE* vystup)
{
  if (strom->koren == NULL)
  {
    printf("NULL\n");
    return;
  }
  printf("\n\n");
  unsigned int mm = _bvsPom1(strom->koren);
  unsigned int nn = _bvsPom2(strom->koren);

  Tuzel *uzly[mm];
  unsigned int uroven[mm];
  int index = 0;

  _stromNaPole(strom->koren, uzly, uroven, &index, 0);

  for (unsigned int u = 0; u < nn; u++)
  {
    fprintf(vystup, "Uroven %2d: ", u);
    for(unsigned int i = 0; i < mm; i++)
    {
      if(uroven[i] == u)
      {
        fprintf(vystup, "%s[%s]%s",
               (uzly[i]->levy == NULL)? "|-" : "<-",
               uzly[i]->klic,
               (uzly[i]->pravy == NULL)? "-|" : "->");
      }
      else
      {
        fprintf(vystup, "          ");
      }
    }
    fprintf(vystup, "\n");
  }
}
