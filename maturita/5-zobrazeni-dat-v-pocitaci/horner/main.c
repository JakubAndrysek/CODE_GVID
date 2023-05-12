#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int horner(int pole[], int pocet, int stupen) {
	int vysledek = 0;
	for(int i = 0; i < pocet; i++) {
		vysledek *= stupen;
		vysledek += pole[i];
	}
	return vysledek;
}

int main() {
	const int pocetPole = 3;
	int pole[pocetPole] = {1,2, 5};
	int stupen = 10;

	int vysledek = horner(pole, pocetPole, stupen);

	printf("%d\n", vysledek);

	return 0;
}