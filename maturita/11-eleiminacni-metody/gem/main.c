#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define N 3

void vypisMatici(double mat[N][N+1], int n) {
	for(int r = 0; r < n; r++) {
		for(int s = 0; s < n; s++) {
			printf("%3.2f, ", mat[r][s]);
		}
		printf("| %3.2f\n", mat[r][n]);
	}
	printf("\n");
}

// najdi index s nejvetsim prvkem v ABS hodnote - ve sloupci dolu
int najdiMaxIndex(double mat[N][N+1], int n, int d) {
	int max_index = d;
	for(int r = 0; r < n; r++) {
		if(fabs(mat[r][d]) > fabs(mat[max_index][d])) { // porovnani absolutnich hodnot prvku
			max_index = r;
		}
	}
	return max_index;
}

// vymena radku v matici
void vymenRadky(double mat[N][N+1], int n, int a, int b) {
	for(int s = 0; s < n+1; s++) {
		double temp = mat[a][s];
		mat[a][s] = mat[b][s];
		mat[b][s] = temp;
	}
}

// radkove upravy - vynulovani prvku pod diagonalou (vstupem je aktualni radek)
void radkoveUpravy(double mat[N][N+1], int n, int r) {
	for(int k = r+1; k < n; k++) { // jdi po radcich dolu - od aktualniho radku + 1 do posledniho radku
		double coef = mat[k][r]/mat[r][r]; // vypocet koeficientu - prvku pod diagonalou deleneho prvkem na diagonal
		mat[k][r] = 0.0; // vynulovani prvku pod diagonalou
		for(int s = r+1; s < n+1; s++) { // jdi po sloupcich doprava - od sloupce pod diagonalou +1 do posledniho sloupce (i s absolutnim clenem N+1)
			double calc = coef*mat[r][s] - mat[k][s]; // vypocet noveho prvku pomoci - koeficientu * prvek radku r - prvek na radku k (dole pod r)
			mat[k][s] = calc; // ulozeni noveho prvku
		}
	}
}

void primyChod(double mat[N][N+1], int n) {
	for(int r = 0; r < n; r++) { // jdi po radcich dolu
		int maxIndex = najdiMaxIndex(mat, n, r); // najdi index s nejvetsim prvkem v ABS hodnote - ve sloupci dolu
		if(mat[maxIndex][r] == 0) { // pokud je nejvetsi prvek 0, tak je matice singularni - nema reseni
			printf("Chyba reseni\n");
			return;
		}
		if(r != maxIndex) { // pokud je nejvetsi prvek v jinem radku nez r, tak je potreba radky vymenit
			vymenRadky(mat, n, r, maxIndex); // vymena radku
		}
		vypisMatici(mat, n);
		radkoveUpravy(mat, n, r); // radkove upravy - vynulovani prvku pod diagonalou (vstupem je aktualni radek)
	}
}

// zpetny chod - vypocet reseni (reseni je v poslednim sloupci - absolutnich clenech)
void zpetnyChod(double mat[N][N+1], int n) {
	for(int r = n-1; r >= 0; r--) { // jdi po radcich od spodu nahoru
		double sum = 0; // priprava promenne pro soucet
		for(int s = r+1; s < n; s++) { // jdi po sloupcich od aktualniho radku + 1 do posledniho sloupce (prostor nad diagonalou)
			sum += mat[r][s] * mat[s][n]; // prvek v matici nad diagonalou * odpovidajici absolutni clen
			mat[r][s] = 0; // vynulovani prvku nad diagonalou
		}

		double calc = (mat[r][N] - sum) / mat[r][r]; // vypocet reseni - (absolutni clen - soucet) / prvek na diagonale
		mat[r][N] = calc; // ulozeni reseni do absolutniho clenu
		mat[r][r] = 1; // vynulovani prvku na diagonale
		vypisMatici(mat, n);
	}
}

int main() {


	double mat[N][N+1] = {
		{-2, -1,  9, 23},
		{ 8, -1, -2,  0},
		{-1,  7, -1, 10},
	};

	vypisMatici(mat, N);

	primyChod(mat, N); // prevede na rozsirenou matici soustavy -> horni hroj. matice (nuly pod diagonalou)
	vypisMatici(mat, N);

	zpetnyChod(mat, N); // dopocitni reseni
	vypisMatici(mat, N);

	return 0;
}