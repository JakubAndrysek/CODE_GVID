#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define N 3

void inicializujReseni(double res[], int n, double hodnota) {
	for(int i = 0; i < n; i++) {
		res[i] = hodnota;
	}
}

void vypisReseni(double res[], int n) {
	for(int i = 0; i < n; i++) {
		printf("x[%d] = %f\n", i, res[i]);
	}
	printf("\n");
}

void vypisMatici(double mat[N][N+1], int n) {
	for(int r = 0; r < n; r++) {
		for(int s = 0; s < n; s++) {
			printf("%3.2f, ", mat[r][s]);
		}
		printf("| %3.2f\n", mat[r][n]);
	}
	printf("\n");
}


// diagonalni prvek musi byt v ABS hodnote ostre vetsi nez soucet ABS hodnot ostatnich prvku na radku (mimo abs. cleny)
bool diagonalneDominantni(double mat[N][N+1], int n) {
	for(int r = 0; r < n; r++) {
		double sum = 0;
		for(int s = 0; s < N; s++) {
			if(s != r) {
				sum += mat[r][s];
			}
		}
		if(!(mat[r][r] > sum)) {
			printf("Nebude konvergovat\n");
			return false;
		}
	}
	return true;
}

// uprava matice - vydel matici diagonalnimi prvky -> ve vypoctu `vypocetSeidelJacobi` pak nemusime delit diagonalnim prvkem
void upravaMatice(double mat[N][N+1], int n) {
	for(int r = 0; r < n; r++) {
		for(int s = 0; s < n+1; s++) {
			if(r != s) {
				mat[r][s] /= mat[r][r];
			}
		}
		mat[r][r] = 0.0; // pro algoritmus 0, ale ralne tam patri 1
	}
}


double vypocetSeidelJacobi(double mat[N][N+1], int n, double res[], int radek) {
    double sum = 0;
    for(int s = 0; s < n; s++) { // scitam koeficienty *
        if(s != radek) {
            sum += mat[radek][s] * res[s];
        }
    }
    // return (mat[radek][N] - sum); // s aktivovanou optimalizaci `upravaMatice` není potřeba dělit diagonalním prvkem
	return (mat[radek][N] - sum) / mat[radek][radek]; // sumu odectu od absolutniho clenu
}

// prohozeni reseni mezi sebou
void prehodReseni(double res[], double resPred[], int n) {
	for(int r = 0; r < n; r++) {
		double pom = res[r];
		res[r] = resPred[r];
		resPred[r] = pom;
	}
}


// Jacobiho metoda - uklada si pole predchozich reseni a porovnava je s novym resenim
void zpravujJacobi(double mat[N][N+1], int n, float epsilon, double res[]) {
	double resPred[n]; // pole predchozich reseni - pro porovnani
	bool jePresny = false; // reseni nenni presne

	while(!jePresny) {
		jePresny = true; // na zacatku pocitam ze bude presny

		for(int r = 0; r < n; r++) { // jdi po radcich
			resPred[r] = vypocetSeidelJacobi(mat, n, res, r); // vypocet noveho reseni
			jePresny = (jePresny && fabs(resPred[r] - res[r]) < epsilon); // kontrola presnosti podle epsilonu
		}
		// vypisReseni(res, N);

		prehodReseni(res, resPred, n);
	}
}



// Gauss Seidel - uklada si pouze JEDEN prvek predchoziho reseni a porovnava ho s novym resenim
void zpravujGaussSeidel(double mat[N][N+1], int n, float epsilon, double res[]) {
	bool jePresny = false;  // reseni nenni presne

	while(!jePresny) {
		jePresny = true; // na zacatku pocitam ze bude presny

		for(int r = 0; r < n; r++) {
			float pred = res[r]; // ulozim si predchozi reseni - pouze jeden prvek
			res[r] = vypocetSeidelJacobi(mat, n, res, r); // vypocet noveho reseni
			jePresny = (jePresny && fabs(pred - res[r]) < epsilon); // kontrola presnosti podle epsilonu
		}
		// vypisReseni(res, N);
	}
}


int main() {

	double mat[N][N+1] = {
		{5, 2, 1, 3},
		{3, 7, 2, 2},
		{2, 1, 4, 6},
	};

	double res[N];

	vypisMatici(mat, N);
	diagonalneDominantni(mat, N); // diagonalni prvek musi byt v ABS hodnote ostre vetsi nez soucet ABS hodnot ostatnich prvku na radku (mimo abs. cleny)


	// upravaMatice(mat, N); // kazdy radek matice vydelim prvkem na diagonale - optimalizace
	// vypisMatici(mat, N);


	const float epsilon = 0.001f; // pripravim si presnost

	// Jacobiho metoda - uklada si pole predchozich reseni a porovnava je s novym resenim
	printf("\nJacobi:\n");
	inicializujReseni(res, N, 0); // nastavim vsechny prvky reseni na 0
	zpravujJacobi(mat, N, epsilon, res);
	vypisReseni(res, N);


	// Gauss Seidel - uklada si pouze JEDEN prvek predchoziho reseni a porovnava ho s novym resenim
	printf("\nGauss Saidell:\n");
	inicializujReseni(res, N, 0); // nastavim vsechny prvky reseni na 0
	zpravujGaussSeidel(mat, N, epsilon, res);
	vypisReseni(res, N);

	return 0;
}