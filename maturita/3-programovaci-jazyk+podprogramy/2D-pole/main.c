#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAXPOLESIZE  100

typedef struct {
	int data[MAXPOLESIZE][MAXPOLESIZE];
	int vyska;
	int sirka;
} TPole;

void vypisPole(FILE* f, TPole pole) {
	for(int v = 0; v < pole.vyska; v++) {
		fprintf(f, "%d", pole.data[v][0]);
		for(int s = 1; s < pole.sirka; s++) {
			fprintf(f, ", %d", pole.data[v][s]);
		}
		fprintf(f, "\n");
	}
	printf("\n");
}

void nactiPoleZeSouboru(FILE *f, TPole *pole) {
	fscanf(f, "%d %d", &pole->sirka, &pole->vyska);

	for(int v = 0; v < pole->vyska; v++) {
		for(int s = 0; s < pole->sirka; s++) {
			fscanf(f, "%d", &pole->data[v][s]);
		}
	}
}

void spocitejSudeVkazdemSloupci(TPole *pole) {
	const int vyska = pole->vyska;
	for(int s = 0; s < pole->sirka; s++) {
		int pocetSudych = 0;
		for(int v = 0; v < pole->vyska; v++) {
			if(pole->data[v][s] % 2 == 0) {
				pocetSudych++;
			}
		}
		pole->data[vyska-1][s] = pocetSudych;
	}
}

int sectiObvodovePrvky(TPole pole) {
	int soucet = 0;
	for(int v = 0; v < pole.vyska; v++) {
		soucet += pole.data[v][0];
		soucet += pole.data[pole.sirka-1][0];
	}

	for(int s = 0; s < pole.sirka; s++) {
		soucet += pole.data[0][s];
		soucet += pole.data[pole.vyska-1][s];
	}
	return soucet;
}

int soucetVKazdeCtvrtineVypis(TPole pole) {
	int ctvrtiny[4] = {0, 0, 0, 0};

	for(int v = 0; v < pole.vyska / 2; v++) {
		for(int s = 0; s < pole.sirka / 2; s++) {
			ctvrtiny[0] += pole.data[v][s];
		}
	}

	for(int v = 0; v < pole.vyska / 2; v++) {
		for(int s = pole.sirka / 2; s < pole.sirka; s++) {
			ctvrtiny[1] += pole.data[v][s];
		}
	}


	for(int v = pole.vyska / 2; v < pole.vyska; v++) {
		for(int s = 0; s < pole.sirka / 2; s++) {
			ctvrtiny[2] += pole.data[v][s];
		}
	}


	for(int v = pole.vyska / 2; v < pole.vyska; v++) {
		for(int s = pole.sirka / 2; s < pole.sirka; s++) {
			ctvrtiny[3] += pole.data[v][s];
		}
	}

	printf("SOUCET PRVKU VE CTVRTINACH: ");
	for(int ctvrtina = 0; ctvrtina < 4; ctvrtina++) {
		printf("%d, ", ctvrtiny[ctvrtina]);
	}
	printf("\n");
}

bool jeVertikalneSymetricka(TPole pole) {
	for(int v = 0; v < pole.vyska; v++) {
		for(int s = 0; s < pole.sirka/2; s++) {
			if(pole.data[v][s] != pole.data[v][pole.sirka-s-1]) {
				return false;
			}
		}
	}
	return true;
}

int main() {

	TPole pole = {
		.data ={
			{3, 5, 4, 2},
			{9, 4, 2, 1},
			{2, 1, 0, 8},
		},
		.vyska = 3,
		.sirka = 4,
	};

	// NACTI POLE
	// TPole pole;
	// nactiPoleZeSouboru(stdin, &pole);

	vypisPole(stdout, pole);

	// POCITEJ SUDE VE SLOUPCI
	// spocitejSudeVkazdemSloupci(&pole);
	// vypisPole(stdout, pole);


	// SOUCET PRVKU NA OBVODU - pouze pro pole o velokosti min 2x2
	// printf("SOUCET PRVKU NA OBVODU: %d\n", sectiObvodovePrvky(pole));

	// SOUCET PRVKU VE CTVRTINACH
	// soucetVKazdeCtvrtineVypis(pole);



	// JE VERTIKALEN SYMETRICKA
	TPole poleVerSym = {
		.data ={
			{4, 5, 4},
			{2, 4, 2},
		},
		.vyska = 2,
		.sirka = 3,
	};

	printf("JE VERTIKALEN SYMETRICKA: %d\n", jeVertikalneSymetricka(poleVerSym));
	printf("JE VERTIKALEN SYMETRICKA: %d\n", jeVertikalneSymetricka(pole));


	return 0;
}