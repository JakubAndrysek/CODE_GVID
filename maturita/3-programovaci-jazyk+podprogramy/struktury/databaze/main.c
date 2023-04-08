#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char name[21]; // 20 characters
	int height;
	bool active;
} Sopka;


void sopkaTiskni(Sopka sopka) {
	printf("Nazev: %s\n", sopka.name);
	printf("Vyska: %d\n", sopka.height);
	printf("Aktivni: %d\n", sopka.active);
}

void sopkyTiskni(Sopka sopky[], int pocet) {
	for(int i = 0; i < pocet; i++) {
		sopkaTiskni(sopky[i]);
	}
}

int nactiSopky(FILE* f, Sopka *sopky) {
	bool mamCoCist = true;
	int pocitadlo = 0;
	Sopka sopp[5];

	while(mamCoCist) {
		// load: "Vyska: 1281"
		// fscanf(f, "%d", & sopky[pocitadlo].height);

		if(fscanf(f, "Nazev: %20s\n", sopky[pocitadlo].name) != 1) {
			printf("Problem nazev\n");
			return pocitadlo;
		}

		if(fscanf(f, "Vyska: %d ", &sopky[pocitadlo].height) != 1) {
			printf("Problem vyska");
			return pocitadlo;
		}

		if(fscanf(f, "Aktivni: %d\n", &sopky[pocitadlo].active) != 1) {
			printf("Problem aktivni");
			return pocitadlo;
		}

		// sopkaTiskni(sopky[pocitadlo]);

		pocitadlo++;
	}
	printf("Ucelene nacteni");
}



int main(int argc, char *argv[]){  // pro parametry prikazoveho radku
	// if(argc < 2 ) {
	// 	printf("Malo parametru: nazev souboru");
	// }

	// FILE *f = fopen(argv[1], "r");
	FILE *f = fopen("sopky.txt", "r");

	if(f == NULL) {
		printf("Error opening file\n");
		return EXIT_FAILURE;
	}

	Sopka sopky[100];
	nactiSopky(f, sopky);

	fclose(f);




	return 0;
}