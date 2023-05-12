/*
 * Projekt:
 * Autor:
 * Datum:
 */

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cifra(int znak) {
  znak = tolower(znak);
  if (znak >= '0' && znak <= '9') {
    return znak - '0';
  }
  if (znak >= 'a' && znak <= 'z') {
    return znak - 'a' + 10;
  }
  if (znak >= 'A' && znak <= 'Z') {
    return znak - 'A' + 10;
  }
}

void cti(FILE *vstup) {
  int soustava;
  fscanf(vstup, "%d:", &soustava);
  printf("Prevod z %d do 10 soustavy\n", soustava);

  int vystup = 0;
  int znak;
  while ((znak = fgetc(vstup)) != '\n') {
    // int toNum = znak - '0';
    int toNum = cifra(znak);
    // TOTO JE HORNER
    vystup *= soustava;
    vystup += toNum;
  }
  printf("%d\n\n", vystup);
}

// int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void) {

  FILE *f = fopen("vstup.txt", "r");

  if (f == NULL) {
    return 1;
  }

  cti(f);
  cti(f);
  cti(f);

  fclose(f);

  return 0;
}
