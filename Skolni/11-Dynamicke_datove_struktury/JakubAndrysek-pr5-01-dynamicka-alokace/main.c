/*
 * Projekt:
 * Autor: Jakub Andrysek
 * Datum:
 */

#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

typedef struct {
  float *prvek; // dynamické pole
  int delka;
} Tpole;


Tpole * novePole(int delka)
{
  Tpole * sp = malloc(sizeof(Tpole));

  if (sp == NULL)
    return NULL;

  sp->prvek = malloc(delka*sizeof(float));

  if (sp->prvek == NULL)
  {
    free(sp);
    return NULL;
  }

  sp->delka = delka;
  return sp;
}

Tpole * nacti(FILE *in) {
  int delka;

  int e = fscanf(in, "%d", &delka);

  if(e != 1) {
    return NULL;
  }

  Tpole * pole = novePole(delka);

  for(int i = 0; i < delka; i++) {
    fscanf(in, "%f", &pole->prvek[i]);
  }

  return pole;
}

float prumer(Tpole * data) {
  float soucet = 0;
  for(int i = 0; i<data->delka; i++) {
    soucet+=data->prvek[i];
  }
  soucet/=data->delka;

  return soucet;
}

void rozdel(FILE *fPod, FILE *fNad, Tpole *data, float prumer) {
	int cPod = 0;
	int cNad = 0;

	for(int i = 0; i<data->delka; i++) {
		if(data->prvek[i]>prumer) {
			cNad++;
		}
		else {
			cPod++;
		}
	}

	fprintf(fNad, "%d\n", cNad);
	fprintf(fPod, "%d\n", cPod);

	for(int i = 0; i<data->delka; i++) {
		if(data->prvek[i]>prumer) {
			fprintf(fNad, "%g\n", data->prvek[i]);
		}
		else {
			fprintf(fPod, "%g\n", data->prvek[i]);
		}
	}
}

//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
  char nazev[31];

  printf("Zadej nazev souboru: ");
  scanf("%30s", nazev);

  FILE * fVstup = fopen(nazev, "r");
//  FILE * fVstup = fopen("dataTest.txt", "r");

  if( fVstup == NULL) {
    printf("Soubor nelze otevrit.\n");
    return EXIT_FAILURE;
  }

  FILE * fVystupPod = fopen("fVystupPod.txt", "w");

  if( fVystupPod == NULL) {

    printf("Soubor nelze otevrit.\n");
    return EXIT_FAILURE;
  }

  FILE * fVystupNad = fopen("fVystupNad", "w");

  if( fVystupNad == NULL) {
    printf("Soubor nelze otevrit.\n");
    return EXIT_FAILURE;
  }

  Tpole* data = nacti(fVstup);

  float prum = prumer(data);

	rozdel(fVystupPod, fVystupNad, data, prum);

	fclose(fVstup);
	fclose(fVystupNad);
	fclose(fVystupPod);

	free(data->prvek);
	free(data);

	printf("Program probehl uspesne\n");
}
