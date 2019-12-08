/*
 * Projekt:   Program3
 * Autor:     Jakub Andrysek
 * Datum:   2019-12-8
 */

#include <stdio.h>
#include <stdlib.h>

// zkratka
typedef unsigned int uint;


void ukol1(void)
{
  printf("Makej!\n");
}

void Serazeni_od_nejmensiho2(void)
{
  float a;
  printf("Zadej cislo:\n");
  scanf("%f",&a);

  float b;
  printf("Zadej cislo:\n");
  scanf("%f",&b);


  if(b<a)
  {
    float c = b;
    b = a;
    a=c;
  }

  printf("Serazene:%g, %g\n",a,b);  //%g-smaze prebutecne nuly
}
/////////////////////////////////

void ukol2(void)
{
  float a;
  printf("Zadej cislo:\n");
  scanf("%f",&a);

  float b;
  printf("Zadej cislo:\n");
  scanf("%f",&b);

  float c;
  printf("Zadej cislo:\n");
  scanf("%f",&c);

  if(a>b)
  {
    float pom = a;
    a = b;
    b=pom;

  }
  if(b>c)
  {
    float pom = b;
    b = c;
    c=pom;

  }
    if(a>b)
  {
    float pom = a;
    a = b;
    b=pom;

  }

  printf("Serazene:%g, %g, %g\n",a,b,c);  //%g-smaze prebutecne nuly
}

///////////////////////

void serad_funkce(float *a, float *b)
{
  if (*a > *b)
  {
    float pom = *a;
    *a = *b;
    *b = pom;
  }
}

void ukol2_funk(void)
{
  float a;
  printf("Zadej cislo:\n");
  scanf("%f",&a);

  float b;
  printf("Zadej cislo:\n");
  scanf("%f",&b);

  float c;
  printf("Zadej cislo:\n");
  scanf("%f",&c);

  serad_funkce(&a, &b);
  serad_funkce(&b, &c);
  serad_funkce(&a, &b);

  printf("Serazene:%g, %g, %g\n",a,b,c);  //%g-smaze prebutecne nuly
}

void ukol3 (void)
{
  int n;
  printf("Zadej cislo\n");
  scanf("%d",&n);
  for(int i = 0; i<n;i++)
  {
    printf("Kuba\n");
  }
}



void ukol4For()
{
  int n = 0;
  printf("For\nZadej cislo N\n");
  scanf("%d",&n);
  for(int i = 1; i<=n; i++)
  {
    printf("%d ", i);
  }
}

void ukol4While()
{
  int n = 0, i = 1;
  printf("While\nZadej cislo N\n");
  scanf("%d",&n);
  while(i<=n)
  {
    printf("%d ", i);
    i++;
  }
}

void ukol4DoWhile()
{
  int n = 0, i = 1;
  printf("Do While\nZadej cislo N\n");
  scanf("%d",&n);
  do
  {
    printf("%d ", i);
    i++;
  }while(i<=n);
}


int main(void)
{
  //Serazeni_od_nejmensiho2();
  //ukol2();
  //ukol2_funk();
  //ukol3();
  //ukol4For();
  //ukol4While();
  //ukol4DoWhile();

  return 0;
}



