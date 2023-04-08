/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

/*
    Vycisli se zada
*/




int horner(int num[], int n, int x) {
    int res = 0;
    for(int i =0; i < n; i++) {
        res = num[i]*x+x;
    }
    return res;
}

int cifra(char znak) {
    znak = tolower(znak);
    if(znak >= '0' && znak <= '9') {
        return znak - '0'
    }
    if(znak >= 'a' && znak <= 'z') {
        return znak - 'a';
    }
}


int vycisli(char vstup[], int soustava) {


}

void cti(FILE* vstup) {
    int soustava;
    fscanf("%d:", &soustava);

    int vystup = 0;
    char znak;
    while(znak = fgetc(vstup) != "\n") {
        printf("%c", znak);
        int toNum = znak - '0';
        vystup = vystup + toNum*soustava;
        hodnota * zaklad +
    }
    printf("%d", vystup);

}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{

  FILE* f = fopen("vstup.txt", "r");

  if(f == NULL) {
    printf("err");
    return 1;
  }

  cti(f);

  return 0;
}
