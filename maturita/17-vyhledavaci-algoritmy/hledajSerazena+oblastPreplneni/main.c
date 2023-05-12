#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
	NE_NALEZENO = -1,
};

int hledejSerazene(FILE *file, int hledane) {
	rewind(file);
	int cislo;
	int index = 0;
	while(fscanf(file, "%d\n", &cislo) == 1 && cislo != 0) {
		if(cislo <= hledane) {
			if(cislo == hledane) {
				return index;
			}
			index++;
		} else {
			return NE_NALEZENO;
		}
	}
	return NE_NALEZENO;
}

int hledejOblastPreplneni(FILE *file, int hledane) {
	int cislo;
	int index = 0;
	while(fscanf(file, "%d\n", &cislo) == 1) {
		if(cislo == hledane) {
			return index;
		}
		index++;
	}
	return NE_NALEZENO;
}


int main() {
	FILE *file = fopen("hledana.txt", "r");
	if(file == NULL) {
		printf("Error opening\n");
		return EXIT_FAILURE;
	}
	const int hledany = 8;

	int vSerazeneIndex = hledejSerazene(file, hledany);
	printf("V serazene oblasti - index: %d\n", vSerazeneIndex);
	int vPreplneni;
	if(vSerazeneIndex == NE_NALEZENO) {
		vPreplneni = hledejOblastPreplneni(file, hledany);
		printf("Oblast preplneni - index: %d\n", vPreplneni);
	}

	if(vPreplneni == NE_NALEZENO) {
		printf("Nenealzeno nikde: %d\n", hledany);
	}


	return 0;
}