#include <stdio.h>
#include <string.h>


//struktura, ve které jsou tři položky stejného typu: 3 vyučovací předměty
typedef struct {
  int ivt,m,f;
}ZNAMKY;

//struktura žák, ve které je jméno, věk a další struktura známky, která musí být definovaná již předem
typedef struct {
  char jmeno[21];
  int vek;
  ZNAMKY znamky;
}ZAK;

void vypisZaka(ZAK z){
  printf("Jmeno: %s, vek: %d, známky IVT: %d, M: %d, F: %d\n", z.jmeno, z.vek, z.znamky.ivt, z.znamky.m, z.znamky.f);

}

float prumernyVek(ZAK z1, ZAK z2, ZAK z3){
  return (z1.vek + z2.vek +z3.vek)/3.;
}

ZAK nejstarsiZak(ZAK z1, ZAK z2, ZAK z3){
  ZAK pom;
  if(z1.vek>z2.vek)
    pom=z1;
  else
    pom=z2;
  if(z3.vek>pom.vek)
    return z3;
  else
    return pom;
}


//napiš funkci, který vrátí žáka, který má nejhořší známku z fyziky
ZAK nejhorsiFyzika(ZAK z1, ZAK z2, ZAK z3)
{
  ZAK pomocna;
  if(z1.znamky.f>z2.znamky.f)
  {
    pomocna = z1;
  }
  else
  {
    pomocna = z2;
  }
  if(z3.znamky.f>pomocna.znamky.f)
  {
    return z3;
  }
  else
  {
    return pomocna;
  }
}


int main(void) {
  //definice prvního žáka s inicializací
  ZAK z1={"JAN", 16, {1, 2, 2}};
  //definice druhého a třetího žáka
  ZAK z2, z3;

  //hodnoty druhého žáka zadáme po položkách
  strcpy(z2.jmeno,"PAVEL");
  z2.vek=15;
  z2.znamky.m=2;
  z2.znamky.ivt=2;
  z2.znamky.f=3;

  //hodnoty třetího žáka načteme ze standardního vstupu
  printf("Zadej jmeno tretiho zaka: ");
  scanf("%20s",z3.jmeno);
  printf("Zadej vek tretiho zaka: ");
  scanf("%d",&z3.vek);
  printf("Zadej tri znamky tretiho zaka: IVT, M, F: ");
  scanf("%d%d%d", &z3.znamky.ivt, &z3.znamky.m, &z3.znamky.f);

  vypisZaka(z1);
  vypisZaka(z2);
  vypisZaka(z3);

  printf("\nPrumerny vek vsech 3 zaku je %.2f.\n",prumernyVek(z1, z2, z3));

  printf("\nNejstarsi zak je %s.\n", nejstarsiZak(z1,z2,z3).jmeno);

  printf("\nNejhorsi prumer z F ma zak %s.\n", nejhorsiFyzika(z1,z2,z3).jmeno);

  //tady zavolate funkci, která vrátí nejhoršího žáka z fyziky a vypíšete jeho jméno.


  printf("\nKonec");
  return 0;
}
