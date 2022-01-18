#include <stdio.h>
#include <stdlib.h>
/* Program, ktery ovlada jednoduchy seznam sopek. Kazda sopka ma ctyri polozky. Pomoci switche
   volime, co s programem delat: vypsat, vlozit novou sopku, najit nejvysi sopku a vypsat
   pouze cinne sopky */


//definice struktury musi byt globalni
typedef struct{
   char nazev[15];
   char stat[15];
   int vyska;
   int cinna; // 0 je-li vyhasla, vsechno ostatni je cinna
}SOPKA;

//pouhy vypis voleb do switche
void menu(){
  printf("\nZvol si akci:\n");
  printf("Ukonci program ...........0\n");
  printf("Vypis sopek ..............1\n");
  printf("Pridej sopku .............2\n");
  printf("Nejvyssi sopka ...........3\n");
  printf("Vypis cinnych sopek ......4\n");
}
/*tuto funkci jsem nasla na netu: http://programujte.com/forum/vlakno/189-smazani-obrazovky/
*/
void clrscr(){
  #ifndef unix
    system("CLS");
  #else
   system("clear");
  #endif
}


//vypise n polozek pole struktur
void vypis(SOPKA s[],int n){
  int i;
  clrscr();
  printf("Seznam sopek\n");
  printf("************\n");
  printf("           Nazev            Stat    Vyska   Cinna?\n");
  printf("**************************************************\n");
  for (i=0;i<n;i++){
    printf("%16s%16s%7d m",s[i].nazev,s[i].stat,s[i].vyska);
    if (s[i].cinna)
        printf("    cinna\n");
    else
        printf("  vyhasla\n");
  }
  printf("\n");
}

//prida novou sopku na konec pole, pokud to jde
void pridej(SOPKA s[], int n){
  printf("Napis nazev nove sopky: ");
  scanf("%14s",s[n].nazev);  //nepiseme &, jedna se o retezec
  printf("Napis stat, ve kterem se sopka nachazi: ");
  scanf("%14s",s[n].stat); //nepiseme &, jedna se o retezec
  printf("Napis vysku nove sopky: ");
  scanf("%d",&s[n].vyska);
  printf("Je sopka cinna? je - 1, neni - 0 ");
  scanf("%d",&s[n].cinna);
  printf("Nova sopka uspesne vlozena.\n");
}

//vypise nejvyssi sopku, pouhe nalezeni maxima
void nejsopka(SOPKA s[], int n){
  int pom=0,i;
  for (i=1;i<n;i++)
    if (s[pom].vyska < s[i].vyska)
        pom = i; //hledam pozici, ne hodnotu
  printf("Nejvyssi sopka v nasem seznamu je %s a meri %d metru.\n",s[pom].nazev, s[pom].vyska);
}

//filtr – vypis cinnych sopek
void vypis_cinnych(SOPKA s[], int n){
 int i;

  printf("Seznam cinnych sopek\n");
  printf("********************\n");
  printf("           Nazev            Stat    Vyska   Cinna?\n");
  printf("**************************************************\n");
  for (i=0;i<n;i++){
    if (s[i].cinna){
        printf("%16s%16s%7d m",s[i].nazev,s[i].stat,s[i].vyska);
        if (s[i].cinna)
            printf("    cinna\n");
        else
            printf("  vyhasla\n");
    }//konec podminky
  }//konec for cyklu
  printf("\n");
}

int main()
{
    SOPKA sopky[10]={{"Etna","Italie",3550,1}, {"Hekla","Island", 1491,1},
                     {"Fudzi","Japonsko",3776,1},{"Chodutka","Rusko",2090,0},
                     {"Mount Bachelor","USA",2763,0}};
     // 5 zaznamu povinne doplnite do definice pole struktur

    int n=5,volba=1;
    printf("SOPKY 1.0\n");
    while(volba!=0){
      menu();
      scanf("%d",&volba);
      clrscr();//smaze obrazovku
      switch (volba){
        case 0: printf("Goog Bye!!!");break;
        case 1: vypis(sopky,n);break;
        case 2: if (n<10){
                    pridej(sopky,n);
                    n++;
                }
                else
                    printf("Sorry, uz neni misto.\n");
                break;
        case 3: nejsopka(sopky,n);break;
        case 4: vypis_cinnych(sopky,n);break;
        default: printf("Netrefil ses, zadej volbu znovu!\n");break;
      } //konec prikazu switch
    }//konec cyklu while
    return 0;
}
