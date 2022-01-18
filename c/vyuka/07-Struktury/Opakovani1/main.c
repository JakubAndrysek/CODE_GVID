/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char cj[20];
  char aj[20];
}SLOVO;

//dopln vypis celeho pole struktur
void vypisSlovniku(SLOVO s[], int n){
  for(int i=0; i<n; i++)
  {
    printf("%10s -> %s\n", s[i].cj, s[i].aj);
  }

}

//funkce, ktera smaze obrazovku
void clrscr(){
  #ifndef unix
    system("CLS");
  #else
   system("clear");
  #endif
}

void menu(){
    printf("Preklad slova z CJ do AJ ................. 1\n");
    printf("Preklad slova z AJ do CJ ................. 2\n");
    printf("Vypis celeho slovniku  ................... 3\n");
    printf("Preklad vety z CJ do AJ .................. 4\n");
    printf("Preklad vety z AJ do CJ .................. 5\n");
    printf("Preklad slova univerzalni................. 6\n");
    printf("Ukoncit program .......................... 0\n");
}

//dopln funkci pro preklad slova z cj do aj
void cjdoaj(char p[], SLOVO s[], int n, char vysledek[]){
  for(int i = 0; i<n; i++)
  {
    if(strcmp(p, s[i].cj) == 0)
    {
        //printf("\n%s -> %s\n\n", s[i].cj, s[i].aj);
        strcpy(vysledek, s[i].aj);
        return;
    }
  }
  strcpy(vysledek, "NULL");
}

//dopln funkci pro preklad slova z aj do cj
void ajdocj(char p[], SLOVO s[], int n, char vysledek[]){
  for(int i = 0; i<n; i++)
  {
    if(strcmp(p, s[i].aj) == 0)
    {
        //printf("\n%s -> %s\n\n", s[i].aj, s[i].cj);
        strcpy(vysledek, s[i].cj);
        return;
    }
  }
  strcpy(vysledek, "NULL");
}


void preloz(char p[], SLOVO s[], int n, char vysledek[]){
  for(int i = 0; i<n; i++)
  {
    if(strcmp(p, s[i].cj) == 0)
    {
        //printf("\n%s -> %s\n\n", s[i].cj, s[i].aj);
        strcpy(vysledek, s[i].aj);
        return;
    }
  }
  for(int i = 0; i<n; i++)
  {
    if(strcmp(p, s[i].aj) == 0)
    {
        //printf("\n%s -> %s\n\n", s[i].aj, s[i].cj);
        strcpy(vysledek, s[i].cj);
        return;
    }
  }
  strcpy(vysledek, "NULL");
}

void cjdoaj_veta(char p[], SLOVO s[], int n, char vysledek[]){
  strcpy(vysledek, p);

  char * pch;
  pch = strtok (p," ,.-");
  while (pch != NULL)
  {
    printf ("*%s*\n",pch);


    for(int i = 0; i<n; i++)
    {
      if(strcmp(pch, s[i].cj) == 0)
      {
          printf("%s ", s[i].aj);
          //strcpy(vysledek, s[i].aj);
          return;
      }
    }
    printf("- ");



    pch = strtok (NULL, " ,.-");
  }
  printf("\n\n");



}



void vypis(char vysledek[])
{
  if(strcmp(vysledek, "NULL")!= 0)
  {
    printf("\nPrelozeno: %s\n\n", vysledek);
  }
  else
  {
    printf("\nNenalezen preklad\n\n");
  }

}

void nactiSlovo(char s[]){
    printf("Zadej slovo, ktere chces prelozit: ");
    scanf("%20s",s);

}


void nactiVetu(char s[]){
    printf("Zadej vetu, kterou chces prelozit: \n");
    //fgets(s, 200, stdin);
    scanf("%200[^.].",s);
}

int main()
{
    SLOVO slovnik[100]={{"pes","dog"},{"je","is"}, {"zvire","animal"}, {"ja","I"}, {"jsem","am"}, {"student","student"}, {"chlapec","boy"},
     {"on","he"}, {"strom","tree"}, {"kocka","cat"}, {"divka","girl"}, {"budoucnost","future"}, {"muj","my"}, {"oblibeny","favourite"},
     {"predmet","subject"},{"matematika","mathematics" }, {"a","and"}};


    int volba=1, n=17;
    char preklad[201];
    char vysledek[201];
    while (volba!=0){

      menu();
      scanf("%d",&volba);
      clrscr();
      switch (volba){
        case 0: printf("\n\n*****Good Bye*****\n\n");break;
        case 1: nactiSlovo(preklad);cjdoaj(preklad, slovnik, n, vysledek); vypis(vysledek); break;
        case 2: nactiSlovo(preklad);ajdocj(preklad, slovnik, n, vysledek); vypis(vysledek); break;
        case 3: vypisSlovniku(slovnik, n);break;
        case 4: nactiVetu(preklad);cjdoaj_veta(preklad, slovnik, n, vysledek); break;
        case 6: nactiSlovo(preklad);preloz(preklad, slovnik, n, vysledek); vypis(vysledek); break;

        default: printf("\n*****Tato volba neexistuje******\n\n");
      }
    }

    return 0;
}
