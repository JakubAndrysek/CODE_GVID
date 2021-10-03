/*
 * Projekt:   Program4
 * Autor:     Jakub Andrysek
 * Datum:   2019-12-8
 */

#include <stdio.h>
#include <stdlib.h>

// zkratka
typedef unsigned int uint;


void test(void)
{
  printf("Makej!\n");
}

/*////////////////////
//Bez vývojového diagramu: Naèti data svého spolužáka: jméno
(char jmeno[20]), váhu (kg, int), výšku (m, float).
////////////////////*/
void ukol1 (void)
{
  char jmeno[20];
  printf("Zadej jmeno\n");
  scanf("%19s", jmeno);

  int vaha; //v kg
  printf("Zadej vahu[kg]\n");
  scanf("%d", &vaha);

  float vyska; //v m
  printf("Zadej vysku[m]\n");
  scanf("%f", &vyska);

  printf("Muj spoluzak %s vazi %d kg a meri %.2f m\n",jmeno, vaha, vyska); //%f- desetina cisla, %.2f- 2 desetinna mista, %g- nevypisuje nuly

  char jmeno2[20];
  printf("Zadej jmeno\n");
  scanf("%19s", jmeno2);

  int vaha2; //v kg
  printf("Zadej vahu[kg]\n");
  scanf("%d", &vaha2);

  float vyska2; //v m
  printf("Zadej vysku[m]\n");
  scanf("%f", &vyska2);

  printf("Muj spoluzak2 %s vazi %d kg a meri %.2f m\n\n",jmeno, vaha, vyska);

  if(vyska>vyska2)
  {
    printf("Spoluzak %s je vyssi o %g cm nez %s\n", jmeno, ((vyska-vyska2)*100), jmeno2);
  }
  else
  {
    printf("Spoluzak %s je vyssi o %g cm nez %s\n", jmeno2, ((vyska2-vyska)*100), jmeno2);
  }



  if(vaha>vaha2)
  {
    printf("Spoluzak %s je tezsi o %d kg nez %s\n", jmeno, (vaha-vaha2), jmeno2);
  }
  else
  {
    printf("Spoluzak %s je tezsi o %d kg nez %s\n", jmeno2, (vaha2-vaha), jmeno2);
  }

}

void ukol2()
{
  float a = 0.001;
  float sum = 0;

  for (long i = 0; i < 1000; ++i)
  {
    sum+=a;
  }
  printf("%g",sum);
}

void ukol3()
{
  float x, vys;
  printf("Zadej X\n");
  scanf("%f", &x);
  vys = (3*x+5)/(2*x*x);

  printf("%2.f\n",vys);
}

void ukol4()
{
  int c;
  while((c=getchar()) != '\n' )
  {
    if(c != ' ')
    {
      putchar(c);
    }
  }
}

void ukol5()
{
  int c, poc = 0;
  while((c=getchar()) != '\n' )
  {
      putchar(c);
      poc++;
  }
  printf("\nPocet znaku %d\n",poc);
}

void ukol6()
{
  int c, maly = 0, velky = 0;
  while((c=getchar()) != '\n' )
  {
    putchar(c);
    //Velka
    if((c >= 65)&&(c<=90))
    {
      velky++;
    }
    //Mala
    if((c >= 97)&&(c<=122))
    {
      maly++;
    }
  }
  printf("\nPocet malych:%d, pocet velkych:%d\n", maly, velky);
}


int main()
{
  //ukol1();
  //ukol2();
  //ukol3();
  //ukol4();
  //ukol5();
  //ukol6();
  return 0;
}
