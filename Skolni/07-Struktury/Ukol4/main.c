/**
* Autor         Jakub Andrysek
* Vytvoreno     2020-4-20
* Projekt       Zastoupeni OS ve svete
* Zdroj udaju   https://netmarketshare.com/operating-system-market-share.aspx?options=%7B%22filter%22%3A%7B%22%24and%22%3A%5B%7B%22deviceType%22%3A%7B%22%24in%22%3A%5B%22Desktop%2Flaptop%22%2C%22Mobile%22%5D%7D%7D%5D%7D%2C%22dateLabel%22%3A%22Trend%22%2C%22attributes%22%3A%22share%22%2C%22group%22%3A%22platform%22%2C%22sort%22%3A%7B%22share%22%3A-1%7D%2C%22id%22%3A%22platformsDesktop%22%2C%22dateInterval%22%3A%22Monthly%22%2C%22dateStart%22%3A%222019-04%22%2C%22dateEnd%22%3A%222020-03%22%2C%22tableOrder%22%3A%5B%5B2%2C%22desc%22%5D%5D%2C%22plotKeys%22%3A%5B%7B%22platform%22%3A%22Linux%22%7D%2C%7B%22platform%22%3A%22Android%22%7D%2C%7B%22platform%22%3A%22Windows%22%7D%2C%7B%22platform%22%3A%22iOS%22%7D%2C%7B%22platform%22%3A%22Mac%20OS%22%7D%5D%2C%22segments%22%3A%22-1000%22%7D
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_POCET 10

typedef struct
{
  char nazev[21];
  int vznik;
  int zastoupeni;
  char vyvoj[21];
}SYSTEM;


/*tuto funkci jsem nasla na netu: http://programujte.com/forum/vlakno/189-smazani-obrazovky/
Prevzato z prikladu*/
void clrscr(){
  #ifndef unix
    system("CLS");
  #else
   system("clear");
  #endif
}

void menu()
{
  printf("\n          Vyber akci\n");
  printf("-> Konec....................0\n");
  printf("-> Vypis vsechny OS.........1\n");
  printf("-> Nejpouzivanejsi OS.......2\n");
  printf("-> Filtr OS podle vzniku....3\n");
  printf("-> Filtr OS podle procent...4\n");
  printf("-> Vyhledej vyvojare........5\n");
  printf("-> Pridani noveho OS........6\n");
  printf("ID: ");
}

void cara(){printf("************************************************\n");}
void hlavicka(){cara(); printf("|   Nazev  | Vznik | Zastoupeni |  Vyvoj       |\n");cara();}
void nenalezeno(){printf("Nic nenalezeno :-(\n");}
void nl(){printf("\n");}

void vypisSystemy(SYSTEM sys[],int pocet)
{

  hlavicka();
  int x = 0;
  for(int i = 0; i<pocet; i++)
  {
    printf("| %8s | %5d | %9d\% | %12s |\n",sys[i].nazev, sys[i].vznik, sys[i].zastoupeni, sys[i].vyvoj);
  }
  cara();
}

void vypisSystemyVse(SYSTEM sys[],int pocet)
{
  printf("Vypis nejpouzivanejsich operacnich systemu\n\n");
  vypisSystemy(sys, pocet);
}

void vypisSystemZastoup(SYSTEM sys[],int pocet)
{
  printf("OS s nejvetsim zastoupenim\n\n");
  int pomocna = 0;
  for(int i = 1; i<pocet; i++)
  {
    if(sys[i].zastoupeni>sys[pomocna].zastoupeni)
    {
      pomocna = i;
    }
  }
  hlavicka();
  printf("| %8s | %5d | %9d\% | %12s |\n",sys[pomocna].nazev, sys[pomocna].vznik, sys[pomocna].zastoupeni, sys[pomocna].vyvoj);
  cara();
}

void filtrujSystemyRok(SYSTEM sys[], int pocet)
{
  printf("FILTROVANI\nZobraz OS vznikle po roce: ");
  int rok;
  scanf("%d", &rok);
  nl();
  hlavicka();
  int x = 0;
  for(int i = 0; i<pocet; i++)
  {
    if(sys[i].vznik > rok)
    {
      printf("| %8s | %5d | %9d\% | %12s |\n",sys[i].nazev, sys[i].vznik, sys[i].zastoupeni, sys[i].vyvoj);
    }
  }
  cara();
}


void filtrujSystemyZastoupeni(SYSTEM sys[], int pocet)
{
  printf("FILTROVANI\n");
  int zastoupeni;
  do
  {
    printf("Zobraz OS s procentualnim zastoupneim vetsim nez: ");
    scanf("%d", &zastoupeni);
  }while(zastoupeni<=0 || zastoupeni>=100);

  nl();
  hlavicka();
  int x = 0;
  for(int i = 0; i<pocet; i++)
  {
    if(sys[i].zastoupeni > zastoupeni)
    {
      printf("| %8s | %5d | %9d\% | %12s |\n",sys[i].nazev, sys[i].vznik, sys[i].zastoupeni, sys[i].vyvoj);
    }
  }
  cara();
}

void vyhledejSystemVyvoj(SYSTEM sys[], int pocet)
{
  printf("VYHLEDAVANI\n");
  char vyvoj[21];
  int nalezeno = 0;
  scanf("%20s", vyvoj);
  nl();
  hlavicka();
  int x = 0;
  for(int i = 0; i<pocet; i++)
  {
    if(strcmp(vyvoj, sys[i].vyvoj)==0)
    {
      printf("| %8s | %5d | %9d\% | %12s |\n",sys[i].nazev, sys[i].vznik, sys[i].zastoupeni, sys[i].vyvoj);
      nalezeno++;
    }
  }

  if(nalezeno == 0)
  {
    printf("Nebyl nalezen zadny vysledek\n");
  }
  cara();
}

int pridejSystem(SYSTEM sys[], int realnyPoc)
{
  if(realnyPoc+1 <=MAX_POCET)
  {
    printf("Zadej nazev OS: ");
    scanf("%20s", sys[realnyPoc].nazev);
    printf("Zadej rok vzniku OS: ");
    scanf("%d", &sys[realnyPoc].vznik);
    int zastoupeni;
    do
    {
      printf("Zadej procentualni zastoupeni OS: ");
      scanf("%d", &zastoupeni);
    }while(zastoupeni<=0 || zastoupeni>=100);
    sys[realnyPoc].zastoupeni = zastoupeni; //Soucet procent vsech OS bohuzel nebude davat 100% musel by se udelat prepocet

    printf("Zadej spolecnost, ktera vyvyji OS: ");
    scanf("%20s", sys[realnyPoc].vyvoj);

    return 1;
  }
  else
  {
    printf("Nepodarilo se pridat senzor. V pameti neni dostatek mista :-(\n");
    return 0;
  }
}

int main()
{

  SYSTEM systemy[MAX_POCET]={
    {"Android", 2008, 42, "Google"},
    {"Windows", 1985, 37, "Microsoft"},
    {"iOS"    , 2007, 16, "Apple"},
    {"Mac OS" , 2001, 4   , "Apple"},
    {"Linux"  , 1991, 1, "Open source"}
  };
  int realnyPocet = 5;
  printf("Zastoupeni operacnich systemu(OS)\n");
  printf("   Vytvoril Jakub Andrysek\n");

  int id;
  do
  {
    menu();
    scanf("%d", &id);
    clrscr();
    switch (id)
    {
      case 0:
        printf("Dekuji za vyuziti meho softwaru :-)\n");
        break;
      case 1:
        vypisSystemyVse(systemy, realnyPocet);
        break;
      case 2:
        vypisSystemZastoup(systemy, realnyPocet);
        break;
      case 3:
        filtrujSystemyRok(systemy, realnyPocet);
        break;
      case 4:
        filtrujSystemyZastoupeni(systemy, realnyPocet);
        break;
      case 5:
        vyhledejSystemVyvoj(systemy, realnyPocet);
        break;
      case 6:
        realnyPocet += pridejSystem(systemy, realnyPocet);
        break;
      default:
        printf("Na tuto akci jeste neumim reagovat\n");
    }
  }while(id != 0);
}
