#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct  {
	int prvek[MAX][MAX];
	int sloupcu;
	int radku;
} pole2d;

FILE* openFileSafe(char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		printf("Error opening %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return f;
}


/*//////////////////////////////////////////////////////////////
// poleNacti
//////////////////////////////////////////////////////////////*/
void poleNacti(FILE * file, pole2d * pole) {
	fscanf(file, "%d %d", &pole->radku, &pole->sloupcu);

	if(pole->radku >= MAX || pole->sloupcu >= MAX) {
		printf("pole je moc velke\n");
		exit(1);
	}


	for(int r = 0; r < pole->radku; r++) {
		for (int s = 0; s < pole->sloupcu; s++) {
			if(fscanf(file, "%d ", &pole->prvek[r][s]) != 1) {
				printf("Problem s nactenim\n");
				exit(1);
			}
		}
	}
}


/*//////////////////////////////////////////////////////////////
// poleTiskni
//////////////////////////////////////////////////////////////*/
void poleTiskni(pole2d *pole) {
	printf("Pole: sloupcu %d, radku: %d\n",pole->sloupcu, pole->radku);

	for(int r = 0; r < pole->radku; r++) {
		for(int s = 0; s < pole->sloupcu; s++) {
			printf(" %2d ", pole->prvek[r][s]);
		}
		printf("\n");
	}
}


/*//////////////////////////////////////////////////////////////
// polePocetSudych
//////////////////////////////////////////////////////////////*/
void polePocetSudych(pole2d *pole) {
	for(int r = 0; r < pole->radku; r++) {
		pole->prvek[r][pole->sloupcu] = 0;
		for(int s = 0; s < pole->sloupcu; s++) {
			if(pole->prvek[r][s] % 2 == 0) {
				pole->prvek[r][pole->sloupcu] ++;
			}
		}
		printf("Pocet sydych na radku: %d je %d\n", r, pole->prvek[r][pole->sloupcu]);
	}
}


/*//////////////////////////////////////////////////////////////
// poleSouctyObvod
//////////////////////////////////////////////////////////////*/
void poleSouctyObvod(pole2d *pole) {
	int obvodove = 0;
	int vnitrni = 0;

	for(int r = 0; r < pole->radku; r++) {
		pole->prvek[r][pole->sloupcu] = 0;
		for(int s = 0; s < pole->sloupcu; s++) {
			if(r==0 || r == pole->radku-1 || s==0 | s == pole->sloupcu-1) {
				obvodove += pole->prvek[r][s];
			} else {
				vnitrni += pole->prvek[r][s];
			}
		}
	}
	printf("Soucet obvodovych: %d, vnitrnich %d\n", obvodove, vnitrni);
}


/*//////////////////////////////////////////////////////////////
// poleVertikalneSymetricke
//////////////////////////////////////////////////////////////*/
bool poleVertikalneSymetricke(pole2d *pole) {
	for(int r = 0; r < pole->radku; r++) {
		for(int s = 0; s < pole->sloupcu/2; s++) {
			if(pole->prvek[r][s] != pole->prvek[r][pole->sloupcu-s-1]){
				return false;
			}
		}
	}
	return true;
}

void testVertikalneSymetricke(char *filename) {
	FILE* f = openFileSafe(filename);

	pole2d pole;
	poleNacti(f, &pole);

	bool symV = poleVertikalneSymetricke(&pole);

	printf("2D pole %s je vertikalne symetricke: %d\n", filename, symV);
}


/*//////////////////////////////////////////////////////////////
// poleOtocMatici90clock
//////////////////////////////////////////////////////////////*/
void poleOtocMatici90clock(pole2d *pole, pole2d *res) {
	res->radku = pole->radku;
	res->sloupcu = pole->sloupcu;

	for(int r = 0; r < pole->radku; r++) {
		pole->prvek[r][pole->sloupcu] = 0;
		for(int s = 0; s < pole->sloupcu; s++) {
			// prehodit sloupce a radky (u nich pocet sloupcu minus radky -1)
			res->prvek[s][r] = pole->prvek[pole->sloupcu-r-1][s];
		}
	}
}

void testOtocMatici90clock(char *filename) {
	FILE* f = openFileSafe(filename);

	pole2d pole;
	pole2d res;
	poleNacti(f, &pole);

	poleOtocMatici90clock(&pole, &res);
	poleTiskni(&res);
}

int main() {

	FILE* f = openFileSafe("data.txt");

	printf("Soubor otevren\n");

	pole2d pole;

	poleNacti(f, &pole);

	poleTiskni(&pole);

	polePocetSudych(&pole);

	poleSouctyObvod(&pole);

	testVertikalneSymetricke("symetricV.txt");
	testVertikalneSymetricke("symetricV4.txt");

	testOtocMatici90clock("otaceni2.txt");
	testOtocMatici90clock("otaceni3.txt");
	return 0;
}