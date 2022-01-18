#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int citatel,jmenovatel;
}ZLOMEK;

void menu(){
  printf("Konec ....................... 0\n");
  printf("Soucet zlomku ............... 1\n");
  printf("Rozdil zlomku ............... 2\n");
  printf("Soucin zlomku ............... 3\n");
  printf("Podil  zlomku ............... 4\n");
  printf("Zkraceni prvniho zlomku  .... 5\n");
  printf("Zkraceni druheho zlomku  .... 6\n");
  printf("Novy prvni zlomek ........... 7\n");
  printf("Novy druhy zlomek ........... 8\n");

}
int nsd(int a, int b){
  int pom;
  while(b != 0){
    pom=a % b;
    a = b;
    b = pom;
  }
  return (a);
}
ZLOMEK zkraceniZlomku(ZLOMEK z){
  printf("%d/%d = ",z.citatel,z.jmenovatel);
  //tady doplňte kód, který zkrátí aktuální zlomek z
  //využijte funkci nsd, kterou jsem vám napsala, znaménka neřešte
  int x = nsd(z.citatel, z.jmenovatel);
  z.citatel/=x;
  z.jmenovatel/=x;
  printf("%d/%d\n",z.citatel,z.jmenovatel);
  return z;
}

void soucet(ZLOMEK z1, ZLOMEK z2){
  ZLOMEK pom;
  pom.jmenovatel = z1.jmenovatel*z2.jmenovatel;
  pom.citatel = z2.jmenovatel*z1.citatel + z1.jmenovatel*z2.citatel;
  printf("%d/%d +  %d/%d = %d/%d\n",z1.citatel, z1.jmenovatel, z2. citatel, z2.jmenovatel, pom.citatel, pom.jmenovatel);
}
void rozdil(ZLOMEK z1, ZLOMEK z2){
  ZLOMEK pom;
  pom.jmenovatel = z1.jmenovatel*z2.jmenovatel;
  pom.citatel = z2.jmenovatel*z1.citatel - z1.jmenovatel*z2.citatel;
  printf("%d/%d – %d/%d = %d/%d\n",z1.citatel, z1.jmenovatel, z2. citatel, z2.jmenovatel, pom.citatel, pom.jmenovatel);
}
void soucin(ZLOMEK z1, ZLOMEK z2){
  ZLOMEK pom;
  pom.jmenovatel = z1.jmenovatel*z2.jmenovatel;
  pom.citatel = z1.citatel*z2.citatel;
  printf("%d/%d * %d/%d = %d/%d\n",z1.citatel, z1.jmenovatel, z2. citatel, z2.jmenovatel, pom.citatel, pom.jmenovatel);
}
void podil(ZLOMEK z1, ZLOMEK z2){
  ZLOMEK pom;
  pom.jmenovatel = z1.jmenovatel*z2.citatel;
  pom.citatel = z1.citatel*z2.jmenovatel;
  printf("%d/%d / %d/%d = %d/%d\n",z1.citatel, z1.jmenovatel, z2. citatel, z2.jmenovatel, pom.citatel, pom.jmenovatel);
}
ZLOMEK novy(){
  ZLOMEK novy;
  printf("Zadej citatel: ");
  scanf("%d",&novy.citatel);
  do{
  printf("Zadej jmenovatel ruzny od nuly: ");
  scanf("%d",&novy.jmenovatel);
  }while(novy.jmenovatel==0);
  printf("Novy zlomek: %d/%d\n",novy.citatel,novy.jmenovatel);
  return novy;

}

int main(void) {
  //budeme pracovat se dvěma zlomky
  ZLOMEK z1 ={5,25};
  ZLOMEK z2 ={1,3};
  int volba=1;
  while (volba!=0){
    menu();
    scanf("%d",&volba);
    switch (volba){
      case 1: soucet(z1,z2);
              break;
      case 2: rozdil(z1,z2);
              break;
      case 3: soucin(z1,z2);
              break;
      case 4: podil(z1,z2);
              break;
      case 5: z1=zkraceniZlomku(z1);
              break;
      case 6: z2=zkraceniZlomku(z2);
              break;
      case 7: z1=novy();
              break;
      case 8: z2=novy();
              break;
      default: printf("Tato volba je neplatna.\n");break;
    }
  }

  printf("\nKonec");
  return 0;
}
